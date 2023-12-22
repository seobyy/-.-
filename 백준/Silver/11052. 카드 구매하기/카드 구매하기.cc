#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
using namespace std;

int dp[MAX_N + 5];
int price[MAX_N + 5];

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    for (int i = 1; i <= N; ++i) {
        cin >> price[i];
    }
    
    dp[1] = price[1];
    for (int i = 2; i <= N; ++i) {
        dp[i] = max(dp[i], price[i]);
        for (int j = 1; j <= i; ++j) {
            if (i % j == 0) 
                dp[i] = max(dp[i], dp[j] * i / j);
            dp[i] = max(dp[i], dp[j] + dp[i - j]);
        }
    }
    
    cout << dp[N] << '\n';
    
    return 0;
}