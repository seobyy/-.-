#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 20
#define MAX_M 100000
using namespace std;

int N, M;
int ans;
int dp[MAX_N + 5][MAX_M + 5];

vector <int> coin;

void init() {
    coin.clear();
    memset(dp, -1, sizeof(dp));
}

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int n; cin >> n;
        coin.push_back(n);
    }
    cin >> M;
}

int cal_dp(int res, int index) {
    
    if (index < 0) {
        if (res == 0) return 1;
        else return 0;
    }
    
    if (dp[index][res] != -1)
        return dp[index][res];
    
    int sum = 0;
    int quo = res / coin[index];
    for (int i = quo; i >= 0; --i) {
        sum += cal_dp(res - coin[index] * i, index - 1);
    }
    
    return dp[index][res] = sum;
}

void solve() {
    ans = cal_dp(M, N - 1);    
}

void output() {
    cout << ans << '\n';
}

int main() {
    
    fastio;
    int T; cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {

        init();        
        input();
        solve();
        output();
        
    }
    
    return 0;
}