#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
#define ll long long
using namespace std;

int n, m;
ll ans;
ll arr[MAX_N + 5];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        ans += arr[i];
    }
}

void solve() {
    for (int i = 0; i < m; ++i) {
        swap(arr[0], *min_element(arr, arr + n));
        swap(arr[1], *min_element(arr + 1, arr + n));
        ll sum = arr[0] + arr[1];
        ans += sum;
        arr[0] = sum;
        arr[1] = sum;
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