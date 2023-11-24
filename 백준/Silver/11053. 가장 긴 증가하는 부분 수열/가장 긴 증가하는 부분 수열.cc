#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
using namespace std;

int A[MAX_N + 5];
int dp[MAX_N + 5];

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (A[j] < A[i])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        if (dp[i] > ans)
            ans = dp[i];
    }
    
    cout << ans << '\n';
    
    return 0;
}