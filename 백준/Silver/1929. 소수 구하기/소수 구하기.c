#include <stdio.h>
#include <math.h>

int main() {
    int M, N;
    scanf("%d %d", &M, &N);
    for (int i = M; i <= N; ++i) {
        if (i == 1)
            continue;
        int find = 0, pivot = sqrt(i);
        for (int j = 2; j <= pivot; ++j) {
            if (i % j == 0) {
                find = 1;
                break;
            }
        }
        if (!find)
            printf("%d\n", i);
    }
    return 0;
}