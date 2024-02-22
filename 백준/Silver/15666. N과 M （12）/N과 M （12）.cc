#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N, M;
int arr[10];
int ans[10];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void sel_number(int index, int cnt) {
    
    if (cnt == M) {
        for (int i = 0; i < M; ++i) 
            cout << ans[i] << ' ';
        cout << '\n';
        return;
    }
    
    int last = 0;
    for (int i = index; i < N; ++i) {
        if (last != arr[i]) {
            ans[cnt] = arr[i];
            sel_number(i, cnt + 1);
            last = arr[i];
        }
    }
}

void solve() {
    sort(arr, arr + N);
    sel_number(0, 0);
}

int main() {
    
    fastio;
    input();
    solve();
    
    return 0;
}