#include <stdio.h>

int main() {
    int T, n;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        scanf("%d", &n);
        printf("Pairs for %d: ", n);
        for (int j = 1; j <= n / 2; ++j) {
            if (n - 2 * j == 1 || n - 2 * j == 2)
                printf("%d %d", j, n - j);
            else {
                if (j != n - j)
                    printf("%d %d, ", j, n - j);
            }
        }
        printf("\n");
    }
}