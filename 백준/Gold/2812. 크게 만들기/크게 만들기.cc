#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N, K;
string str;
string ans;
stack <int> s;

void input() {
    cin >> N >> K >> str;
}

void solve() {
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        int n = str[i] - '0';
        
        if (cnt == K || s.empty())
            s.push(n);
        
        else {
            if (n > s.top()) {
                while (!s.empty() && cnt < K) {
                    if (n <= s.top())
                        break;
                    s.pop();
                    cnt++;
                }
                s.push(n);
            }
            else
               s.push(n);
        }
    }
    if (cnt == K) {
        while (!s.empty()) {
            ans += to_string(s.top());
            s.pop();
        }
    }
    else {
        while (!s.empty() && cnt < K) {
            s.pop();
            cnt++;
        }
        
        while (!s.empty()) {
            ans += to_string(s.top());
            s.pop();
        }
    }
    
}


void output() {
    for (int i = ans.length() - 1; i >= 0; --i)
        cout << ans[i];
    cout << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}