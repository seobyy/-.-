#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
#define MAX_M 1000
using namespace std;

struct POS { int y, x; };
const int mod = 10;

int N, M;
int areaCnt;
int MAP[MAX_N + 5][MAX_M + 5];
int visited[MAX_N + 5][MAX_N + 5];
unordered_map <int, int> areaDic;

const int dy[4] = {-1, 1, 0, 0};    // 상 하 좌 우
const int dx[4] = {0, 0, -1, 1};

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        for (int j = 0; j < M; ++j) {
            MAP[i][j] = str[j] - '0';
        }
    }
}

void bfs(int y, int x) {
    int cnt = 0;
    areaCnt++;
    visited[y][x] = areaCnt;
    
    queue <POS> q;
    q.push({y, x});
    
    while (!q.empty()) {
        int sy = q.front().y;
        int sx = q.front().x;
        q.pop();
        
        cnt++;
        for (int i = 0; i < 4; ++i) {
            int ny = sy + dy[i];
            int nx = sx + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
                
            if (!visited[ny][nx] && !MAP[ny][nx]) {
                visited[ny][nx] = areaCnt;
                q.push({ny, nx});
            }
        }
    }
    areaDic[areaCnt] = cnt;
}

void calArea() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (!MAP[i][j] && !visited[i][j]) {
                bfs(i, j);
            }
        }
    }
}

void solve() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (MAP[i][j]) {
                int ans = 1;
                set <int> s;
                for (int k = 0; k < 4; ++k) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];
                    
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                        continue;
                    if (!MAP[ny][nx])
                        s.insert(visited[ny][nx]);
                }
                for (auto i : s) {
                    ans += areaDic[i];
                }
                
                cout << ans % mod;
            }
            else
                cout << 0;
        }
        cout << '\n';
    }
}

int main() {
    
    fastio;
    input();
    calArea();
    solve();
    /*
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cout << visited[i][j];
        cout << '\n';
    }
    */
    
    return 0;
}