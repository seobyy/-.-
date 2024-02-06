#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
#define ll long long
using namespace std;

int n, m;
ll ans;

priority_queue <ll, vector<ll>, greater<ll>> pq;


void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        ans += a;
        pq.push(a);
    }
}

void solve() {
    for (int i = 0; i < m; ++i) {
        while (!pq.empty()) {
            ll a1 = pq.top();
            pq.pop();
            ll a2 = pq.top();
            pq.pop();
            
            ll sum = a1 + a2;
            pq.push(sum);
            pq.push(sum);
            ans += sum;
            break;
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