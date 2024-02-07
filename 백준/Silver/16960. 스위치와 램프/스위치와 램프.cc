#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 2000
using namespace std;

int N, M;
vector <int> v[MAX_N + 5];
bool on[MAX_N + 5];
bool canLight;

void input() {
    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int n; cin >> n;
        for (int j = 0; j < n; ++j) {
            int x; cin >> x;
            v[i].push_back(x);
        }
    }
}

void solve() {
    for (int i = 1; i <= N; ++i) {
        int cnt = 0;
        memset(on, false, sizeof(on));
        for (int j = 1; j <= N; ++j) {
            if (i != j) {
                for (auto k : v[j]) {
                    if (!on[k]) {
                        cnt++;
                        on[k] = true;
                    }
                }
            }
        }
        if (cnt == M) {
            canLight = true;
            return;
        }
    }
}

void output() {
    cout << canLight << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}