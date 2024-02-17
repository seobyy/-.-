#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 600
#define MAX_M 600
using namespace std;

struct POS { int y, x; };

int N, M;
int ans;
char Map[MAX_N + 5][MAX_M + 5];
bool visited[MAX_N + 5][MAX_M + 5];

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

queue <POS> q;

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        string str; cin >> str;
        for (int j = 0; j < M; ++j) {
            Map[i][j] = str[j];
            if (Map[i][j] == 'I') {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
}

void solve() {
    
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (visited[ny][nx])
                continue;
            if (Map[ny][nx] == 'X')
                continue;
                
            visited[ny][nx] = true;
            q.push({ny, nx});
            if (Map[ny][nx] == 'P')
                ans++;
            
        }
    }
}

void output() {
    if (!ans)
        cout << "TT" << '\n';
    else
        cout << ans << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}