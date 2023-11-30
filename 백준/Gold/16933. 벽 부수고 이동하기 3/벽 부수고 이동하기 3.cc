#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
#define MAX_M 1000
#define MAX_K 10
using namespace std;

struct POS {
    int dis;
    int breakCnt;
    int y, x;
    bool isNight;
};

int N, M, K;
int ans = -1;
int map[MAX_N + 5][MAX_M + 5];
bool visited[2][MAX_K + 1][MAX_N + 5][MAX_M + 5];

const int dy[5] = {0, -1, 0, 1, 0};    // 이동x 북 동 남 서
const int dx[5] = {0, 0, 1, 0, -1};

void bfs() {
    
    visited[0][0][0][0] = true;
    queue <POS> q;
    q.push({1, 0, 0, 0, false});
    
    while (!q.empty()) {
        
        int d = q.front().dis;
        int b = q.front().breakCnt;
        int y = q.front().y;
        int x = q.front().x;
        bool isNight = q.front().isNight;
        q.pop();
        
        //cout << d << ' ' << b << ' ' << y << ' ' << x << ' ' << isNight << '\n';
        
        if (y == N - 1 && x == M - 1) {
            ans = d;
            break;
        }
        
        for (int i = 0; i < 5; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            
            if (!map[ny][nx] && !visited[!isNight][b][ny][nx]) {
                visited[!isNight][b][ny][nx] = true;
                q.push({d + 1, b, ny, nx, !isNight});
            }
            
            else if (map[ny][nx] == 1) {
                // 1. 벽을 부술 경우
                if (!isNight && !visited[!isNight][b + 1][ny][nx] && b + 1 <= K) {
                    visited[!isNight][b + 1][ny][nx] = true;
                    q.push({d + 1, b + 1, ny, nx, !isNight});
                }
                // 2. 이미 부순 벽일경우
                else if (isNight && visited[1][b][ny][nx] && !visited[0][b][ny][nx]) {
                    visited[0][b][ny][nx] = true;
                    q.push({d + 1, b, ny, nx, !isNight});
                }
                
            }
        }
    }
}

int main() {
    
    fastio;
    cin >> N >> M >> K;
    
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j) 
            map[i][j] = str[j] - '0';
    }
    
    bfs();
    
    cout << ans << '\n';
    
    return 0;
}