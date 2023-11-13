#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
#define MAX_K 10
using namespace std;

struct POS {int dis; int y, x; int breakCnt;};

int N, M, K;
int ans = -1;
int map[MAX_N][MAX_N];
bool visited[MAX_K + 1][MAX_N][MAX_N];

const int dy[4] = {-1, 0, 1, 0};    // 북 동 남 서 
const int dx[4] = {0, 1, 0, -1};

void bfs() {
    
    queue <POS> q;
    q.push({1, 0, 0, 0});
    visited[0][0][0] = true;
    
    while (!q.empty()) {
        
        int d = q.front().dis;
        int y = q.front().y;
        int x = q.front().x;
        int k = q.front().breakCnt;
        q.pop();
        
        if (y == N - 1 && x == M - 1) {
            ans = d;
            break;
        }
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (visited[k][ny][nx])
                continue;
            
            if (!map[ny][nx]) {
                visited[k][ny][nx] = true;
                q.push({d + 1, ny, nx, k});
            }
                
            else {
                if (k < K && !visited[k + 1][ny][nx]) {
                    visited[k + 1][ny][nx] = true;
                    q.push({d + 1, ny, nx, k + 1});
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
        for (int j = 0; j < M; ++j) {
            map[i][j] = str[j] - '0';
        }
    }
    
    bfs();
    
    cout << ans << '\n';
    
    return 0;
}