#include <stdio.h>

int main() {
    int N, M, i, j, basket[101] = {0}, inverted_B[101] = {0};
    scanf("%d %d", &N, &M);
    for (int x = 1; x <= N; ++x) {
        basket[x] = x;
    }
    for (int x = 0; x < M; ++x) {
        scanf("%d %d", &i, &j);
        for (int y = 0; y < j - i + 1; ++y) {
            inverted_B[y] = basket[j - y];
        }
        for (int y = i; y <= j; ++y) {
            basket[y] = inverted_B[y - i];
        }
    }
    for (int x = 1; x <= N; ++x) {
        printf("%d ", basket[x]);
    }
    return 0;
}