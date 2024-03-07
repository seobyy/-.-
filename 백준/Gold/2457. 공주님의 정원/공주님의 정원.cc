#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 2'147'000'000
using namespace std;

struct flower { int s, e; };

bool cmp(const flower &a, const flower &b) {
    if (a.e == b.e) 
        return a.s < b.s;
    return a.e > b.e;
}

int N;
int ans = INF;
vector <flower> v; 

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int m1, d1, m2, d2; cin >> m1 >> d1 >> m2 >> d2;
        v.push_back({100 * m1 + d1, 100 * m2 + d2});
    }
}

void solve() {
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < N; ++i) {
        if (v[i].e <= 1130)
            break;
            
        int cnt = 1;
        int st_time = v[i].s;
        int min_st_time = v[i].s;
        int j = 0;
        
        for (j = i + 1; j < N; ++j) {
            if (st_time <= 301)
                break;
            
            if (v[j].e < st_time) {
                if (min_st_time != st_time) {
                    st_time = min_st_time;
                    cnt++;
                    j--;
                }
                else
                    break;
            }
            else 
                min_st_time = min(min_st_time, v[j].s);
        }
        
        if (j == N && st_time > 301) {
            if (v[j - 1].s <= 301) {
                cnt++;
                st_time = v[j - 1].s;
            }
        }
        
        if (st_time <= 301)
            ans = min(ans, cnt);
    }
}

void output() {
    if (ans == INF) cout << 0 << '\n';
    else cout << ans << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}