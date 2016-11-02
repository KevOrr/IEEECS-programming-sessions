#include <stdio.h>

int main() {
    unsigned long long m, n;

    scanf("%llu %llu", &m, &n);
    printf("%llu\n", m*n - 1);

    return 0;
}
