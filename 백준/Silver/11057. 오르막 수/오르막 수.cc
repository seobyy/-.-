#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
using namespace std;

const int mod = 10'007;
int dp[MAX_N + 5][10];

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    for (int i = 0; i <= 9; ++i) {
        dp[1][i] = 1;
    }
    
    for (int i = 2; i <= N; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = j; k >= 0; --k) {
                dp[i][j] += dp[i - 1][k];
                dp[i][j] %= mod;
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i <= 9; ++i) {
        ans += dp[N][i];
        ans %= mod;
    }
    
    cout << ans << '\n';
    
    return 0;
}