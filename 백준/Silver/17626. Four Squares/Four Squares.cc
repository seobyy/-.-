#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct NUM { int n; int cnt; };
struct cmp {
    bool operator()(NUM a, NUM b) {
        return a.cnt > b.cnt;
    }
};

int n;
bool is_find;
int ans;
bool visited[50005];

priority_queue <NUM, vector<NUM>, cmp> pq;

void input() {
    cin >> n;
}

void solve() {
    
    pq.push({n, 0});
    visited[n] = true;
    
    while (!pq.empty()) {
        
        int num = pq.top().n;
        int c = pq.top().cnt;
        pq.pop();
        
        if (!num) {
            ans = c;
            break;
        }
        
        int a = sqrt(num);
        
        for (int i = a; i >= 1; --i) {
            int x = num - i * i;
            if (!visited[x]) {
                pq.push({x, c + 1});
                visited[x] = true;
            }
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