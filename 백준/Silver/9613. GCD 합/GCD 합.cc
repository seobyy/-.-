#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100
#define ll long long
using namespace std;

int main() {
    
    fastio;
    int t;
    cin >> t;
    
    for (int tc = 1; tc <= t; ++tc) {
        
        int n;
        cin >> n;
        ll ans = 0;
        int num[MAX_N + 5];
        
        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }
        
        for (int i = 0; i < n - 1; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += __gcd(num[i], num[j]);
            }
        }
        
        cout << ans << '\n';
        
    }
    
    return 0;
}