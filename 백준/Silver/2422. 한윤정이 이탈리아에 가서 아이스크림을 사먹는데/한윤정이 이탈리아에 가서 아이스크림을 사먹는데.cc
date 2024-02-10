#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, M;
int ans;
int no[205][205];

void input() {
    cin >> N >> M;
    for (int i = 0 ; i < M; ++i) {
        int a, b; cin >> a >> b;
        no[a][b] = true;
        no[b][a] = true;
    }
}

void solve() {
    for (int i = 1; i <= N - 2; ++i) {
        for (int j = i + 1; j <= N - 1; ++j) {
            for (int k = j + 1; k <= N; ++k) {
                if (no[i][j] || no[j][k] || no[k][i])
                    continue;
                ans++;
            }
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