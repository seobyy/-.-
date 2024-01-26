#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 50
#define INF 2'147'000'000
using namespace std;

struct POS { int T; int y, x;};

const int dy[4] = {-1, 0, 1, 0};    // 북 동 남 서  
const int dx[4] = {0, 1, 0, -1};

int N, M;
int blank;
int ans = INF;
int Map[MAX_N + 5][MAX_N + 5];
int newMap[MAX_N + 5][MAX_N + 5];
bool visited[MAX_N + 5][MAX_N + 5];

vector <POS> v;
bool selected[2505];
int virusPos[2505];

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> Map[i][j];
            if (Map[i][j] == 2) 
                v.push_back({0, i, j});
        }
    }
}

void Virus() {
    memset(newMap, 0, sizeof(newMap));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (Map[i][j] != 2)
                newMap[i][j] = Map[i][j];
        }
    }
    queue <POS> q;
    for (int i = 0; i < M; ++i) {
        int y = v[virusPos[i]].y; 
        int x = v[virusPos[i]].x;
        newMap[y][x] = 2;
        q.push({0, y, x});
    }
    
    int maxT = 0;
    while (!q.empty()) {
        int t = q.front().T;
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        maxT = max(maxT, t);
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (visited[ny][nx])
                continue;
            
            if (!newMap[ny][nx]) {
                newMap[ny][nx] = t + 1;
                visited[ny][nx] = true;
                q.push({t + 1, ny, nx});
            }
        }
    }
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (!newMap[i][j]) 
                return;
        }
    }
    
    ans = min(ans, maxT);
}

void selectBlank(int index, int cnt) {
    if (cnt == M) {
        Virus();
        return;
    }
    
    for (int i = index; i < blank; ++i) {
        if (!selected[i]) {
            selected[i] = true;
            virusPos[cnt] = i;
            selectBlank(i + 1, cnt + 1);
            selected[i] = false;
        }
    }
}

void solve() {
    blank = v.size();
    selectBlank(0, 0);
    if (ans == INF)
        ans = -1;
}

void output() {
    cout << ans << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}