#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N, M;
int arr[10];
int nums[10];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void backtraking(int cnt) {
    if (cnt == M) {
        for (int i = 0; i < M; ++i) {
            cout << nums[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    int last = 0;
    for (int i = 0; i < N; ++i) {
        if (last != arr[i]) {
            nums[cnt] = arr[i];
            backtraking(cnt + 1);
            last = arr[i];
        }
    }
}

void solve() {
    sort(arr, arr + N);
    backtraking(0);
}


int main() {
    
    fastio;
    input();
    solve();
    
    return 0;
}