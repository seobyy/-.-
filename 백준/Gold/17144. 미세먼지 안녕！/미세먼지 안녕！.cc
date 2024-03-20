#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_R 50
#define MAX_C 50
using namespace std;

int R, C, T;
int ay;
int ans;
int Map[MAX_R + 5][MAX_C + 5];

const int dy[4] = {-1, 0, 1, 0};    // 북 동 남 서  
const int dx[4] = {0, 1, 0, -1};

void input() {
    cin >> R >> C >> T;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> Map[i][j];
            if (Map[i][j] == -1 && !ay) 
                ay = i;
        }
    }
}

void move_dust() {
    
    int tmp[MAX_R + 5][MAX_C + 5];
    memset(tmp, 0, sizeof(tmp));
    memmove(tmp, Map, sizeof(tmp));
    
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (Map[i][j] && Map[i][j] != -1) {
                
                int carry = Map[i][j] / 5;
                
                
                for (int d = 0; d < 4; ++d) {
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    
                    if (ny < 1 || ny > R || nx < 1 || nx > C)
                        continue;
                    if (Map[ny][nx] == -1)
                        continue;
                    
                    tmp[ny][nx] += carry;
                    tmp[i][j] -= carry;
                    
                }
            }
        }
    }
    
    memmove(Map, tmp, sizeof(tmp));
}

void air_cleaner() {
    
    //위, 왼
    for (int i = ay - 1; i > 1; --i) {
        Map[i][1] = Map[i - 1][1];
    }
    //위, 위
    for (int j = 1; j < C; ++j) {
        Map[1][j] = Map[1][j + 1];
    }
    //위, 오
    for (int i = 1; i < ay; ++i) {
        Map[i][C] = Map[i + 1][C];
    }
    //위, 아
    for (int j = C; j > 1; --j) {
        if (j == 2)
            Map[ay][j] = 0;
        else
            Map[ay][j] = Map[ay][j - 1];
    }    
    
    //아, 왼
    for (int i = ay + 2; i < R; ++i) {
        Map[i][1] = Map[i + 1][1];
    }
    //아, 아
    for (int j = 1; j < C; ++j) {
        Map[R][j] = Map[R][j + 1];
    }    
    //아, 오
    for (int i = R; i > ay + 1; --i) {
        Map[i][C] = Map[i - 1][C];
    }
    //아, 위
    for (int j = C; j >= 2; --j) {
        if (j == 2)
            Map[ay + 1][j] = 0;
        else
            Map[ay + 1][j] = Map[ay + 1][j - 1];
    }    
    
}

/*
void print_array() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j)
            cout << Map[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}
*/

void solve() {
    while (T--) {
        move_dust();
        //print_array();
        air_cleaner();
        //print_array();
    }
    
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (Map[i][j] != -1)
                ans += Map[i][j];
        }
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