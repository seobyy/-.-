#include <bits/stdc++.h>

using namespace std;

void fast_io() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
}

int main() {
    fast_io();
    int N, M, power, P;
    string title;
    map <int, string> m;
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> title >> power;
        m.insert({power, title});
    }
    for (int i = 0; i < M; ++i) {
        cin >> P;
        cout << (m.lower_bound(P)) -> second << '\n';
    }
}
