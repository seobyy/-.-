#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    
    int N;
    cin >> N;
    
    queue <int> q;
    int cnt = 0;
    
    while (1) {
        int n;
        cin >> n;
        
        if (n == -1)
            break;
        
        else if (!n) {
            q.pop();
            cnt--;
        }
        else {
            if (cnt + 1 <= N) { 
                q.push(n);
                cnt++;
            }
        }
    }
    
    if (q.empty())
        cout << "empty" << '\n';
    else {
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
    }
    
    cout << '\n';
    
    return 0;
}