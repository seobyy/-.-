#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int num[1505][1505];
int main() {
    fastio;
    int N, max, cnt = 0, A[1505] = {0}, a = 0;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> num[i][j];
        }
    }
    while (cnt != N) {
        max = -1000000000;
        for (int j = 0; j < N; ++j) {
            int i = N - 1 - A[j];
            if (i < 0)
                continue;
            if (num[i][j] > max) {
                max = num[i][j];
                a = j;
            }
        }
        A[a]++;
        cnt++;
    }
    cout << max << '\n';
}