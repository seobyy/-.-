#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1'000'000'000
using namespace std;

typedef long long int ll;
struct NUM { int cnt; ll n; };

int A, B;
int ans = -1;

void bfs() {
    
    queue <NUM> q;
    q.push({1, A});
    
    while (!q.empty()) {
        
        int c = q.front().cnt;
        int n = q.front().n;
        q.pop();
        
        if (n == B) {
            ans = c;
            break;
        }
        
        ll case1 = (ll) 2 * n;
        ll case2 = (ll) n * 10 + 1;
        
        if (case1 <= MAX_N) 
            q.push({c + 1, case1});
        
        
        if (case2 <= MAX_N) 
            q.push({c + 1, case2});

    }
}


int main() {
    
    fastio;
    cin >> A >> B;
    
    bfs();
    
    cout << ans << '\n';
    
    return 0;
}