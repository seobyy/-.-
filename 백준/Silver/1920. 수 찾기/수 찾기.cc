#include <iostream>
#include <set>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fastio;
    int N, M, a, b;
    cin >> N;
    set <int> s;
    for (int i = 0; i < N; ++i) {
        cin >> a;
        s.insert(a);
    }
    cin >> M;
    for (int i = 0; i < M; ++i) {
        cin >> b;
        if (s.find(b) == s.end()) cout << 0 << '\n';
        else cout << 1 << '\n';
    }
    return 0;
}