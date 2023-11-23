#include <iostream>
#include <memory.h>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_W 50
#define MAX_H 50
using namespace std;

typedef pair<int, int> pii;

int w, h;
int ans;
int map[MAX_W + 5][MAX_H + 5];
bool visited[MAX_W + 5][MAX_H + 5];

const int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

void bfs(int y, int x) {
    
    ans++;
    visited[y][x] = true;
    queue <pii> q;
    q.push({y, x}); 
    
    while (!q.empty()) {
        
        int sy = q.front().first;
        int sx = q.front().second;
        q.pop();
        
        for (int i = 0; i < 8; ++i) {
            int ny = sy + dy[i];
            int nx = sx + dx[i];
            
            if (ny < 0 || ny >= h || nx < 0 || nx >= w)
                continue;
            if (!map[ny][nx] || visited[ny][nx])
                continue;
                
            visited[ny][nx] = true;
            q.push({ny, nx});
        }
    }
}

int main() {
    
    fastio;
    while (1) {
    
        cin >> w >> h;
        if (!w && !h)
            break;
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                cin >> map[i][j];
            }
        }
        memset(visited, false, sizeof(visited));
        ans = 0;
        
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (map[i][j] && !visited[i][j]) 
                    bfs(i, j);
            }
        }
        
        cout << ans << '\n';
    }
    
    return 0;
}