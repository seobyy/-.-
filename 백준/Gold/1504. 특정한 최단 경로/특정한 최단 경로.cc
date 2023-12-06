#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 800
#define INF 1e9 + 9
#define ll long long
using namespace std;

struct path { int node, cost; };
struct cmp {
    bool operator()(path a, path b) {
        return a.cost > b.cost;
    }
};

int N, E;
ll dist[MAX_N + 5];
vector <path> adj[MAX_N + 5];
bool visited[MAX_N + 5];

void dijkstra(int s) {
    
    for (int i = 1; i <= N; ++i) {
        dist[i] = INF;
    }
    memset(visited, false, sizeof(visited));
    
    dist[s] = 0;
    priority_queue <path, vector<path>, cmp> pq;
    pq.push({s, 0});
    
    while (!pq.empty()) {
        int n = pq.top().node;
        int c = pq.top().cost;
        pq.pop();
        
        if (visited[n])
            continue;
            
        visited[n] = true;
        
        for (auto i : adj[n]) {
            int next = i.node;
            int nc = c + i.cost;
            if (nc < dist[next]) {
                dist[next] = nc;
                pq.push({next, nc});
            }
        }
    }
}

int main() {
    
    fastio;
    cin >> N >> E;
    
    for (int i = 0; i < E; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    
    int v1, v2;
    cin >> v1 >> v2;
    
    dijkstra(v1);
    ll v1To1 = dist[1];
    ll v1Tov2 = dist[v2];
    ll v1ToN = dist[N];
    
    dijkstra(v2);
    ll v2To1 = dist[1];
    ll v2ToN = dist[N];
    
    ll ans1 = (ll)(v1To1 + v1Tov2 + v2ToN);
    ll ans2 = (ll)(v2To1 + v1Tov2 + v1ToN);
    
    ll ans = ans1 < ans2 ? ans1 : ans2;
    ans = (ans >= INF) ? -1 : ans;
    
    cout << ans << '\n';
    
    return 0;
}