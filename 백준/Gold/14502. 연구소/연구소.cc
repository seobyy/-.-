#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 9
#define MAX_WALL 64
using namespace std;

int N, M;
int map[MAX_N][MAX_N];
int copy_map[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

const int dx[4] = {1, 0, -1, 0};    // 동 남 서 북
const int dy[4] = {0, 1, 0, -1};

struct POS {
    int y;
    int x;
};

vector <POS> wall;
vector <POS> virus;

void SpreadVirus(int start_y, int start_x) {
    
    queue <POS> q;
    q.push({start_y, start_x});
    visited[start_y][start_x] = true;
    
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
                
            if (!visited[ny][nx] && !copy_map[ny][nx]) {
                copy_map[ny][nx] = 2;
                q.push({ny, nx});
                visited[ny][nx] = true;
            }    
        }
    }
}

int Count() {
    int ret = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!copy_map[i][j])
                ret++;
        }
    } 
    return ret;
}

int main() {
    fastio;
    cin >> N >> M;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> map[i][j];
            if (!map[i][j]) 
                wall.push_back({i, j});
            if (map[i][j] == 2)
                virus.push_back({i, j});
        }
    }
    
    int wall_cnt = wall.size();
    vector <int> v1;
    vector <int> v2;
    
    for (int i = 0; i < wall_cnt; ++i) {
        v1.push_back(i);
    }
    
    for (int i = 0; i < 3; ++i) {
        v2.push_back(1);
    }
    for (int i = 0; i < wall_cnt - 3; ++i) {
        v2.push_back(0);
    }
    sort(v2.begin(), v2.end());
    int max_cnt = 0;
    
    do {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j)
                copy_map[i][j] = map[i][j];
        }
        memset(visited, false, sizeof(visited));
        
        for (int i = 0; i < wall_cnt; ++i) {
            if (v2[i] == 1) {
                int y = wall[v1[i]].y;
                int x = wall[v1[i]].x;
                copy_map[y][x] = 1;
            }
        }
        
        for (auto i : virus) {
            SpreadVirus(i.y, i.x);
        }
        
        int cnt = Count();
        if (cnt > max_cnt)
            max_cnt = cnt;
        
    } while(next_permutation(v2.begin(), v2.end()));
    
    cout << max_cnt << '\n';
    
    return 0;
}