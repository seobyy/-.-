#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 15
using namespace std;

int T[MAX_N + 5];
int P[MAX_N + 5];
int dp[MAX_N + 5];

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }
    
    for (int i = 1; i <= N; ++i) {
        if (i + T[i] <= N + 1) {
            if (dp[i] + P[i] > dp[i + T[i]])
                dp[i + T[i]] = dp[i] + P[i];
        } 
        if (dp[i + 1] < dp[i])
            dp[i + 1] = dp[i];
    }
    
    cout << dp[N + 1] << '\n';
    
    return 0;
}