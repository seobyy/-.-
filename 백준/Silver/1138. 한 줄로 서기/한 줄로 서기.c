#include <stdio.h>

int main() {
    int N, a, P[11] = {0};
    scanf("%d", &N);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &a);
        if (a == N - i) {
            for (int j = N - 1; j >= 0; --j) {
                if (P[j] == 0) {
                    P[j] = i;
                    break;
                }
            }
        }
        else {
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (cnt == a) {
                    if (P[j] == 0) {
                        P[j] = i;
                        break;
                    }
                }
                if (P[j] == 0) 
                    cnt++;
            }
        }
    }
    for (int i = 0; i < N; ++i)
        printf("%d ", P[i]);
}