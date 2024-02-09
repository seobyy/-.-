#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
#define MAX_M 1000
#define INF 1e9 + 9
using namespace std;

int N, M;
int ans = INF;
int Map[MAX_N + 5][MAX_M + 5];
int dp[MAX_N + 5][MAX_M + 5][3];

void init() {
    for (int i = 0; i < N; ++i) 
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < 3; ++k)
                dp[i][j][k] = INF;
}

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> Map[i][j];
        }
    }
}

void solve() {
    
    for (int j = 0; j < M; ++j) {
        for (int k = 0; k < 3; ++k)
            dp[0][j][k] = Map[0][j];
    }
    
    
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j + 1 < M)
                dp[i][j][0] = min(dp[i - 1][j + 1][1], dp[i - 1][j + 1][2]) + Map[i][j];
    
            dp[i][j][1] = min(dp[i - 1][j][0], dp[i - 1][j][2]) + Map[i][j];
                
            if (j - 1 >= 0)
                dp[i][j][2] = min(dp[i - 1][j - 1][0], dp[i - 1][j - 1][1]) + Map[i][j];
        }
    }
    
    for (int j = 0; j < M; ++j) {
        for (int k = 0; k < 3; ++k)
            ans = min(ans, dp[N - 1][j][k]);
    }
}

void output() {
    cout << ans << '\n';
}

int main() {
    
    fastio;
    input();
    init();
    solve();
    output();
    
    return 0;
}