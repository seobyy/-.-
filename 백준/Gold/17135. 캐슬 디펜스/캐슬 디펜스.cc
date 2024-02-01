#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 15
#define MAX_M 15
using namespace std;

struct ENEM { int dis; int y, x; };
struct POS { int y, x; };
struct cmp {
    bool operator()(ENEM a, ENEM b) {
        if (a.dis == b.dis)
            return a.x > b.x;
        return a.dis > b.dis;
    }
};

const int dy[4] = {-1, 0, 1, 0};    // 북 동 남 서  
const int dx[4] = {0, 1, 0, -1};

int N, M, D;
int ans;
int Map[MAX_N + 5][MAX_M + 5];
int cMap[MAX_N + 5][MAX_M + 5];
bool visited[MAX_N + 5][MAX_M + 5];

int archer[3];

void input() {
    cin >> N >> M >> D;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cin >> Map[i][j];
    }
}

void castleDefense() {
    int cnt = 0;
    int turn = -1;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cMap[i][j] = Map[i][j];
    }
    
    while (++turn <= N) {
        priority_queue <ENEM, vector<ENEM>, cmp> pq[3];
        for (int i = 0; i < 3; ++i) {
            queue <ENEM> q;
            q.push({0, N - turn, archer[i]});
            memset(visited, false, sizeof(visited));
            visited[N - turn][archer[i]] = true;
            
            while (!q.empty()) {
                int d = q.front().dis;
                int y = q.front().y;
                int x = q.front().x;
                q.pop();
                
                
                if (d == D)
                    continue;
                
                for (int j = 0; j < 4; ++j) {
                    int ny = y + dy[j];
                    int nx = x + dx[j];
                
                    if (ny < 0 || ny >= N - turn || nx < 0 || nx >= M)
                        continue;
                    if (visited[ny][nx])
                        continue;
                    
                    visited[ny][nx] = true;
                    q.push({d + 1, ny, nx});
                    
                    if (cMap[ny][nx]) 
                        pq[i].push({d + 1, ny, nx});
                }
            }
        }
        
        for (int i = 0; i < 3; ++i) {
            if (!pq[i].empty()) {
                int y = pq[i].top().y;
                int x = pq[i].top().x;
                if (cMap[y][x]) {
                    cMap[y][x] = 0;
                    cnt++;
                }
            }
        }
    }
    ans = max(ans, cnt);
}

void selectArcher(int index, int cnt) {
    if (cnt == 3) {
        castleDefense();
        return;
    }
    
    for (int i = index; i < M; ++i) {
        archer[cnt] = i;
        selectArcher(i + 1, cnt + 1);
    }
    
}

void solve() {
    selectArcher(0, 0);
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