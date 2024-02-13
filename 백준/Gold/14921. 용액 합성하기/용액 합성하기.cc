#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100'000
#define INF 2'147'000'000
using namespace std;

int N;
int min_gap = INF;
int ans;
int A[MAX_N + 5];

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
}

void solve() {
    int s = 0; int e = N - 1;
    while (s < e) {
        int gap = A[s] + A[e];
        if (abs(gap) < min_gap) {
            min_gap = abs(gap);
            ans = gap;
        }
        
        if (gap >= 0) {
            e--;
        }
        else 
            s++;
    }
}

void output() {
    cout << ans << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}