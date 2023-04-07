#include <iostream>
#include <map> 
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    fastio;
    int N, M, cnt = 0;
    cin >> N >> M;
    string name;
    map <string, int> m;
    for (int i = 0; i < N; ++i) {
        cin >> name;
        m[name]++;
    }
    for (int i = 0; i < M; ++i) {
        cin >> name;
        m[name]++;
        if (m[name] == 2)
            cnt++;
    }
    cout << cnt << '\n';
    for (auto i : m) {
        if (i.second == 2)
            cout << i.first << '\n';
    }
}
