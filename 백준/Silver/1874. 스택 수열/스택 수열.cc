#include <iostream>
#include <stack>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100000
using namespace std;

int arr[MAX_N + 5];

int main() {
    
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    
    int next_index = 1;
    stack <int> stack;
    string ans;
    
    for (int i = 1; i <= n; ++i) {
        if (i <= arr[next_index]) {
            stack.push(i);
            ans += "+\n";
        }
        else {
            if (stack.top() == arr[next_index]) {
                stack.pop();
                ans += "-\n";
                next_index++;
                i--;
            }
            else {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }
    
    while (!stack.empty()) {
        if (stack.top() == arr[next_index]) {
            stack.pop();
            ans += "-\n";
            next_index++;
        }
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    cout << ans << '\n';
    
    return 0;
}