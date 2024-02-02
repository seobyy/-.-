#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100'000
#define ll long long
#define INF 1e18
using namespace std;

struct EDGE { ll cost; int node; };
struct cmp {
    bool operator()(EDGE a, EDGE b) {
        return a.cost > b.cost;
    }
};

int N, M, K;
int ans;
ll minDis;
ll dist[MAX_N + 5];
bool visited[MAX_N + 5];
vector <EDGE> adj[MAX_N + 5][2];

priority_queue <EDGE, vector<EDGE>, cmp> pq;

void init() {
    for (int i = 1; i <= N; ++i) {
        dist[i] = INF;
    }
}

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; ++i) {
        int U, V, C;
        cin >> U >> V >> C;
        adj[U][0].push_back({C, V});
        adj[V][1].push_back({C, U});
    }
    init();
    for (int i = 0; i < K; ++i) {
        int n; cin >> n;
        dist[n] = 0;
        pq.push({0, n});
    }
}

void dijkstra() {
    while (!pq.empty()) {
        ll c = pq.top().cost;
        int n = pq.top().node;
        pq.pop();
        
        if (visited[n])
            continue;
            
        visited[n] = true;
        
        for (auto i : adj[n][1]) {
            int next = i.node;
            ll nc = c + i.cost;
            if (nc < dist[next]) {
                dist[next] = nc;
                pq.push({nc, next});
            }
        }
    }
}

void findAns() {
    for (int i = 1; i <= N; ++i) {
        if (dist[i] > minDis) {
            ans = i;
            minDis = dist[i];
        }
    }
}

void output() {
    cout << ans << '\n';
    cout << minDis << '\n';
}


int main() {
    
    fastio;
    input();
    dijkstra();
    findAns();
    output();
    
    return 0;
}