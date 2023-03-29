#include <iostream>
#include <map>
#define fast_io() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int main() {
    fast_io();
    int T, n, k, t, m, i, j, s;
    cin >> T;
    for (int x = 0; x < T; ++x) {
        map <pair<int, int>, int> m1;
        int score[101] = {0}, cnt[101] = {0}, last[101] = {0};
        cin >> n >> k >> t >> m;
        for (int y = 0; y < m; ++y) {
            cin >> i >> j >> s;
            if (s > m1[{i, j}]) {
                score[i] += s - m1[{i, j}];
                m1[{i, j}] = s;
            }
            cnt[i]++;
            last[i] = y;
        }
        int rank = 0;
        for (int x = 1; x <= n; ++x) {
            if (score[x] > score[t])
                rank++;
            else if (score[x] == score[t]) {
                if (cnt[x] < cnt[t])
                    rank++;
                else if (cnt[x] == cnt[t]) {
                    if (last[x] < last[t])
                        rank++;
                }
            }
        }
        cout << rank + 1 <<'\n';
    }
}
