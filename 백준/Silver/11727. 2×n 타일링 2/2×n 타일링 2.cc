#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
using namespace std;

const int MOD = 10'007;

int dp[MAX_N + 5];

int main() {
    
    fastio;
    int n;
    cin >> n;
    
    dp[1] = 1;
    dp[2] = 3;
    
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 2] * 2 + dp[i - 1];
        dp[i] %= MOD;
    }
    
    cout << dp[n] % MOD << '\n';
    
    return 0;
}