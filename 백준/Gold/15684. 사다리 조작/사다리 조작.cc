#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 10
#define MAX_H 30
using namespace std;

int N, M, H;
int ans = -1;
int add;
bool is_find;
int adj[MAX_N + 5][MAX_H + 5];

void input() {
    cin >> N >> M >> H;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        adj[b][a] = b + 1;
        adj[b + 1][a] = b;
    }
}

bool play_ladder() {
    for (int i = 1; i <= N; ++i) {
        int cur = i;
        for (int j = 1; j <= H; ++j) {
            if (adj[cur][j]) 
                cur = adj[cur][j];
        }
        if (cur != i)
            return false;
    }
    
    return true;
}


void add_line(int col, int cnt) {
    
    if (is_find)
        return;
    
    if (cnt == add) {
        if (play_ladder()) { 
            ans = cnt;
            is_find = true;
        }
        return;
    }
    
    for (int i = col; i < N; ++i) {
        for (int j = 1; j <= H; ++j) {
            if (!adj[i][j] && !adj[i + 1][j]) {
                adj[i][j] = i + 1;
                adj[i + 1][j] = i;
                add_line(i, cnt + 1);
                adj[i + 1][j] = 0;
                adj[i][j] = 0;
            }
        }
    }
}


void solve() {
    for (add = 0; add <= 3; ++add) {
        add_line(1, 0);
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