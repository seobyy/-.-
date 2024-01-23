#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100'000
#define INF 2'147'000'000
using namespace std;

int N, M;
int ans = INF;
int arr[MAX_N + 5];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void solve() {
    sort(arr, arr + N);
    int l = 0, r = 0;
    while (l <= r && r < N) {
        int res = arr[r] - arr[l];
        if (res < M) {
            if (r != N - 1)
                r++;
            else
                l++;
        }
        else {
            ans = min(ans, res);
            l++;
        }
    }
}

int main() {
    
    fastio;
    input();
    solve();
    
    cout << ans << '\n';
    
    return 0;
}