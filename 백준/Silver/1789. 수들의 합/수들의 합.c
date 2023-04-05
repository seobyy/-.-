#include <stdio.h>

int main() {
    long long int S, sum = 0;
    int ans = 0;
    scanf("%lld", &S);
    for (int i = 1; i < S + 100; ++i) {
        sum += i;
        if (sum > S) {
            ans = i - 1; break;
        }
    }
    printf("%d", ans);
}