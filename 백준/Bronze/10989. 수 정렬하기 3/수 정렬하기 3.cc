#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fastio;
    int N, num, cnt[100001] = {0};
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> num;
        cnt[num]++;
    }
    for (int i = 1; i<= 10000; ++i) {
        if (cnt[i] != 0) {
            for (int j = 0; j < cnt[i]; ++j)
                cout << i << '\n';
        }
    }
    return 0;
}