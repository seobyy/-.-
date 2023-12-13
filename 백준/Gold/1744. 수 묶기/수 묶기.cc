#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    vector <int> v1;    // 음수
    vector <int> v2;    // 0 
    vector <int> v3;    // 양수
    
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        if (n < 0) v1.push_back(n);
        else if (!n) v2.push_back(n);
        else v3.push_back(n);
    }
    sort(v1.begin(), v1.end());
    sort(v3.begin(), v3.end());
    int ans = 0;
    int len = v1.size();
    
    for (int i = 0; i < len - 1; ++i) {
        ans += v1[i] * v1[i + 1];
        i++;
    }
    
    if (len % 2 == 1) {
        if (!v2.size())
            ans += v1[len - 1];
    }
    
    for (int i = v3.size() - 1; i >= 0; --i) {
        if (i && v3[i] * v3[i - 1] >= v3[i] + v3[i - 1])  {
            ans += v3[i] * v3[i - 1];
            i--;
        }
        else
            ans += v3[i];
    }
    
    cout << ans << '\n';
    
    return 0;
}