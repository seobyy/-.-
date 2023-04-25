#include <stdio.h>

int main() {
    int T, A, ans = 0;
    scanf("%d", &T);
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &A);
        if (A == T)
            ans ++;
    }
    printf("%d\n", ans);
}