#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int k, N; 
int S[15];
int ans[6];

void input() {
    cin >> k;
    for (int i = 0; i < k; ++i) {
        cin >> S[i];
    }
}

void sel_number(int index, int cnt) {
    if (cnt == 6) {
        for (int i = 0; i < 6; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    
    for (int i = index; i < k; ++i) {
        ans[cnt] = S[i];
        sel_number(i + 1, cnt + 1);
    }
    
    
}

void solve() {
    sel_number(0, 0);
    cout << '\n';
}

int main() {
    
    fastio;
    while (1) {
        
        input();
        if (!k) break;
        solve();
        
    }
    
    return 0;
}