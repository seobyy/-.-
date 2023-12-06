#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
#define INF 1e9 + 9
using namespace std;

struct path1 { int end, cost;};
struct path{ int end, cost; vector<int> v;};
struct cmp {
    bool operator()(path a, path b) {
        return a.cost > b.cost;
    }
};

int n, m;
int S, E;
int dist[MAX_N + 5];
bool visited[MAX_N + 5];
vector <path1> adj[MAX_N + 5];

void dijkstra() {
    
    for (int i = 1; i <= n; ++i) {
        dist[i] = INF;
    }
    dist[S] = 0;
    
    priority_queue <path, vector<path>, cmp> pq;
    vector <int> v;
    v.push_back(S);
    pq.push({S, 0, v});
    
    while (!pq.empty()) {
        int n = pq.top().end;
        int c = pq.top().cost;
        vector <int> v = pq.top().v;
        pq.pop();
        
        if (n == E) {
            cout << dist[E] << '\n';
            cout << v.size() << '\n';
            for (auto i : v) {
                cout << i << ' ';
            }
            return;
        }
        
        if (visited[n])
            continue;
        
        visited[n] = true;
        for (auto i : adj[n]) {
            int next = i.end;
            int nc = c + i.cost;
            
            if (nc < dist[next]) {
                vector <int> tmp(v.begin(), v.end());
                tmp.push_back(next);
                dist[next] = nc;
                pq.push({next, nc, tmp});
            }
        }
    }
}

int main() {
    
    fastio;
    cin >> n >> m;
    
    for (int i = 0; i < m; ++i) {
        int s, e, c;
        cin >> s >> e >> c;
        adj[s].push_back({e, c});
    }
    
    cin >> S >> E;
    dijkstra();
    
    
    return 0;
}