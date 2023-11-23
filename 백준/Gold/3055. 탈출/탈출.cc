#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_R 50
#define MAX_C 50
using namespace std;

typedef pair<int, int> pii;

struct POS { int tCnt; int y, x; };

int R, C;
int sY, sX;
int ans;
char map[2500][MAX_R + 5][MAX_C + 5];
bool visited[2500][MAX_R + 5][MAX_C + 5];
bool watered[2500];

const int dy[4] = {-1, 0, 1, 0};    // 북 동 남 서
const int dx[4] = {0, 1, 0, -1};

void pushWater(int t) {
    
    watered[t] = true;
    vector <pii> v;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            map[t][i][j] = map[t - 1][i][j];
            if (map[t][i][j] == '*') 
                v.push_back({i, j});
        }
    }
    
    for (auto i : v) {
        int y = i.first;
        int x = i.second;
        
        for (int j = 0; j < 4; ++j) {
            
            int ny = y + dy[j];
            int nx = x + dx[j];
            
            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                continue;
            if (map[t][ny][nx] == '.') 
                map[t][ny][nx] = '*';
        }
    }
}

void bfs() {
    
    visited[0][sY][sX] = true;
    queue <POS> q;
    q.push({0, sY, sX});
    
    while (!q.empty()) {
        
        int t = q.front().tCnt;
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        if (!watered[t + 1]) 
            pushWater(t + 1);
        
        for (int i = 0; i < 4; ++i) {
            
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= R || nx < 0 || nx >= C)
                continue;
            if (map[t + 1][ny][nx] == '.' && !visited[t + 1][ny][nx]) {
                visited[t + 1][ny][nx] = true;
                q.push({t + 1, ny, nx});
            }
            
            else if (map[t + 1][ny][nx] == 'D') {
                ans = t + 1;
                return;
            }
        }
    }
}

int main() {
    
    fastio;
    cin >> R >> C;
    
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> map[0][i][j];
            if (map[0][i][j] == 'S') {
                sY = i; sX = j;
                map[0][i][j] = '.';
            }
        }
    }
    
    bfs();
    
    if (!ans)
        cout << "KAKTUS" << '\n';
    else
        cout << ans << '\n';
        
    return 0;
}