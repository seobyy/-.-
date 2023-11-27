#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    
    fastio;
    int N, K;
    cin >> N >> K;
    
    queue <int> q;
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }
    
    cout << "<";
    int cnt = 0;
    while (!q.empty()) {
        
        int n = q.front();
        q.pop();
        cnt++;
        
        if (cnt == K) {
            if (q.empty())
                cout << n << ">" << '\n';
            else
                cout << n << ", ";
            cnt = 0;
            continue;
        }
        q.push(n);
    }
    
    return 0;
}