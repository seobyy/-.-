#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100'000
using namespace std;

int arr[MAX_N + 5];
int dp[MAX_N + 5][2];

int main() {
    
    fastio;
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    
    int ans = arr[1];
    dp[1][1] = arr[1];
    for (int i = 2; i <= n; ++i) {
        dp[i][0] = 0;
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + arr[i];
        
        if (dp[i][1] > ans)
            ans = dp[i][1];
    }
    
    cout << ans << '\n';
    
    return 0;
}