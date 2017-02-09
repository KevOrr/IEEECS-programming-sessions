#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

const uint_fast32_t mod = 1000000007; // 1e9 + 7

int main() {
    uint_fast32_t i, n;
    scanf("%" PRIuFAST32, &n);

    for (i=0; i<n; i++) {
        uint_fast32_t a, b, b_temp, fib_index;
        scanf("%" PRIuFAST32, &a);
        scanf("%" PRIuFAST32, &b);
        scanf("%" PRIuFAST32, &fib_index);
        while (fib_index--) {
            b_temp = b;
            b = (a+b) % mod;
            a = b_temp;
        }
        printf("%" PRIuFAST32 "\n", a);
    }

}
