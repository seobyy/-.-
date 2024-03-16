#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1'000'000
using namespace std;

int N, M;
int ans;
string S;
int dp[MAX_N + 5];

void input() {
    cin >> N >> M >> S;
}

void solve() {
    
    string tmp = "";
    for (int i = 0 ; i < M; ++i) {
        if (S[i] == 'I') {
            if (tmp == "") tmp = 'I';
            else if (tmp == "IO") {
                tmp = "I";
                dp[i] = dp[i - 2] + 1;
            }
        }
        else if (S[i] == 'O') {
            if (tmp == "I") tmp += S[i];
            else tmp = "";
        }

    }
    
    for (int i = 0; i < M; ++i) {
        //cout << dp[i] << ' ';
        if (dp[i] >= N)
            ans++;
    }
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