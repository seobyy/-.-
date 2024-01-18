#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define ll long long 
using namespace std;

int main() {
    
    fastio;
    int n;
    cin >> n;
    for (int tc = 1; tc <= n; ++tc) {
        ll a, b;
        cin >> a >> b;
        ll ans = lcm(a, b);
        cout << ans << '\n';
    }
    
    return 0;
}