#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1'000'000
//#define ll long long
using namespace std;

const int MOD = 1'000'000'009;
int dp[MAX_N + 5];

int main() {
    
    fastio;
    int T;
    cin >> T;
    
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for (int i = 4; i <= MAX_N; ++i) {
        dp[i] = dp[i - 3] + dp[i - 2];
        dp[i] %= MOD;
        dp[i] += dp[i - 1];
        dp[i] %= MOD;
    }
    
    for (int tc = 1; tc <= T; ++tc) {
        int n;
        cin >> n;
        
        cout << dp[n] % MOD << '\n';
    }
    
    return 0;
}