#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#define p(x) printf("%"PRIu64"\n", x)

#define MAX_N 5001
const int MOD = 1000000009; // 1e9 + 9

uint64_t catalan_n(int n) {
    static uint64_t catalans[MAX_N] = {1, 1};
    static int last_calculated = 1;

    if (last_calculated < n) {
        for (int i=last_calculated + 1; i<=n; i++)
            for (int j=0; j<i; j++)
                catalans[i] += catalans[j] * catalans[i-j-1] % MOD;
        last_calculated = n;
    }

    return catalans[n];
}

uint64_t choose(int n, int k) {
    static uint64_t chooses[(MAX_N + 1)*(MAX_N + 2) << 1] = {1, 1, 1};
    static int last_n_calculated = 1;

    if (last_n_calculated < n) {
        for (int row_num=last_n_calculated + 1; row_num<=n; row_num++) {
            int array_row = (row_num + 1)*row_num >> 1;
            int array_row_above = row_num * (row_num - 1) >> 1;

            // First and last element in each row is 1
            chooses[array_row] = chooses[array_row + row_num] = 1;

            // All the elements in the middle are the sum of their adjacent parents
            for (int col_num=1; col_num < row_num; col_num++)
                chooses[array_row + col_num] = chooses[array_row_above + (col_num - 1)] + chooses[array_row_above + col_num] % MOD;
        }

        last_n_calculated = n;
    }

    int row = (n+1)*n >> 1;
    return chooses[row + k];
}

uint64_t num_trees(int size) {
    static uint64_t tree_sizes[MAX_N] = {1}; // tree_sizes[n] = number of ways to arrange BST with n+1 nodes
    static int last_calculated = 1;

    if (last_calculated < size) {
        for (int i=last_calculated+1; i<=size; i++)
            for (int j=1; j<=i; j++)
                tree_sizes[i-1] += choose(i, j) * catalan_n(j) % MOD;
    }

    return tree_sizes[size-1];
}

int main() {
    uint64_t catalans[MAX_N];
    memset(catalans, 0, sizeof(catalans));
    catalans[0] = catalans[1] = 1;

    int test_cases;
    for (scanf("%d", &test_cases); test_cases > 0; test_cases--) {
        int n;
        scanf("%d", &n);
        printf("%"PRIu64"\n", num_trees(n));
    }
}
