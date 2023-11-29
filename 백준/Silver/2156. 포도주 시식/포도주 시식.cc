#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 10'000
using namespace std;

int wine[MAX_N + 5];
int dp[MAX_N + 5][3];

int main() {
    
    fastio;
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> wine[i];
    }
    
    dp[1][1] = wine[1];
    dp[2][0] = wine[1]; dp[2][1] = wine[2]; dp[2][2] = wine[1] + wine[2];
    for (int i = 3; i <= n; ++i) {
        dp[i][0] = max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
        dp[i][1] = dp[i - 1][0] + wine[i];
        dp[i][2] = dp[i - 1][1] + wine[i];
    }
    
    int ans = max({dp[n][0], dp[n][1], dp[n][2]});
    
    cout << ans << '\n';
    
    return 0;
}