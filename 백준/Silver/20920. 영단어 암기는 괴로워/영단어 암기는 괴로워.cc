#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<string, int> &a, pair<string, int> &b) {
    if (a.second == b.second) {
        if (a.first.length() == b.first.length()) {
            return a.first < b.first;
        }
        return a.first.length() > b.first.length();
    }
    return a.second > b.second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    unordered_map <string, int> word;
    string W;
    for (int i = 0; i < N; ++i) {
        cin >> W;
        if (W.length() >= M)  {
            word[W]++;
        }
    }
    vector<pair<string, int>> v(word.begin(), word.end());
    sort(v.begin(), v.end(), cmp);
    for (auto p: v) {
        cout << p.first << '\n';
    }
}