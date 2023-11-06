#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

typedef pair<int, int> pii;

int main() {
    
    fastio;
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        
        int N, M;
        cin >> N >> M;
        
        queue <pii> q;
        priority_queue <int> pq;
        
        for (int i = 0; i < N; ++i) {
            int x;
            cin >> x;
            q.push({x, i});
            pq.push(x);
        }
        
        int cnt = 0;
        int next = pq.top();
        pq.pop();
        
        while (!q.empty()) {
            int x = q.front().first;
            int n = q.front().second;
            q.pop();
            
            if (x == next) {
                cnt++;
                if (n == M) {
                    cout << cnt << '\n';
                    break;
                }
                next = pq.top();
                pq.pop();
            }
            else
                q.push({x, n});
            
        }
    }
    
    return 0;
}