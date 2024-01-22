#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100'000
#define MAX_NUM 1'000'000
using namespace std;

int N;
int nums[MAX_N + 5];
int score[MAX_N + 5];

unordered_map <int, int> numIndex;

void input() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i];
        numIndex[nums[i]] = i;
    }
}

void solve() {
    for (int i = 1; i <= N; ++i) {
        int n = nums[i];
        for (int j = 2 * n; j <= MAX_NUM; j += n) {
            if (numIndex[j]) {
                score[i]++;
                score[numIndex[j]]--;
            }
        }
    }
}

void output() {
    for (int i = 1; i <= N; ++i) {
        cout << score[i] << ' ';
    }
    cout << '\n';
}

int main() {

    fastio;
    input();
    solve();
    output();

    return 0;
}