#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 20
using namespace std;

struct GUEST { int sy, sx; int ey, ex; bool isFinished; };
struct POS {int y, x; int gas; int dis; };
struct cmp {
    bool operator()(POS a, POS b) {
        if (a.dis == b.dis) {
            if (a.y == b.y)
                return a.x > b.x;
            return a.y > b.y;
        }
        return a.dis > b.dis;
    }
};

GUEST guestPool[500];

int N, M, gas;
int curY, curX;
int rest;
int targetNum;
int ans;
bool f = true;
int Map[MAX_N + 5][MAX_N + 5];
bool visited[MAX_N + 5][MAX_N + 5];

const int dy[4] = {-1, 0, 0, 1};    // 북 서 동 남 
const int dx[4] = {0, -1, 1, 0};

priority_queue <POS, vector<POS>, cmp> pq;

void input() {
    cin >> N >> M >> gas;
    rest = M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cin >> Map[i][j];
    }
    cin >> curY >> curX;
    curY--; curX--;
    for (int i = 11; i < M + 11; ++i) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;
        guestPool[i] = {y1 - 1, x1 - 1, y2 - 1, x2 - 1, false};
        Map[y1 - 1][x1 - 1] = i;
    }
}

void bfs1() {
    bool canGo = false;
    memset(visited, false, sizeof(visited));
    visited[curY][curX] = true;
    queue <POS> q;
    q.push({curY, curX, gas, 0});
    
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int g = q.front().gas;
        int d = q.front().dis;
        q.pop();
        
        if (Map[y][x] >= 11 && !guestPool[Map[y][x]].isFinished) {
            pq.push({y, x, 0, d});
            canGo = true;
        }
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (visited[ny][nx])
                continue;
                
            if (Map[ny][nx] != 1 && g >= 1) {
                visited[ny][nx] = true;
                q.push({ny, nx, g - 1, d + 1});
            }
        }
    }
    if (!canGo) 
        f = false;
    
    else {
        curY = pq.top().y;
        curX = pq.top().x;
        gas -= pq.top().dis;
        targetNum = Map[curY][curX];
        while (!pq.empty())
            pq.pop();
    }
}

void bfs2() {
    
    memset(visited, false, sizeof(visited));
    visited[curY][curX] = true;
    queue <POS> q;
    q.push({curY, curX, gas, 0});
    
    while (!q.empty()) {
        int y = q.front().y;
        int x = q.front().x;
        int g = q.front().gas;
        int d = q.front().dis;
        q.pop();
        
        if (y == guestPool[targetNum].ey && x == guestPool[targetNum].ex) {
            gas += d;
            curY = y; curX = x;
            rest--;
            guestPool[targetNum].isFinished = true;
            return;
        }
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= N)
                continue;
            if (visited[ny][nx])
                continue;
                
            if (Map[ny][nx] != 1 && g >= 1) {
                visited[ny][nx] = true;
                q.push({ny, nx, g - 1, d + 1});
            }
        }
    }
    f = false;
}


void solve() {
    while (rest) {
        //cout << curY << ' ' << curX << ' ' << gas << '\n';
        bfs1();
        //cout << curY << ' ' << curX << ' ' << gas << '\n';
        if (!f) {
            gas = -1;
            break;
        }
        bfs2();
        //cout << curY << ' ' << curX << ' ' << gas << '\n';
        if (!f) {
            gas = -1;
            break;
        }
    }
}

void output() {
    cout << gas << '\n';
}


int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}