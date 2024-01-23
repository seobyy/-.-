#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 5000
#define INF 1e18
#define ll long long
using namespace std;

int N;
ll minSum = INF;
int arr[MAX_N + 5];
int ans[4];

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) 
        cin >> arr[i];
}

void solve() {
    sort(arr, arr + N);
    for (int i = 0; i < N; ++i) {
        int l = i + 1;
        int r = N - 1;
        while (l < r) {
            ll sum = (ll) arr[l] + arr[r] + arr[i];
            if (abs(sum) < minSum) {
                minSum = abs(sum);
                ans[1] = arr[i];
                ans[2] = arr[l];
                ans[3] = arr[r];
            }
            if (sum < 0) 
                l++;
            else 
                r--;
        }
    }
}

int main() {
    
    fastio;
    input();
    solve();
    
    cout << ans[1] << ' ' << ans[2] << ' ' << ans[3] << '\n';
    
    return 0;
}