#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1'000'000
using namespace std;

const int MOD = 15746;

int dp[MAX_N + 5];

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    dp[1] = 1;
    dp[2] = 2;
    
    for (int i = 3; i <= N; ++i) {
        dp[i] = dp[i - 2] + dp[i - 1];
        dp[i] %= MOD;
    }
    
    cout << dp[N] << '\n';
    
    return 0;
}