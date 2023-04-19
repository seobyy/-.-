#include <iostream>
#include <map>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int main() {
    fastio;
    int N, max = 0;
    string book, ans;
    cin >> N;
    map <string, int> m;
    for (int i = 0; i < N; ++i) {
        cin >> book;
        m[book]++;
    }
    for (auto i : m) {
        if (i.second > max) {
            max = i.second;
            ans = i.first;
        }
    }
    cout << ans << '\n';
}