#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N, S;
int ans;
int arr[25];
int num[25];
void input() {
    cin >> N >> S;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void sel_num(int index, int cnt) {
    
    if (cnt) {
        int sum = 0;
        for (int i = 0; i < cnt; ++i) 
            sum += num[i];
        if (sum == S)
            ans++;
    }
    
    for (int i = index; i < N; ++i) {
        num[cnt] = arr[i];
        sel_num(i + 1, cnt + 1);
    }
    
}

void solve() {
    sel_num(0, 0);
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