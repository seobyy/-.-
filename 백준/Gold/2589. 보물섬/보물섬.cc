#include <iostream>
#include <queue>
#include <memory.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 50
using namespace std;

struct POS { int dis; int y, x; };

int N, M;
int maxLen;
char map[MAX_N + 5][MAX_N + 5];
bool visited[MAX_N + 5][MAX_N + 5];

const int dy[4] = {-1, 0, 1, 0};    // 북 동 남 서 
const int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    
    memset(visited, false, sizeof(visited));
    visited[y][x] = true;
    queue <POS> q;
    q.push({0, y, x});
    
    while (!q.empty()) {
        
        int d = q.front().dis;
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        if (d > maxLen) 
            maxLen = d;
        
        for (int i = 0; i < 4; ++i) {
            
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (map[ny][nx] == 'L' && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({d + 1, ny, nx});
            }
        }
    }
}

int main() {
    
    fastio;
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (map[i][j] == 'L')
                bfs(i, j);
        }
    }
    
    cout << maxLen << '\n';
    
    return 0;
}