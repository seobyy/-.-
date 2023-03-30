#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
    fastio;
    int J, R, n, pt[505] = {0}, max = 0, winner = 0;
    cin >> J >> R;
    for (int i = 1; i <= J * R; ++i) {
        cin >> n;
        pt[i % J] += n;
    }
    pt[J] = pt[0];
    for (int i = 1; i <= J; ++i) {
        if (pt[i] >= max) {
            max = pt[i];
            winner = i;
        }
    }
    cout << winner << '\n';
}