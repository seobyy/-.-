#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 200'000
using namespace std;

int N;
int ans;
int d[2];
int arr[MAX_N + 5];

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
}

void solve() {
    sort(arr, arr + N);
    int mid = N / 2;
    if (N % 2 == 0) {
        for (int c = 0; c < 2; ++c) {
            for (int i = 0; i < N; ++i)
                d[c] += abs(arr[mid - c] - arr[i]);
        }
        if (d[1] <= d[0])
            ans = arr[mid - 1];
        else
            ans = arr[mid];
    }
    else {
        ans = arr[mid];
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