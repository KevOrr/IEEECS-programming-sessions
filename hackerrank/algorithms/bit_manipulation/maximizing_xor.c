#include <stdio.h>

int main() {
    int L, R;
    scanf("%d", &L);
    scanf("%d", &R);

    int max = -1;
    for (int a=L; a<=R; a++) {
        for (int b=a; b<=R; b++) {
            int temp = a ^ b;
            if (temp > max)
                max = temp;
        }
    }

    printf("%d\n", max);
}
