#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
#define ll long long
using namespace std;

int n, m;
ll ans;
vector <ll> v;
ll minNum[2];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        ans += a;
        v.push_back(a);
    }
}

void solve() {
    for (int i = 0; i < m; ++i) {
        sort(v.begin(), v.end());
        ll sum = v[0] + v[1];
        ans += sum;
        v[0] = sum;
        v[1] = sum;
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