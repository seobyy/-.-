#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 105
using namespace std;

int M, N, K;
int cnt;
int map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];
vector <int> v;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

void bfs(int start_y, int start_x) {
    cnt++;
    int area_size = 1;
    visited[start_y][start_x] = true;
    queue <pair<int, int>> q;
    q.push({start_y, start_x});
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= M || nx < 0 || nx >= N)
                continue;
            if (!map[ny][nx] && !visited[ny][nx]) {
                q.push({ny, nx});
                visited[ny][nx] = true;
                area_size++;
            }
        }
    }
    
    v.push_back(area_size);
}

int main() {
    fastio;
    cin >> M >> N >> K;
    for (int i = 0; i < K; ++i) {
        int sX, sY, eX, eY;
        cin >> sX >> sY >> eX >> eY;
        
        for (int j = M - eY; j < M - sY; ++j) {
            for (int k = sX; k < eX; ++k) {
                map[j][k] = 1;
            }
        }
        
    }
    
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!map[i][j] && !visited[i][j])
                bfs(i, j);
        }
    }
    
    sort(v.begin(), v.end());
    
    cout << cnt << '\n';
    for (auto i : v) {
        cout << i << ' ';
    }
    
    return 0;

}