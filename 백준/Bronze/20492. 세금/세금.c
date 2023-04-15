#include <stdio.h>

int main() {
    int N, a, b;
    scanf("%d", &N);
    a = N * 0.78;
    b = N - (N * 0.2 * 0.22);
    printf("%d %d", a, b);
}