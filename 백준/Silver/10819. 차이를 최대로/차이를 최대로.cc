#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int N;
int ans;
int arr[10];
int A[10];
bool selected[10];

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> arr[i];
}

void selNum(int cnt) {
    if (cnt == N) {
        int sum = 0;
        for (int i = 0; i < N - 1; ++i) {
            sum += abs(A[i] - A[i + 1]);
        }
        ans = max(ans, sum);
        return;
    }
    for (int i = 0; i < N; ++i) {
        if (!selected[i]) {
            selected[i] = true;
            A[cnt] = arr[i];
            selNum(cnt + 1);
            selected[i] = false;
        }
    }
}

void solve() {
    selNum(0);
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