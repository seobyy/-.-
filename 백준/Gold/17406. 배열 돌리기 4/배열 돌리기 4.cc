#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 50
#define MAX_M 50
#define INF 2'147'000'000
using namespace std;

struct OPER { int r, c, s; };

vector <OPER> v;
int order[7];
bool selected[7];

int N, M, K;
int ans = INF;
int A[MAX_N + 5][MAX_M + 5];
int tmp_A[MAX_N + 5][MAX_N + 5];

void input() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j)
            cin >> tmp_A[i][j];
    }
    for (int i = 0; i < K; ++i) {
        int r, c, s; cin >> r >> c >> s;
        v.push_back({r, c, s});
    }
}

void print_array() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j)
            cout << A[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void turn_array() {
    
    memmove(A, tmp_A, sizeof(A));
    
    for (int d = 0; d < K; ++d) {
        int num = order[d];
        int r = v[num].r;
        int c = v[num].c;
        int s = v[num].s;
        
        for (int k = s; k > 0; --k) {
            int sy = r - k, sx = c - k;
            int ey = r + k, ex = c + k;
        
            int tmp = A[sy][ex];
        
            // 윗변
            for (int j = ex; j > sx; --j) {
                A[sy][j] = A[sy][j - 1];
            }
        
            // 왼쪽 변
            for (int i = sy; i < ey; ++i) {
                A[i][sx] = A[i + 1][sx];
            }
        
            // 아랫 변 
            for (int j = sx; j < ex; ++j) {
                A[ey][j] = A[ey][j + 1];
            }
        
            // 오른쪽 변
            for (int i = ey; i > sy; --i) {
                if (i == sy + 1)
                    A[i][ex] = tmp;
                else
                    A[i][ex] = A[i - 1][ex];
            }
        }
    }
    
    for (int i = 1; i <= N; ++i) {
        int sum = 0;
        for (int j = 1; j <= M; ++j)
            sum += A[i][j];
        ans = min(ans, sum);
    }
}

void sel_order(int cnt) {
    
    if (cnt == K) {
        turn_array();
        return;
    }
    
    for (int i = 0; i < K; ++i) {
        if (!selected[i]) {
            order[cnt] = i;
            selected[i] = true;
            sel_order(cnt + 1);
            selected[i] = false;
        }
    }
}

void solve() {
    sel_order(0);
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