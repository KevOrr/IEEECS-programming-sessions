#include <stdio.h>

int main() {

    int n;
    scanf("%d", &n);
    int n_bijections = n;

    while (--n)
        n_bijections *= n;

    printf("%d\n", n_bijections);

    return 0;
}
