#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 10'000
using namespace std;


int N, M;
int ans;
int arr[MAX_N + 5];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void solve() {
    int l = 0;
    int r = 0;
    int sum = 0;
    while (r <= N) {
        if (sum < M) 
            sum += arr[r++];
        else if (sum > M)
            sum -= arr[l++];
        else {
            ans++;
            sum -= arr[l++];
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