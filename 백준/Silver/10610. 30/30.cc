#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;


string str;
int arr[100005];

void input() {
    cin >> str;
}

void solve() {
    int len = str.length();
    int sum = 0;
    bool zeroCheck = false;
    for (int i = 0; i < len; ++i) {
        sum += str[i] - '0';
        arr[i] = str[i] - '0';
        if (!arr[i])
            zeroCheck = true;
    }
    
    if (!zeroCheck || sum % 3 != 0) 
        cout << -1 << '\n';
    
    else {
        sort(arr, arr + len, greater<>());
        for (int i = 0; i < len; ++i)
            cout << arr[i];
        cout << '\n';
    }
}

int main() {
    
    fastio;
    input();
    solve();
    
    return 0;
}