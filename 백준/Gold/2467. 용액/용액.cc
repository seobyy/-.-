#include <iostream>
#include <algorithm>
#include <cstdlib>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100'000
#define INF 2'147'000'000
using namespace std;

int N;
int min_gap = INF;
int ans1, ans2;
int target;
int liquid[MAX_N + 5];

void solve() {
    
    int s = 0; int e = N - 1;
    
    while (s < e) {
        int gap = liquid[s] + liquid[e];
        if (abs(gap) < min_gap) {
            min_gap = abs(gap);
            ans1 = liquid[s]; ans2 = liquid[e];
        }
        
        if (gap <= 0)
            s++;
        else
            e--;
    }
}

int main() {
    
    fastio;
    cin >> N;
    
    for (int i = 0; i < N; ++i) {
        cin >> liquid[i];
    }
    
    solve();

    cout << ans1 << ' ' << ans2 << '\n';
    
    return 0;
}