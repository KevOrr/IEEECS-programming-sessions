/*
Calculates the recurrence relation u(n), where
u(0) = a
u(1) = b
u(n) = u(n-1) + u(n-2), n > 1

This can be expressed with the following linear equations:
u(n)   = 1*u(n-1) + 1*u(n-2)
u(n-1) = 1*u(n-1) + 0*u(n-2)

And thus with the following linear transformation:
[ u(n) ] = [1, 1] * [u(n-1)]
[u(n-1)]   [1, 0]   [u(n-2)]

The vector on the left is the "next" state, while the vector on the right is the
"previous" state. When n=2, the vector on the right is the initial state [b; a]

Since this is a linear transformation, we can exponentiate the transformation
matrix T = [1 1; 1 0] to calculate n states ahead. This can be done in
essentially O(log n) time, with the [exponentiation by squaring method]
(https://en.wikipedia.org/wiki/Exponentiation_by_squaring).

This challenge also asks us to output the final result (mod 1e9 + 7). This is necessary
in fact, since we are dealing with n <= 10^9, and even fib(n=94) would overflow
a uint64_t. That means that we must be taking the modulo of ALL our intermediate
results. All uses of the modulo operator here are algebraicly equivalent to simply
finding the modulo of the final result, except that it gaurantees that no intermediate
result overflows its data type.

One final note is that I use uint64_t. On systems that don't support 64 bit words,
any use of multiplication must be rewritten, since any intermediate result (mod 1e9 + 7)
can have up to 30 (ceil(log_2(1e9+7)) == 30) significant bits, and thus the product of
two results can have up to 60 significant bits. Karatsuba's algorithm might help here.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#define fmt64 "%" PRIu64

const uint64_t MOD = 1000000007; // 1e9 + 7
const uint64_t EYE[2][2] = {{0, 1}, {1, 0}}; // Identity matrix
const uint64_t T[2][2] = {{1, 1}, {1, 0}}; // Our tranformation matrix

void mat_mul(uint64_t A[2][2], uint64_t B[2][2]) {
    uint64_t temp[2][2];

    // yes, I know it's all hardcoded, but we're only expecting 2x2 matrices
    temp[0][0] = ((A[0][0]*B[0][0]) % MOD + (A[0][1]*B[1][0]) % MOD) % MOD;
    temp[0][1] = ((A[0][0]*B[0][1]) % MOD + (A[0][1]*B[1][1]) % MOD) % MOD;
    temp[1][0] = ((A[1][0]*B[0][0]) % MOD + (A[1][1]*B[1][0]) % MOD) % MOD;
    temp[1][1] = ((A[1][0]*B[0][1]) % MOD + (A[1][1]*B[1][1]) % MOD) % MOD;

    memcpy(A, temp, sizeof(temp));
}

void mat_exp(uint64_t A[2][2], uint64_t n) {
    uint64_t temp[2][2];

    if (n == 0) {
        memcpy(A, EYE, sizeof(EYE));
        return;
    } else if (n == 1)
        return;

    if (n & 1) {
        memcpy(temp, A, sizeof(temp));
        mat_mul(A, A);
        mat_exp(A, n/2);
        mat_mul(A, temp);
    } else {
        mat_mul(A, A);
        mat_exp(A, n/2);
    }
}

uint64_t recurrence_n(uint64_t a, uint64_t b, uint64_t n) {
    // this is redundant since you have to check in mat_exp() anyway, but especially
    // if n is 0, we shouldn't call mat_exp(mat, n-1), if for no ther reason then
    // n is unsigned
    if (n == 0)
        return a;
    if (n == 1)
        return b;

    uint64_t mat[2][2];
    memcpy(mat, T, sizeof(mat));
    mat_exp(mat, n-1);

    return ((mat[0][0]*b) % MOD + (mat[0][1]*a) % MOD) % MOD;
}

int main() {
    int i, n;
    if(scanf("%d", &n) != 1) return 1;

    for (i=0; i<n; i++) {
        uint64_t a, b, fib_index;
        if (scanf(fmt64" "fmt64" "fmt64, &a, &b, &fib_index) != 3) return 1;
        printf(fmt64"\n", recurrence_n(a, b, fib_index));
    }
}
