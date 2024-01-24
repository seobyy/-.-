#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
using namespace std;

struct ACM { int sT; int n;};

int N, K, W;
int ans;
int delay[MAX_N + 5];
int indegree[MAX_N + 5];
int maxT[MAX_N + 5];

vector <int> adj[MAX_N + 5];

void init() {
    for (int i = 1; i <= N; ++i) {
        adj[i].clear();
        indegree[i] = 0;
        maxT[i] = 0;
    }
    ans = 0;
}

void input() {
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        cin >> delay[i];
    }
    init();
    for (int i = 0; i < K; ++i) {
        int X, Y; cin >> X >> Y;
        adj[X].push_back(Y);
        indegree[Y]++;
    }
    cin >> W;
}

void solve() {
    queue <ACM> q;
    for (int i = 1; i <= N; ++i) {
        if (!indegree[i])
            q.push({0, i});
    }
    while (!q.empty()) {
        int sT = q.front().sT;
        int n = q.front().n;
        q.pop();
        
        //cout << sT << ' ' << n << '\n';
        
        if (n == W) {
            ans = sT + delay[n];
            break;
        }
        
        for (auto i : adj[n]) {
            indegree[i]--;
            maxT[i] = max(maxT[i], sT + delay[n]);
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
    int T; cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        input();
        solve();
        output();
    }
    
    return 0;
}