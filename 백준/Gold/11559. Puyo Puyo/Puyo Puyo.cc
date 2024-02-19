#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

struct POS { int y, x; };

int ans;
char Map[13][7];
bool visited[13][7];

const int dy[4] = {-1, 0, 1, 0};    //  북 동 남 서 
const int dx[4] = {0, 1, 0, -1};

void input() {
    for (int i = 0; i < 12; ++i) {
        string str; cin >> str;
        for (int j = 0; j < 6; ++j) {
            Map[i][j] = str[j];
        }
    }
}

int cal_area(int y, int x) {
    char val = Map[y][x];
    queue <POS> q;
    q.push({y, x});
    visited[y][x] = true;
    int cnt = 0;
    
    while (!q.empty()) {
        int sy = q.front().y;
        int sx = q.front().x;
        q.pop();
        
        cnt++;
        for (int i = 0; i < 4; ++i) {
            int ny = sy + dy[i];
            int nx = sx + dx[i];
            
            if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6)
                continue;
            if (visited[ny][nx])
                continue;
            
            if (Map[ny][nx] == val) {
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    }
    
    if (cnt >= 4) {
        queue <POS> q;
        q.push({y, x});
        Map[y][x] = '.';
        
        while (!q.empty()) {
            int sy = q.front().y;
            int sx = q.front().x;
            q.pop();
            
            for (int i = 0; i < 4; ++i) {
                int ny = sy + dy[i];
                int nx = sx + dx[i];
                
                if (ny < 0 || ny >= 12 || nx < 0 || nx >= 6)
                    continue;
                    
                if (Map[ny][nx] == val) {
                    Map[ny][nx] = '.';
                    q.push({ny, nx});
                }
            }
        }
    }
    
    return cnt;
}

bool puyo() {
    memset(visited, false, sizeof(visited));
    bool can_puyo = false;
    for (int i = 0; i < 12; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (Map[i][j] != '.' && !visited[i][j]) {
                if (cal_area(i, j) >= 4) 
                    can_puyo = true;
            }
        }
    }
    
    return can_puyo;
}

void gravity() {
    for (int j = 0; j < 6; ++j) {
        for (int i = 10; i >= 0; --i) {
            if (Map[i][j] != '.') {
                for (int k = 11; k >= i + 1; --k) {
                    if (Map[k][j] == '.') {
                        Map[k][j] = Map[i][j];
                        Map[i][j] = '.';
                    }
                }
            }
        }
    }
}

void solve() {
    while (1)  {
        if (!puyo())
            break;
        ans++;
        gravity();
        /*
        for (int i = 0; i < 12; ++i) {
            for (int j = 0; j < 6; ++j)
                cout << Map[i][j];
            cout << '\n';
        }
        */
        
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