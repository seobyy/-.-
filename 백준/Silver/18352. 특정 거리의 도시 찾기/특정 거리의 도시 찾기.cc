#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 300'000
#define INF 1e9 + 9
using namespace std;

int N, M, K, X;
int dist[MAX_N + 5];
bool visited[MAX_N + 5];
vector <int> adj[MAX_N + 5];

void dijkstra() {
    
    for (int i = 1; i <= N; ++i) {
        dist[i] = INF;
    }
    dist[X] = 0;
    queue <int> q;
    q.push(X);
    
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        
        if (visited[n])
            continue;
        visited[n] = true;
        
        for (auto i : adj[n]) {
            if (1 + dist[n] < dist[i]) {
                dist[i] = 1 + dist[n];
                q.push(i);
            }
        }
    }
}

int main() {
    
    fastio;
    cin >> N >> M >> K >> X;
    
    for (int i = 0; i < M; ++i) {
        int s, e;
        cin >> s >> e;
        adj[s].push_back(e);
    }
    
    dijkstra();
    vector <int> ans;
    for (int i = 1; i <= N; ++i) {
        if (dist[i] == K) 
            ans.push_back(i);
    }
    
    if (!ans.size())
        cout << -1 << '\n';
    else {
        sort(ans.begin(), ans.end());
        for (auto i : ans) 
            cout << i << '\n';
    }
    
    return 0;
}