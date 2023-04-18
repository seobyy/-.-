#include <stdio.h>
//top-down
int solution(int n) {
    if (n < 2)
        return 0;
    int a = solution(n / 3) + (n % 3) + 1;
    int b = solution(n / 2) + (n % 2) + 1;
    return a < b ? a : b;
}

int main() {
    int N;
    scanf("%d", &N);
    printf("%d\n", solution(N));
}