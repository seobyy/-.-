#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 300'000
using namespace std;

int n;
double ans;
double arr[MAX_N + 5];

void input() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void solve() {
    sort(arr, arr + n);
    double x = 0.15 * n;
    
    double delNum = round(x);
    double cnt = n - delNum * 2;
    double sum = 0;
    for (int i = delNum; i < n - delNum; ++i) {
        sum += arr[i];
    }
    if (cnt)
        ans = round(sum / cnt);
    
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