#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 10
using namespace std;

struct POS { int y, x; };

int N, M, H;
int sy, sx;
int len;
int ans;
int Map[MAX_N + 5][MAX_N + 5];
bool visited[15];
vector <POS> v;

void input() {
    cin >> N >> M >> H;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> Map[i][j];
            if (Map[i][j] == 1) {
                sy = i; sx = j;
            }
            else if (Map[i][j] == 2)
                v.push_back({i, j});
        }
    }
    len = v.size();
}

void selNext(int y, int x, int hp, int cnt) {
    
    int dis = abs(y - sy) + abs(x - sx);
    if (dis <= hp) 
        ans = max(ans, cnt);
    
    for (int i = 0; i < len; ++i) {
        int ny = v[i].y; int nx = v[i].x;
        int dis = abs(ny - y) + abs(nx - x);
        if (dis <= hp && !visited[i]) {
            visited[i] = true;
            selNext(ny, nx, hp - dis + H, cnt + 1);
            visited[i] = false;
        }
    }
}

void output() {
    cout << ans << '\n';
}


void solve() {
    selNext(sy, sx, M, 0);
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}