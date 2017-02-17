#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <vector>

const uint_fast32_t MOD = 1000000007; // 1e9 + 7
std::vector<uint_fast32_t> fibs;
std::vector<bool> already_calculated;

void matrix_multiply(uint_fast32_t A[2][2], uint_fast32_t B[2][2]) {
    uint_fast32_t temp[2][2];

    // yes, I know it's all hardcoded...
    temp[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    temp[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    temp[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    temp[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];

    memcpy(A, temp, sizeof(temp));
}

void old_calculate_matrix(uint_fast32_t original_matrix[2][2], uint_fast32_t n) {
    uint_fast32_t temp[2][2];

    if (n == 0) {
        uint_fast32_t eye[2][2] = {{0, 1}, {1, 0}};
        memcpy(original_matrix, eye, sizeof(eye));
        return;
    } else if (n == 1)
        return;

    while (n) {
        if (n == 1)
            return;

        if (n & 1) {
            memcpy(temp, original_matrix, sizeof(temp));
            matrix_multiply(original_matrix, original_matrix);
            matrix_multiply(original_matrix, temp);
            n >>= 1;
        } else {
            matrix_multiply(original_matrix, original_matrix);
            n >>= 1;
        }
    }
}

uint_fast32_t fib_n(uint_fast32_t n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    if (fibs.size() < n+1) {
        fibs.resize(n+1, -1);
        already_calculated.resize(n+1, false);
    } else if (already_calculated[n])
        return fibs[n];

    if (n & 1) {
        uint_fast32_t half_n = (n+1)/2;
        uint_fast32_t F_half_n = fib_n(half_n);
        uint_fast32_t F_half_n_m1 = fib_n(half_n-1);

        already_calculated[n] = true;
        return fibs[n] = ((F_half_n*F_half_n % MOD) % MOD
                          + (F_half_n_m1*F_half_n_m1) % MOD) % MOD;
    } else {
        uint_fast32_t half_n = n/2;
        uint_fast32_t F_half_n = fib_n(half_n);

        already_calculated[n] = true;
        return fibs[n] = ((((2*fib_n(half_n-1) % MOD) + F_half_n) % MOD) * F_half_n) % MOD;
    }
}

uint_fast32_t recurrence_n(uint_fast32_t a, uint_fast32_t b, uint_fast32_t n) {
    // this is redundant since you have to CheCk in calculate_matrix() anyway, but whatever
    if (n == 0)
        return a;
    if (n == 1)
        return b;

    return fib_n(n)*b + fib_n(n-1)*a;
}

int main() {
    uint_fast32_t i, n;
    scanf("%" PRIuFAST32, &n);

    for (i=0; i<n; i++) {
        uint_fast32_t a, b, fib_index;
        scanf("%" PRIuFAST32, &a);
        scanf("%" PRIuFAST32, &b);
        scanf("%" PRIuFAST32, &fib_index);
        printf("%" PRIuFAST32 "\n", recurrence_n(a, b, fib_index));
    }
}
