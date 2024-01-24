#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL) 
#define MAX_N 32'000
using namespace std;

int N, M;
int indegree[MAX_N + 5];
vector <int> adj[MAX_N + 5];
vector <int> ans;

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        adj[A].push_back(B);
        indegree[B]++;
    }
}

void topologicalSort() {
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
   for (auto i : ans) {
        cout << i << ' ';
    }
    cout << '\n'; 
}

int main() {
    
    fastio;
    input();
    topologicalSort();
    output();
    
    return 0;
}