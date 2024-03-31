#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct HEATER { int y, x; };
struct POS { int power; int y, x; };

// 0 오 왼 위 아 
const int dy[5] = {0, 0, 0, -1, 1};
const int dx[5] = {0, 1, -1, 0, 0};

int R, C, K, W;
int ans;

int Map[25][25];
int heater[25][25];
bool visited[25][25];
vector <HEATER> fan_heater;

bool target[25][25];
bool wall_row[25][25];  // 아래 -> 위 방향의 wall
bool wall_col[25][25];  // 왼 -> 오 방향의 wall

void print_map() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j)
            cout << Map[i][j] << ' ';
        cout << '\n';
    }
    cout << '\n';
}

void input() {
    cin >> R >> C >> K;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            int x; cin >> x;
            if (x == 5) target[i][j] = true;
            else if (x)  {
                fan_heater.push_back({i, j});
                heater[i][j] = x;
            }
        }
    }
    cin >> W;
    for (int i = 0; i < W; ++i) {
        int y, x, t; cin >> y >> x >> t;
        if (!t) wall_row[y][x] = true;
        else wall_col[y][x] = true;
    }
}

bool is_in_map(int y, int x) {
    if (y < 1 || y > R || x < 1 || x > C)
        return false;
    else
        return true;
}

void fan_heater_move() {
    
    for (auto i : fan_heater) {
        int cy = i.y; int cx = i.x;
        int dir = heater[cy][cx];
        
        int ny = cy + dy[dir]; int nx = cx + dx[dir];
        
        queue <POS> q;
        q.push({5, ny, nx});
        
        memset(visited, false, sizeof(visited));
        
        while (!q.empty()) {
            
            int p = q.front().power;
            int y = q.front().y;
            int x = q.front().x;
            q.pop();
            
            if (visited[y][x]) continue;
            visited[y][x] = true;
            Map[y][x] += p;
            
            if (p == 1) continue;
            
            
            // 오 
            if (dir == 1) {
                int ny = 0; int nx = x + 1;
                for (int k = 0; k < 3; ++k) {
                    if (!k) {
                        ny = y - 1;
                        if (is_in_map(ny, nx)) {
                            if (!wall_row[y][x] && !wall_col[y - 1][x])
                                q.push({p - 1, ny, nx});
                        }
                    }
                    else if (k == 1) {
                        ny = y;
                        if (is_in_map(ny, nx)) {
                            if (!wall_col[y][x])
                                q.push({p - 1, ny, nx});
                        }
                    }
                    else {
                        ny = y + 1;
                        if (is_in_map(ny, nx)) {
                            if (!wall_row[y + 1][x] && !wall_col[y + 1][x])
                                q.push({p - 1, ny, nx});
                        }
                    }
                }
            }
            // 왼
            else if (dir == 2) {
                int ny = 0; int nx = x - 1;
                for (int k = 0; k < 3; ++k) {
                    if (!k) {
                        ny = y - 1;
                        if (is_in_map(ny, nx)) {
                            if (!wall_row[y][x] && !wall_col[y - 1][x - 1])
                                q.push({p - 1, ny, nx});
                        }
                    }
                    else if (k == 1) {
                        ny = y;
                        if (is_in_map(ny, nx)) {
                            if (!wall_col[y][x - 1])
                                q.push({p - 1, ny, nx});
                        }
                    }
                    else {
                        ny = y + 1;
                        if (is_in_map(ny, nx)) {
                            if (!wall_row[y + 1][x] && !wall_col[y + 1][x - 1])
                                q.push({p - 1, ny, nx});
                        }
                    }
                }
            }
            // 위
            else if (dir == 3) {
                int ny = y - 1; int nx = 0;
                for (int k = 0; k < 3; ++k) {
                    if (!k) {
                        nx = x - 1;
                        if (is_in_map(ny, nx)) {
                            if (!wall_col[y][x - 1] && !wall_row[y][x - 1])
                                q.push({p - 1, ny, nx});
                        }
                    }
                    else if (k == 1) {
                        nx = x;
                        if (is_in_map(ny, nx)) {
                            if (!wall_row[y][x])
                                q.push({p - 1, ny, nx});
                        }
                    }
                    else {
                        nx = x + 1;
                        if (is_in_map(ny, nx)) {
                            if (!wall_col[y][x] && !wall_row[y][x + 1])
                                q.push({p - 1, ny, nx});
                        }
                    }
                }
            }
            // 아 
            else {
                int ny = y + 1; int nx = 0;
                for (int k = 0; k < 3; ++k) {
                    if (!k) {
                        nx = x - 1;
                        if (is_in_map(ny, nx)) {
                            if (!wall_col[y][x - 1] && !wall_row[y + 1][x - 1])
                                q.push({p - 1, ny, nx});
                        }
                    }
                    else if (k == 1) {
                        nx = x;
                        if (is_in_map(ny, nx)) {
                            if (!wall_row[y + 1][x])
                                q.push({p - 1, ny, nx});
                        }
                    }
                    else {
                        nx = x + 1;
                        if (is_in_map(ny, nx)) {
                            if (!wall_col[y][x] && !wall_row[y + 1][x + 1])
                                q.push({p - 1, ny, nx});
                        }
                    }
                }
            }
        }
        //print_map();
    }
}

void temp_adjusted() {
    
    int tmp[25][25];
    memmove(tmp, Map, sizeof(tmp));
    
    // 1. 세로방향
    for (int j = 1; j <= C; ++j) {
        for (int i = 2; i <= R; ++i) {
            if (wall_row[i][j]) continue;
            
            if (Map[i][j] >= Map[i - 1][j]) {
                int gap = (Map[i][j] - Map[i - 1][j]) / 4;
                tmp[i][j] -= gap;
                tmp[i - 1][j] += gap;
            }
            else {
                int gap = (Map[i - 1][j] - Map[i][j]) / 4;
                tmp[i][j] += gap;
                tmp[i - 1][j] -= gap;
            }
        }
    }
    // 2. 가로방향
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j < C; ++j) {
            if (wall_col[i][j]) continue;
            
            if (Map[i][j] >= Map[i][j + 1]) {
                int gap = (Map[i][j] - Map[i][j + 1]) / 4;
                tmp[i][j] -= gap;
                tmp[i][j + 1] += gap;
            }
            else {
                int gap = (Map[i][j + 1] - Map[i][j]) / 4;
                tmp[i][j] += gap;
                tmp[i][j + 1] -= gap;
            }
        }
    }
    
    memmove(Map, tmp, sizeof(Map));
}

void edge_decrease() {
    for (int i = 1; i < R; ++i) {
        if (Map[i][1] >= 1) Map[i][1]--;
    }
    for (int j = 1; j < C; ++j) {
        if (Map[R][j] >= 1) Map[R][j]--;
    }
    for (int i = R; i > 1; --i) {
        if (Map[i][C] >= 1) Map[i][C]--;
    }
    for (int j = C; j > 1; --j) {
        if (Map[1][j] >= 1) Map[1][j]--;
    }
}

bool ans_check() {
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (target[i][j]) {
                if (Map[i][j] < K)
                    return false;
            }
        }
    }
    return true;
}

void solve() {
    int chocolate = 0;
    while (chocolate <= 100) {
        fan_heater_move();
        //print_map();
        temp_adjusted();
        //print_map();
        edge_decrease();
        //print_map();
        chocolate++;
        if (ans_check()) {
            //print_map();
            ans = chocolate;
            return;
        }
    }
    ans = chocolate;
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