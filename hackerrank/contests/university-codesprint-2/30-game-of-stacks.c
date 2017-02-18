#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint64_t arraysum(uint32_t *array, uint32_t n) {
    uint64_t result = 0;
    for (uint32_t i=0; i<n; i++) {
        result += array[i];
    }
    return result;
}

int main() {
    int g;
    if (scanf("%d", &g) != 1) return 1; // number of games

    for(; g>0; --g) {
        // get game constants
        uint32_t n, m, x;
        if (scanf("%"PRIu32" %"PRIu32" %"PRIu32, &n, &m, &x) != 3) return 1;

        // get game stacks
        uint32_t A[n], B[m];
        for (uint32_t *a=A, *end=A+n; a!=end; a++)
            if (scanf("%"PRIu32, a) != 1) return 1;
        for (uint32_t *b=B, *end=B+m; b!=end; b++)
            if (scanf("%"PRIu32, b) != 1) return 1;

        // find max score. Greedy with A, and then figure out how many we can
        // take from B. If the sum exceeds x, replace some A until it doesn't
        uint32_t max_score = 0;
        uint64_t current_sum = arraysum(A, n);
        uint32_t j=0;
        for (uint32_t i=n; ; current_sum -= A[--i]) {
            for (; j<=m; current_sum += B[j++]) {
                if (current_sum > x)
                    break;

                if (i + j > max_score)
                    max_score = i + j;
            }

            if (!i)
                break;
        }

        printf("%"PRIu32"\n", max_score);
    }
}
