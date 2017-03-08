#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

const int MAX_N = 5001;
const int MOD = 1000000009; // 1e9 + 9

// just for convenience
int last_calculated = 1;

uint64_t catalan_n(int n, uint64_t catalans[]) {
    if (last_calculated < n) {
        for (int i=last_calculated + 1; i<=n; i++)
            for (int j=0; j<i; j++)
                catalans[i] += catalans[j] * catalans[i-j-1];
        last_calculated = n;
    }

    return catalans[n];
}

int main() {
    uint64_t catalans[MAX_N];
    memset(catalans, 0, sizeof(catalans));
    catalans[0] = catalans[1] = 1;

    int test_cases;
    for (scanf("%d", &test_cases); test_cases > 0; test_cases--) {
        int n;
        scanf("%d", &n);
        printf("%"PRIu64"\n", catalan_n(n, catalans));
    }
}
