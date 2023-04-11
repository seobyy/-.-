#include <stdio.h>

int num[1505][1505];
int main() {
    int N, max, cnt = 0, A[1505] = {0}, a = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) 
            scanf("%d", &num[i][j]);
    }
    while (cnt != N) {
        max = -1000000000;
        for (int j = 0; j < N; ++j) {
            int i = N - 1 - A[j];
            if (i < 0)
                continue;
            if (num[i][j] > max) {
                max = num[i][j];
                a = j;
            }
        }
        A[a]++;
        cnt++;
    }
    printf("%d\n", max);
}
