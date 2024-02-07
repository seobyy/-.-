#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_M 2000
using namespace std;

int N, M;
int ans;
int ramp[MAX_M + 5];
vector <int> v[MAX_M + 5];

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int x; cin >> x;
        for (int j = 0; j < x; ++j) {
            int n; cin >> n;
            ramp[n]++;
            v[i].push_back(n);
        }
    }
}

void solve() {
    for (int i = 1; i <= N; ++i) {
        int cnt[MAX_M + 5];
        memmove(cnt, ramp, sizeof(cnt));
        
        for (auto j: v[i]) {
            cnt[j]--;
        }
        
        bool canLight = true;
        for (int j = 1; j <= M; ++j) {
            if (cnt[j] < 1) {
                canLight = false;
                break;
            }
        } 
        if (canLight) {
            ans = 1;
            return;
        }
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