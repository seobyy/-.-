#include <iostream>
#include <map>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fastio;
    int N, a, b, last = 0;
    cin >> N;
    multimap <int, int> mm;
    for (int i = 0; i < N; ++i) {
        cin >> a >> b;
        mm.insert({a, b});
    }
    for (auto i : mm) {
        if (i.first < last) {
            last += i.second;
        }
        else {
            last = i.first;
            last += i.second;
        }
    }
    cout << last << '\n';
}