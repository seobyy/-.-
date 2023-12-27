#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N, r, c;
int ans;

void solve(int y, int x, int size) {
    
    if (y == r && x == c) {
        cout << ans << '\n';
        return;
    }
    
    int addS = pow(2, size);
    if (r >= y && r < y + addS && c >= x && c < x + addS) {
        int ns = size - 1;
        addS = pow(2, ns);
        solve(y, x, ns);
        solve(y, x + addS, ns);
        solve(y + addS, x, ns);
        solve(y + addS, x + addS, ns);
    }
    
    else
        ans += addS * addS;
}

int main() {
    
    fastio;
    cin >> N >> r >> c;
    
    solve(0, 0, N);
    
    return 0;
}