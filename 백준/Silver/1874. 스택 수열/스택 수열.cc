#include <iostream>
#include <stack>
#include <vector>
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
    vector <char> v;
    
    for (int i = 1; i <= n; ++i) {
        if (i <= arr[next_index]) {
            stack.push(i);
            v.push_back('+');
        }
        else {
            int n = stack.top();
            if (n == arr[next_index]) {
                stack.pop();
                v.push_back('-');
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
        int n = stack.top();
        if (n == arr[next_index]) {
            stack.pop();
            v.push_back('-');
            next_index++;
        }
        else {
            cout << "NO" << '\n';
            return 0;
        }
    }
    
    for (auto i : v) {
        cout << i << '\n';
    }
    
    return 0;
}