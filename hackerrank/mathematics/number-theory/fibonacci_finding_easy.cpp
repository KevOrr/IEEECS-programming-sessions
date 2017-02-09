#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <vector>

const uint_fast64_t mod = 1000000007; // 1e9 + 7
std::vector<uint_fast64_t> fibs;
std::vector<bool> already_calculated;

void matrix_multiply(uint_fast64_t A[2][2], uint_fast64_t B[2][2]) {
    uint_fast64_t temp[2][2];

    // yes, I know it's all hardcoded...
    temp[0][0] = A[0][0]*B[0][0] + A[0][1]*B[1][0];
    temp[0][1] = A[0][0]*B[0][1] + A[0][1]*B[1][1];
    temp[1][0] = A[1][0]*B[0][0] + A[1][1]*B[1][0];
    temp[1][1] = A[1][0]*B[0][1] + A[1][1]*B[1][1];

    memcpy(A, temp, sizeof(temp));
}

void old_calculate_matrix(uint_fast64_t original_matrix[2][2], uint_fast64_t n) {
    uint_fast64_t temp[2][2];

    if (n == 0) {
        uint_fast64_t eye[2][2] = {{0, 1}, {1, 0}};
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

uint_fast64_t fib_n(uint_fast64_t n) {
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
        uint_fast64_t half_n = (n+1)/2;
        uint_fast64_t F_half_n = fib_n(half_n);
        uint_fast64_t F_half_n_m1 = fib_n(half_n-1);

        already_calculated[n] = true;
        return fibs[n] = F_half_n*F_half_n + F_half_n_m1*F_half_n_m1;
    } else {
        uint_fast64_t half_n = n/2;
        uint_fast64_t F_half_n = fib_n(half_n);

        already_calculated[n] = true;
        return fibs[n] = (2*fib_n(half_n-1) + F_half_n)*F_half_n;
    }
}

uint_fast64_t recurrence_n(uint_fast64_t a, uint_fast64_t b, uint_fast64_t n) {
    // this is redundant since you have to check in calculate_matrix() anyway, but whatever
    if (n == 0)
        return a;
    if (n == 1)
        return b;

    return fib_n(n)*b + fib_n(n-1)*a;
}

int main() {
    uint_fast64_t i, n;
    scanf("%" PRIuFAST64, &n);

    for (i=0; i<n; i++) {
        uint_fast64_t a, b, fib_index;
        scanf("%" PRIuFAST64, &a);
        scanf("%" PRIuFAST64, &b);
        scanf("%" PRIuFAST64, &fib_index);
        printf("%" PRIuFAST64 "\n", recurrence_n(a, b, fib_index) % mod);
    }
}
