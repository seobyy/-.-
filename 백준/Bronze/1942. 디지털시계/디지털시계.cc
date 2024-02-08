#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

void solve() {
    for (int i = 0; i < 3; ++i) {
        string str1, str2; cin >> str1 >> str2;
        string s1 = "";
        string s2 = "";
        for (int j = 0; j < 8; ++j) {
            if (str1[j] != ':' && !(s1 == "" && str1[j] == '0'))
                s1 += str1[j];
            if (str2[j] != ':' && !(s2 == "" && str2[j] == '0'))
                s2 += str2[j];
        }

        int n1 = stoi(s1);
        int n2 = stoi(s2);
        if (n1 > n2)
            n2 += 240000;
            
        int ans = 0;
        for (int j = n1; j <= n2; ++j) {
                
            int m = (j / 100) % 100 ;
            int s = j % 100;
            if (m >= 60 || s >= 60)
                continue;
            if (j % 3 == 0)
                ans++;
        }

        cout << ans << '\n';
    }
}

int main() {
    
    fastio;
    solve();
    
    return 0;
}