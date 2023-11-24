#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 90
using namespace std;

typedef long long int ll;

ll dp[MAX_N + 5][2];

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    dp[1][1] = 1; dp[1][0] = 0;
    dp[2][0] = 1; dp[2][1] = 0;
    
    for (int i = 3; i <= N; ++i) {
        dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
    }
    
    cout << dp[N][0] + dp[N][1] << '\n';
    
    return 0;
}