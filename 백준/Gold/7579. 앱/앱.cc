#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100
#define MAX_C 10000
#define INF 1e9 + 9
#define ll long long
using namespace std;

int N, M;
int sumCost;
int ans = INF;
int m[MAX_N + 5];
int c[MAX_N + 5];
int dp[MAX_N + 5][MAX_C + 5];

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        cin >> m[i];
    }
    for (int i = 1; i <= N; ++i) {
        cin >> c[i];
        sumCost += c[i];
    }
}

void solve() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= sumCost; ++j) {
            if (c[i] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
            if (dp[i][j] >= M)
                ans = min(ans, j);
        }
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