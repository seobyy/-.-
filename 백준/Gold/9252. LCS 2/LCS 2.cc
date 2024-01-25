#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_LEN 1000
using namespace std;

string str1, str2;
string ans;
int maxLen;
int LCS[MAX_LEN + 5][MAX_LEN + 5];

void input() {
    cin >> str1 >> str2;
}

void solve2(int y, int x) {
    int val = LCS[y][x];
    if (!val)
        return;
    if ((y - 1) && LCS[y - 1][x] == val)
        solve2(y - 1, x);
    else if ((x - 1) && LCS[y][x - 1] == val)
        solve2(y, x - 1);
    else {
        ans += str1[y - 1];
        solve2(y - 1, x - 1);
    }
}

void solve() {
    int len1 = str1.length();
    int len2 = str2.length();
    
    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
                maxLen = max(maxLen, LCS[i][j]);
            }
            else
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
        }
    }
    solve2(len1, len2);
}

void output() {
    cout << maxLen << '\n';
    for (int i = maxLen - 1; i >= 0; --i) {
        cout << ans[i];
    }
    cout << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}