#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 300
using namespace std;

int stair[MAX_N + 5];
int dp[MAX_N + 5][2];

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        cin >> stair[i];
    }
    
    dp[1][0] = stair[1]; dp[1][1] = stair[1];
    
    for (int i = 2; i <= N; ++i) {
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + stair[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - i][1]) + stair[i];
    }
    
    
    int ans = (dp[N][0] > dp[N][1]) ? dp[N][0] : dp[N][1];
    cout << ans << '\n';
    
    return 0;
}