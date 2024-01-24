#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 10'000
using namespace std;

struct WORK { int sT; int n;};

int N; 
int ans;
int T[MAX_N + 5];
int maxT[MAX_N + 5];
int indegree[MAX_N + 5];
vector <int> adj[MAX_N + 5];

void input() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> T[i];
        int n; cin >> n;
        indegree[i] += n;
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            adj[x].push_back(i);
        }
    }
}

void solve() {
    queue <WORK> q;
    for (int i = 1; i <= N; ++i) {
        if (!indegree[i])
            q.push({0, i});
    }
    while (!q.empty()) {
        int sT = q.front().sT;
        int n = q.front().n;
        q.pop();
        
        //cout << sT << ' ' << n << '\n';
        
        ans = max(ans, sT + T[n]);
        for (auto i : adj[n]) {
            maxT[i] = max(maxT[i], sT + T[n]);
            indegree[i]--;
            if (!indegree[i])
                q.push({maxT[i], i});
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