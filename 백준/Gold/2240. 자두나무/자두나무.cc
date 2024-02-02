#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_T 1000
#define MAX_W 30
using namespace std;

int T, W;
int ans;
int treeNum[MAX_T + 5];
int dp[3][MAX_W + 5][MAX_T + 5];

void input() {
    cin >> T >> W;
    for (int i = 1; i <= T; ++i) {
        cin >> treeNum[i];
    }
}

void solve() {
    
    if (treeNum[1] == 1) 
        dp[1][0][1] = 1;
    
    else if (treeNum[1] == 2) 
        dp[2][1][1] = 1;
    
    
    for (int i = 2; i <= T; ++i) {
        if (treeNum[i] == 1) {
            for (int j = 0; j <= W; ++j) {
                if (j != 0) 
                    dp[1][j][i] = max(dp[1][j][i - 1], dp[2][j - 1][i - 1]) + 1;
                else
                    dp[1][j][i] = dp[1][j][i - 1] + 1;
                dp[2][j][i] = dp[2][j][i - 1];
            }
        }
        else if (treeNum[i] == 2) {
            for (int j = 0; j <= W; ++j) {
                if (j != 0) 
                    dp[2][j][i] = max(dp[2][j][i - 1], dp[1][j - 1][i - 1]) + 1;
                else
                    dp[2][j][i] = dp[2][j][i - 1] + 1;
                dp[1][j][i] = dp[1][j][i - 1];
            }
        }
    }
    
    /*
    for (int t = 1; t <= T; ++t) {
        for (int i = 1; i <= 2; ++i) {
            for (int j = 0; j <= W; ++j) {
                cout << dp[i][j][t] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    */
    
    for (int i = 1; i <= 2; ++i) {
        for (int j = 0; j <= W; ++j) 
            ans = max(ans, dp[i][j][T]);
    }
    
}

void output() {
    cout << ans << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}