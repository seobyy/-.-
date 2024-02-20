#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 32'000
using namespace std;

int N, M;
int indegree[MAX_N + 5];

vector <int> v[MAX_N + 5];
vector <int> ans;

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        indegree[b]++;
        v[a].push_back(b);
    }
}

void solve() {
    
    priority_queue <int, vector<int>, greater<int>> pq;
    
    for (int i = 1; i <= N; ++i) {
        if (!indegree[i])
            pq.push(i);
    }
    
    while (!pq.empty()) {
        int n = pq.top();
        pq.pop();
        
        ans.push_back(n);
        
        for (auto i: v[n]) {
            indegree[i]--;
            if (!indegree[i])
                pq.push(i);
        }
    }
}

void output() {
    for (auto i : ans)
        cout << i << ' ';
    cout << '\n';
}


int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}