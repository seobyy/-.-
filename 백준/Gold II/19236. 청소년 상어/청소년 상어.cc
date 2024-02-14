#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define SHARK 20
using namespace std;

struct FISH { bool exist; int y, x; int dir; };
FISH F[17];

int ans;
int Map[5][5];

const int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
const int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

void input() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int n, d; cin >> n >> d;
            Map[i][j] = n;
            F[n] = {true, i, j, d};
        }
    }
}

void play_shark(int y, int x, int sum) {
    
    //cout << y << ' ' << x << ' ' << sum << '\n';
    
    int n = Map[y][x];
    int dir = F[n].dir;
    F[n].exist = false;
    Map[y][x] = SHARK;
    
    // 1. 물고기 자리 이동 
    for (int i = 1; i <= 16; ++i) {
        if (F[i].exist) {
            
            int fy = F[i].y;
            int fx = F[i].x;
            for (int j = 0; j < 8; ++j) {
                int d = (F[i].dir + j) % 8;
                if (!d) d = 8;
                
                int ny = fy + dy[d];
                int nx = fx + dx[d];
                
                if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
                    continue;
                if (Map[ny][nx] == SHARK)
                    continue;
                
                if (Map[ny][nx]) {
                    int s = Map[ny][nx];
                    Map[ny][nx] = i;
                    Map[fy][fx] = s;
                    F[i] = {true, ny, nx, d};
                    F[s] = {true, fy, fx, F[s].dir};
                    break;
                }
                else if (!Map[ny][nx]) {
                    Map[ny][nx] = i;
                    Map[fy][fx] = 0;
                    F[i] = {true, ny, nx, d};
                    break;
                }
            }
        }
    }
    
    int tmp[5][5];
    FISH tmp2[17];
    memmove(tmp, Map, sizeof(tmp));
    memmove(tmp2, F, sizeof(tmp2));
    
    // 2. 상어 자리 이동
    int c = 1;
    bool can_eat = false;
    while (1) {
        int ny = y + dy[dir] * c;
        int nx = x + dx[dir] * c;
        c++;
        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
            break;
        if (!Map[ny][nx])
            continue;
            
        can_eat = true;
        
        Map[y][x] = 0;
        play_shark(ny, nx, sum + n);
        memmove(Map, tmp, sizeof(Map));
        memmove(F, tmp2, sizeof(F));
    }
    
    if (!can_eat)
        ans = max(ans, sum + n);
}

void solve() {
    play_shark(0, 0, 0);
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