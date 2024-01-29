#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;


int N, M;
int arr[10];
int nums[10];
set <vector<int>> s;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
}

void backtraking(int index, int cnt) {
    if (cnt == M) {
        vector <int> tmp;
        for (int i = 0; i < M; ++i) {
            tmp.push_back(nums[i]);
        }
        s.insert(tmp);
        return;
    }
    
    for (int i = index; i < N; ++i) {
        nums[cnt] = arr[i];
        backtraking(i + 1, cnt + 1);
    }
}

void solve() {
    sort(arr, arr + N);
    backtraking(0, 0);
}

void output() {
    for (auto i : s) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << '\n';
    }
}


int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}