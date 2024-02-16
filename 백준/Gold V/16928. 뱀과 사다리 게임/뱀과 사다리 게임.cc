#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct POS { int n; int diceCnt; };

int N, M;
int ans;
int ladders[105];
int snakes[105];

bool visited[105];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        ladders[x] = y;
    }
    for (int i = 0; i < M; ++i) {
        int u, v; cin >> u >> v;
        snakes[u] = v;
    }
}

void solve() {
    queue <POS> q;
    q.push({1, 0});
    visited[1] = true;
    
    while (!q.empty()) {
        int n = q.front().n;
        int c = q.front().diceCnt;
        q.pop();
        
        if (n == 100) {
            ans = c;
            break;
        }
        
        for (int i = 1; i <= 6; ++i) {
            int next = n + i;
            if (next > 100)
                continue;
            if (visited[next])
                continue;
                
            visited[next] = true;
            if (ladders[next]) 
                q.push({ladders[next], c + 1});
            else if (snakes[next]) 
                q.push({snakes[next], c + 1});
            else
                q.push({next, c + 1});
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