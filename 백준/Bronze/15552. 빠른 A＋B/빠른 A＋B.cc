#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fastio;
    int T, A, B;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        cin >> A >> B;
        cout << A + B << '\n';
    }
}