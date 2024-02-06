#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_L 1'000'000'000
using namespace std;

struct LINE { int s, e; };

int N;
int ans;
vector <LINE> v;

bool cmp (LINE a, LINE b) {
    if (a.s == b.s)
        return a.e > b.e;
    return a.s < b.s;
}

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x, y; cin >> x >> y;
        v.push_back({x, y});
    }
}

void solve() {
    sort(v.begin(), v.end(), cmp);
    int last = -MAX_L - 5;
    for (auto i : v) {
        if (i.s < last) {
            if (i.e > last) {
                ans += i.e - last;
                last = i.e;
            }
        }
        else {
            ans += i.e - i.s;
            last = i.e;
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