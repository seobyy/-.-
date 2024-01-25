#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
using namespace std;

int N, M;
int indegree[MAX_N + 5];

vector <int> adj[MAX_N + 5];
vector <int> ans;

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int n; cin >> n;
        vector <int> v;
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            v.push_back(x);
        }
        for (int j = 0; j < n; ++j) {
            for (int k = j + 1; k < n; ++k) {
                adj[v[j]].push_back(v[k]);
                indegree[v[k]]++;
            }
        }
    }
}

void solve() {
    
    queue <int> q;
    for (int i = 1; i <= N; ++i) {
        if (!indegree[i])
            q.push(i);
    }
    while (!q.empty()) {
        int n = q.front();
        q.pop();
        
        ans.push_back(n);
        for (auto i : adj[n]) {
            indegree[i]--;
            if (!indegree[i])
                q.push(i);
        }
    }
}

void output() {
    if (ans.size() != N)    
        cout << 0 << '\n';
    else {
        for (auto i : ans) 
            cout << i << '\n';
    }
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}