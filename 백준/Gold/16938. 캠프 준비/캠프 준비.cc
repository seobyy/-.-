#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 15
#define INF 2'147'000'000
using namespace std;

int N, L, R, X;
int ans;
int A[MAX_N + 5];
int problem[MAX_N + 5];

void input() {
    cin >> N >> L >> R >> X;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
}

void selProblem(int index, int cnt) {
    if (index == N) {
        if (cnt >= 2) {
            int sum = 0;
            for (int i = 0; i < cnt; ++i) {
                sum += problem[i];
            }
            
            int m = *min_element(problem, problem + cnt);
            int M = *max_element(problem, problem + cnt);
            //cout << sum << ' ' << m << ' ' << M << '\n';
            if (sum >= L && sum <= R && (M - m) >= X)
                ans++;
        }
        return;
    }
    problem[cnt] = A[index];
    selProblem(index + 1, cnt + 1);
    selProblem(index + 1, cnt);
}

void solve() {
    selProblem(0, 0);
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