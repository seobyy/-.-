#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_T 1000
using namespace std;

int dp[MAX_T + 5];

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    dp[1] = 1; dp[2] = 0; dp[3] = 1; dp[4] = 1;
    for (int i = 5; i <= N; ++i) {
        if (min({dp[i - 1], dp[i - 3], dp[i - 4]}) == 1)
            dp[i] = 0;
        else
            dp[i] = 1;
    }
    
    if (dp[N])
        cout << "SK" << '\n';
    else
        cout << "CY" << '\n';
        
    return 0;
}