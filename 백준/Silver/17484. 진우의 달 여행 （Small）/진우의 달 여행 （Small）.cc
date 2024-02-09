#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 601

using namespace std;

const int dx[3] = {-1, 0, 1};
int N, M, ans = MAX, space[7][7];

int solve(int y, int x, int last) {
    if (y == N)
        return 0;
    int sum = MAX;
    for (int i = 0; i < 3; ++i) {
        if (i == last)
            continue;
        if (x + dx[i] < 0 || x + dx[i] >= M)
            continue;
        sum = min(sum, solve(y + 1, x + dx[i], i) + space[y][x]);
    }
    return sum;
}

int main() {
    fastio;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> space[i][j];
        }
    }
    for (int i = 0; i < M; ++i) {
        ans = min(ans, solve(0, i, -1));
    }
    cout << ans << '\n';
    return 0;
}
