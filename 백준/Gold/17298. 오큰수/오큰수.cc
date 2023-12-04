#include <iostream>
#include <stack>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1'000'000
using namespace std;

int A[MAX_N + 5];
int ans[MAX_N + 5];

int main() {
    
    fastio;
    int N;
    cin >> N;

    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }
    
    stack <int> s;
    for (int i = N; i >= 1; --i) {
        while (!s.empty() && s.top() <= A[i]) {
            s.pop();
        }
        if (!s.empty())
            ans[i] = s.top();
        else
            ans[i] = -1;
        s.push(A[i]);
    }
    
    for (int i = 1; i <= N; ++i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}