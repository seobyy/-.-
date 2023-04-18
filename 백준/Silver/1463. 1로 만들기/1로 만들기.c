#include <stdio.h>
#define min(a, b) a < b ? a : b

int dp[1000005];
int main() {
    int N;
    scanf("%d", &N);
    //bottom-up
    dp[1] = 0;  dp[2] = 1;  dp[3] = 1;
    int i = 4;
    while (i <= N) {
        dp[i] = dp[i - 1] + 1;
        if (i % 3 == 0)
            dp[i] = min(dp[i / 3] + 1, dp[i]);
        if (i % 2 == 0)
            dp[i] = min(dp[i / 2] + 1, dp[i]);
        i++;
    }
    printf("%d\n", dp[N]);
}