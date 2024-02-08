#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100
#define INF 1e9
using namespace std;

int n, m;
int dist[MAX_N + 5][MAX_N + 5];

void init() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i != j)
                dist[i][j] = INF;
        }
    }
}

void input() {
    cin >> n >> m;
    init();
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b], c);
    }
}

void solve() {
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void output() {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF)
                dist[i][j] = 0;
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}