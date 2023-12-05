#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
using namespace std;

const int mod = 10'007;
int dp[MAX_N + 5][MAX_N + 5];

int calCoef(int n, int k) {
    
    if (k > n)
        return 0;
        
    if (dp[n][k])
        return dp[n][k] % mod;
        
    if (!k || k == n)
        return dp[n][k] = 1;
    
    return dp[n][k] = (calCoef(n - 1, k - 1) + calCoef(n - 1, k)) % mod;
}

int main() {
    
    fastio;
    int N, K;
    cin >> N >> K;
    
    cout << calCoef(N, K) << '\n';
    
    return 0;
}