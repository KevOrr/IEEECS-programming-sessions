#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

const uint_fast64_t mod = 1000000007; // 1e9 + 7

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

uint_fast64_t recurrence_n(uint_fast64_t a, uint_fast64_t b, uint_fast64_t n) {
    // this is redundant since you have to check in calculate_matrix() anyway, but whatever
    if (n == 0)
        return a;
    if (n == 1)
        return b;

    uint_fast64_t matrix[2][2] = {{1, 1}, {1, 0}};
    calculate_matrix(matrix, n-1);
    return matrix[0][0]*b + matrix[0][1]*a;
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
