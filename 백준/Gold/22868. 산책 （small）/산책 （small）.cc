#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 10000

using namespace std;

struct POS { int dis; int n; };
struct cmp {
    bool operator()(POS a, POS b) {
        return a.dis > b.dis;
    }
};

int N, M;
int S, E;
int ans;
vector <int> adj[MAX_N + 5];
bool visited[MAX_N + 5];
int last[MAX_N + 5];

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int A, B; cin >> A >> B;
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    cin >> S >> E;
}

void bfs(int mode) {
    
    memset(visited, false, sizeof(visited));
    
    priority_queue <POS, vector<POS>, cmp> pq;
    
    if (mode == 1) {
        pq.push({0, S});
        visited[S] = true;
    }
    
    else if (mode == 2) {
        
        int node = E;
        while (node != S) {
            node = last[node];
            visited[node] = true;
        }
        
        visited[S] = false;
        pq.push({0, E});
    }
    
    while (!pq.empty()) {
        
        int d = pq.top().dis;
        int n = pq.top().n;
        pq.pop();
        
        if (mode == 1 && n == E) {
            ans += d;
            break;
        }
        
        
        if (mode == 2 && n == S) {
            ans += d;
            break;
        }
        
        for (auto i : adj[n]) {
            if (!visited[i]) {
                visited[i] = true;
                last[i] = n;
                pq.push({d + 1, i});
            }
        }
    }
}

void solve() {
    
    for (int i = 1; i <= N; ++i) {
        sort(adj[i].begin(), adj[i].end());
    }
    bfs(1);
    bfs(2);
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