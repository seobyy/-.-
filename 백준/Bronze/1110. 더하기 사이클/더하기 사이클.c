#include <stdio.h>

int main() {
    int N, cnt = 0;
    scanf("%d", &N);
    if (N < 10)
        N *= 10;
    int x = N;
    while (1) {
        int a = (x / 10) + (x % 10);
        x = (x % 10) * 10 + (a % 10);
        cnt++;
        if (x == N)
            break;
    }
    printf("%d\n", cnt);
}