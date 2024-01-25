#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 105
#define MAX_K 100005
using namespace std;

int dp[MAX_N][MAX_K];
int V[MAX_N];
int C[MAX_N];

int main() {
    
    fastio;
    int N, K;
    cin >> N >> K;
        
    for (int i = 1; i <= N; ++i) {
        cin >> V[i] >> C[i];
    }
        
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
                
            if (V[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - V[i]] + C[i]);
                
        }
    }
        
    cout << dp[N][K] << '\n';

    
    return 0;
}