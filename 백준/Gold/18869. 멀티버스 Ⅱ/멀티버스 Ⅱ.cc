#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_M 100
using namespace std;

struct POS { int num, index; };

int M, N;
int ans;
vector <POS> v[MAX_M + 5];

bool cmp(POS a, POS b) {
    return a.num < b.num;
}


void input() {
    cin >> M >> N;
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            int x; cin >> x;
            v[i].push_back({x, j});
        }
    }
}

void solve() {
    
    for (int i = 1; i <= M; ++i) {
        sort(v[i].begin(), v[i].end(), cmp);
    }
    
    for (int i = 1; i <= M; ++i) {
        for (int j = i + 1; j <= M; ++j) {
            
            bool is_same = true;
            for (int k = 0; k < N; ++k) {
                if (v[i][k].index != v[j][k].index) {
                    is_same = false;
                    break;
                }
                if (k < N - 1 && v[i][k].num == v[i][k + 1].num) {
                    if (v[j][k].num != v[j][k + 1].num) {
                        is_same = false;
                        break;
                    }
                }
                
            }
            
            
            if (is_same) 
                ans++;
            
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