#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long
using namespace std;

const int MOD = 1'000'000;

string str;
ll ans;
ll dp[5005][2];

void input() {
    cin >> str;
}

void solve() {
    if (str[0] == '0')
        return;
        
    dp[0][0] = 1;
    int len = str.length();
    for (int i = 1; i < len; ++i) {
        int last = str[i - 1] - '0';
        if (str[i] == '0') {
            if (last == 1 || last == 2)
                dp[i][1] = dp[i - 1][0];
            else
                return;
        }
        
        else {
            if (last > 2 || !last) 
                dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
                
            else {
                if (last == 2 && str[i] - '0' > 6)
                    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
                else {
                    dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
                    dp[i][1] = dp[i - 1][0];
                }
            }
        }
    }
    
    ans = (dp[len - 1][0] + dp[len - 1][1]) % MOD;
}

void output() {
    cout << ans << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}