#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 50
#define INF 2'147'000'000
using namespace std;

struct POS { int y, x; };

int N, M;
int len;
int ans = INF;
int Map[MAX_N + 5][MAX_N + 5];
int tmp_map[MAX_N + 5][MAX_N + 5];
bool visited[MAX_N + 5][MAX_N + 5];
bool check[MAX_N + 5][MAX_N + 5];

int virus[15];

const int dy[4] = {-1, 0, 1, 0};    // 북 동 남 서 
const int dx[4] = {0, 1, 0, -1};

vector <POS> v;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> Map[i][j];
            if (Map[i][j] == 2)
                v.push_back({i, j});
        }
    }
    len = v.size();
}

void play_virus() {
    
    queue <POS> q;
    memset(tmp_map, 0, sizeof(tmp_map));
    memset(visited, false, sizeof(visited));
    memset(check, false, sizeof(check));
    
    for (int i = 0; i < M; ++i) {
        int y = v[virus[i]].y; int x = v[virus[i]].x;
        tmp_map[y][x] = 2;
        q.push({y, x});
        visited[y][x] = true;
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (Map[i][j] != 2)
                tmp_map[i][j] = Map[i][j];
            else {
                if (!tmp_map[i][j]) {
                    tmp_map[i][j] = -1;
                    check[i][j] = true;
                }
            }
        }
    }

    int max_t = 0;
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        int num = tmp_map[y][x];
        
        if (!check[y][x])
            max_t = max(max_t, num);
        
        for (int i = 0; i < 4; ++i) {
            
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (visited[ny][nx])
                continue;
            
            if (!tmp_map[ny][nx] || tmp_map[ny][nx] == -1) {
                tmp_map[ny][nx] = num + 1;
                q.push({ny, nx});
                visited[ny][nx] = true;
            }
        }
    } 
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!tmp_map[i][j]) 
                return;            
        }
    }
    
    ans = min(ans, max_t - 2);
}

void sel_virus(int index, int cnt) {
    
    if (cnt == M) {
        play_virus();
        return;
    }
    
    for (int i = index; i < len; ++i) {
        virus[cnt] = i;
        sel_virus(i + 1, cnt + 1);
    }
}

void solve() {
    sel_virus(0, 0);
}

void output() {
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}