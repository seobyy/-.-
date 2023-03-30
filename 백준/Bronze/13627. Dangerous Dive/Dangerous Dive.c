#include <stdio.h>

int main() {
    int N, R, V[10005], p;
    scanf("%d %d", &N, &R);
    for (int i = 1; i <= N; ++i) {
        V[i] = 1;
    }
    for (int i = 0; i < R; ++i) {
        scanf("%d", &p);
        V[p]--;
    }
    if (N == R) 
        printf("*");
    else {
        for (int i = 1; i <= N; ++i) {
            if (V[i] == 1) 
                printf("%d ", i);
        }
    }
}