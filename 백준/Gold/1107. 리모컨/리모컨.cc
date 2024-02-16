#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 2'147'000'000
using namespace std;

int N, M;
int cur = 100;
int ans;
bool broken[10];

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int n; cin >> n;
        broken[n] = true;
    }
}

void solve() {
    
    int a = 0;
    int gap = abs(cur - N);
    ans = gap;
    while (a <= gap) {
        int n1 = N - a;
        int n2 = N + a;
            
        string s1 = to_string(n1);
        string s2 = to_string(n2);
        int len1 = s1.length();
        int len2 = s2.length();
            
        bool can_push1 = true;
        bool can_push2 = true;
        for (int j = 0; j < len1; ++j) {
            if (broken[s1[j] - '0']) {
                can_push1 = false;
                break;
            }
        }
        for (int j = 0; j < len2; ++j) {
            if (broken[s2[j] - '0']) {
                can_push2 = false;
                break;
            }
        }    
        
        int cnt1 = can_push1 ? len1 + a : INF;
        int cnt2 = can_push2 ? len2 + a : INF;
            
        int x1 = abs(cur - n1) + a;
        int x2 = abs(cur - n2) + a;
        
        ans = min({cnt1, cnt2, x1, x2});
        
        if (can_push1 || can_push2)
            break;
            
        a++;
    }
}

void output() {
    cout << ans << '\n';
}


int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}