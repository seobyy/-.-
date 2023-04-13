#include <stdio.h>

int M, N;
int search(int a, int b, int arr[][55]) {
    arr[a][b] = 0;
    if (arr[a][b + 1] == 1) 
        search(a, b + 1, arr);
    if (arr[a][b - 1] == 1) 
        search(a, b - 1, arr);
    if (arr[a + 1][b] == 1) 
        search(a + 1, b, arr);
    if (arr[a - 1][b] == 1) 
        search(a - 1, b, arr);
}

int main() {
    int T, K, X, Y;
    scanf("%d", &T);
    for (int i = 0; i < T; ++i) {
        int map[55][55] = {0};
        scanf("%d %d %d", &M, &N, &K);
        for (int i = 0; i < K; ++i) {
            scanf("%d %d", &X, &Y);
            map[Y][X] = 1;
        }
        int cnt = 0;
        for (int j = 0; j < N; ++j) {
            for (int i = 0; i < M; ++i) {
                if (map[j][i] == 1) {
                    cnt++;
                    search(j, i, map);
                }
            }
        }
        printf("%d\n", cnt);
    }
}