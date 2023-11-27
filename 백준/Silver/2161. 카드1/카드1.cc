#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    queue <int> q;
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }
    
    while (!q.empty()) {
        
        int n1 = q.front();
        cout << n1 << " ";
        q.pop();
        
        if (!q.empty()) {
            int n2 = q.front();
            q.push(n2);
            q.pop();
        }
    }
    cout << '\n';
    
    return 0;
}