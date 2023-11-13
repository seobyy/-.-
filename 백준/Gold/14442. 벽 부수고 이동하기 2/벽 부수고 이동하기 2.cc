#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int N,M,K;
char arr[MAX][MAX];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue<tuple<int,int,int,int>> q;
int visited[MAX][MAX][10]; // 현재까지 부순 벽의 수
int ans = 987654321;

// BFS이므로 이미 방문한 곳에 뒤늦게 방문했다면 기존보다 절대로 더 빠른 경로가 아니다.
int bfs() {
    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        int x = get<0>(cur);
        int y = get<1>(cur);
        int cnt = get<2>(cur);
        int block = get<3>(cur);
        if (x == N-1 && y == M-1) {
            return cnt;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }
            if (visited[nx][ny][block]) {
                continue;
            }
            if (arr[nx][ny] == '0') {
                visited[nx][ny][block] = 1;
                q.push({nx, ny, cnt+1, block});
            }
            else if (arr[nx][ny] == '1' && block + 1 <= K) {
                visited[nx][ny][block + 1] = 1;
                q.push({nx, ny, cnt+1, block+1});
            }
        }
    }
    return -1;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    q.push({0,0,1,0});
    cout << bfs();
    return 0;
}