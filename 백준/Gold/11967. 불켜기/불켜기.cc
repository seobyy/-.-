#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100
using namespace std;

struct POS { int y, x; };

int N, M;
int ans;

int Map[MAX_N + 5][MAX_N + 5];
bool switch_on[MAX_N + 5][MAX_N + 5];
vector <POS> v[MAX_N + 5][MAX_N + 5];
bool visited[MAX_N + 5][MAX_N + 5];

const int dy[4] = {-1, 0, 1, 0};    // 북 동 남 서 
const int dx[4] = {0, 1, 0, -1};

void input() {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        v[x][y].push_back({a, b});
    }
}

void solve() {
    
    switch_on[1][1] = true;
    ans++;
    
    queue <POS> q;
    q.push({1, 1});
    
    while (!q.empty()) {
        
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        
        for (auto i : v[y][x]) {
            if (!switch_on[i.y][i.x]) {
                switch_on[i.y][i.x] = true;
                ans++;
                memset(visited, false, sizeof(visited));
            }
        }
        
        visited[y][x] = true;
        
        for (int i = 0; i < 4; ++i) {
            
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 1 || ny > N || nx < 1 || nx > N)
                continue;
            
            if (switch_on[ny][nx] && !visited[ny][nx]) {
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
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