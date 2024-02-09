#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 500
#define MAX_M 500
#define INF 1e9 + 9
using namespace std;

int N, M, B;
int minH = 257, maxH = -1;
int ans1 = INF, ans2;
int Map[MAX_N + 5][MAX_M + 5];

void input() {
    cin >> N >> M >> B;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> Map[i][j];
            minH = min(minH, Map[i][j]);
            maxH = max(maxH, Map[i][j]);
        }
    }
}

void solve() {
    
    for (int h = minH; h <= maxH; ++h) {
        
        int cnt = 0;
        bool canBuild = true;
        int inven = B;
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (Map[i][j] > h) {
                    int gap = Map[i][j] - h;
                    inven += gap;
                    cnt += 2 * gap;
                }
            }
        }
        
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (Map[i][j] < h) {
                    int gap = h - Map[i][j];
                    inven -= gap;
                    cnt += gap;
                }
                if (inven < 0) {
                    canBuild = false;
                    break;
                }
            }
            if (!canBuild)
                break;
        }
        if (canBuild) {
            if (cnt <= ans1) {
                ans1 = cnt;
                ans2 = h;
            }
        }
    }
}

void output() {
    cout << ans1 << ' ' << ans2 << '\n';
}


int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}