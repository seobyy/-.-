#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1'000'000
using namespace std;

int N;
vector <int> adj[MAX_N + 5];
int dp[MAX_N + 5][2];
bool visited[MAX_N + 5];

void dfs(int node) {
    
    if (visited[node])
        return;
    
    visited[node] = true;
    dp[node][0] = 1;
    dp[node][1] = 0;
    
    for (auto i : adj[node]) {
        
        if (visited[i])
            continue;
            
        dfs(i);
        
        dp[node][0] = dp[node][0] + min(dp[i][0], dp[i][1]);
        
        dp[node][1] = dp[node][1] + dp[i][0];
        
    }
}

int main() {
    
    fastio;
    cin >> N;
    
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    dfs(1);
    
    cout << min(dp[1][0], dp[1][1]) << '\n';
    
    return 0;
}