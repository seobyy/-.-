#include <stdio.h>

int main() {
    int N, T[100], D[100];
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        scanf("%d %d", &T[i], &D[i]);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N - 1 - i; ++j) {
            if (T[j + 1] < T[j]) {
                int tmp = T[j];
                T[j] = T[j + 1];
                T[j + 1] = tmp;
                tmp = D[j];
                D[j] =D[j + 1];
                D[j + 1] = tmp;
            }
        }
    }
    int last = 0;
    for (int i = 0; i < N; ++i) {
        if (T[i] < last) {
            last += D[i];
        }
        else {
            last = T[i];
            last += D[i];
        }
    }
    printf("%d\n", last);
}