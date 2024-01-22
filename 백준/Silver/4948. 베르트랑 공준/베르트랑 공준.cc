#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 123'456
using namespace std;

int ans;
bool isPrime[2 * MAX_N + 5];

void solve() {
    for (int i = 1; i <= 2 * MAX_N; ++i) {
        isPrime[i] = true;
    }
    
    for (int i = 2; i <= 2 * MAX_N; ++i) {
        if (isPrime[i]) {
            for (int j = i * 2; j <= 2 * MAX_N; j += i)
                isPrime[j] = false;
        }
    }
}


int main() {
    
    fastio;
    solve();
    while (1) {
        int n; cin >> n;
        if (!n)
            break;
        int ans = 0;
        for (int i = n + 1; i <= 2 * n; ++i) {
            if (isPrime[i])
                ans++;
        }
        cout << ans << '\n';
    } 
    
    return 0;
}