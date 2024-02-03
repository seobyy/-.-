#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100
#define MAX_M 100
using namespace std;

struct POS { int cnt; int y, x; };
struct cmp {
    bool operator()(POS a, POS b) {
        return a.cnt > b.cnt;
    }
};

int N, M;
int ans;
int Map[MAX_N + 5][MAX_M + 5];
bool visited[MAX_N + 5][MAX_M + 5];

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, 1, 0, -1};

void input() {
    cin >> M >> N;
    for (int i = 0; i < N; ++i) {
        string str; cin >> str;
        for (int j = 0; j < M; ++j)
            Map[i][j] = str[j] - '0';
    }
}

void solve() {
    priority_queue <POS, vector<POS>, cmp> pq;
    pq.push({0, 0, 0});
    visited[0][0] = true;
    
    while (!pq.empty()) {
        int c = pq.top().cnt;
        int y = pq.top().y;
        int x = pq.top().x;
        pq.pop();
        
        //cout << c << ' ' << y << ' ' << x << '\n';
        
        if (y == N - 1 && x == M - 1) {
            ans = c;
            break;
        }
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;
            if (visited[ny][nx])
                continue;
            
            visited[ny][nx] = true;
            if (!Map[ny][nx]) 
                pq.push({c, ny, nx});
            
            else if (Map[ny][nx] == 1)
                pq.push({c + 1, ny, nx});
            
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