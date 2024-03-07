#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    fastio;
    int N, s, e;
    cin >> N;
    vector <pair<int, int>> meeting;
    for (int i = 0; i < N; ++i) {
        cin >> s >> e;
        meeting.push_back({e, s});
    }
    sort(meeting.begin(), meeting.end());
    int cnt = 1;
    int end_time = meeting[0].first;
    for (int i = 1; i < N; ++i) {
        if (meeting[i].second >= end_time) {
            cnt++;
            end_time = meeting[i].first;
        }
    }
    cout << cnt << '\n';
    return 0;
}