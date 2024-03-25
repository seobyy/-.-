#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct POS { int sum; int x; }; 
struct cmp {
    bool operator() (POS a, POS b) {
        if (a.sum == b.sum) 
            return a.x > b.x;
        return a.sum < b.sum;
    }
};

int M, S;
int sy, sx;
int ans;

vector <int> Map[5][5];
vector <int> waited[5][5];

int scent[5][5];
bool visited[5][5];

// 좌 부터 시계방향
const int dy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
const int dx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

priority_queue <POS, vector<POS>, cmp> pq;

void input() {
    cin >> M >> S;
    for (int i = 0; i < M; ++i) {
        int y, x, d;
        cin >> y >> x >> d;
        Map[y][x].push_back(d);
    }
    cin >> sy >> sx;
}

void fish_copy() {
    
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j)
            waited[i][j].clear();
    }
    
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (auto k : Map[i][j])
                waited[i][j].push_back(k);
        }
    }
    
}

void fish_move() {
    
    vector <int> tmp[5][5];
    
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (auto k : Map[i][j]) {
                
                bool can_move = false;
                for (int c = 0; c < 8; ++c) {
                    
                    int dir = (k - c + 8) % 8;
                    if (!dir) dir = 8;
                    
                    int ny = i + dy[dir];
                    int nx = j + dx[dir];
                    if (ny < 1 || ny > 4 || nx < 1 || nx > 4)
                        continue;
                    if (scent[ny][nx])
                        continue;
                    if (ny == sy && nx == sx)
                        continue;
                    
                    can_move = true;
                    tmp[ny][nx].push_back(dir);
                    break;
                    
                }
                
                if (!can_move)
                    tmp[i][j].push_back(k);
                
            }
        }
    }
    
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j)
            Map[i][j].clear();
    }
    
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (auto k : tmp[i][j]) 
                Map[i][j].push_back(k);
        }
    }
    
}

void dfs(int sum, int cnt, int y, int x, int d1, int d2, int d3) {
    
    if (cnt == 3) {
        
        //cout << d1 << d2 << d3 << ' ' << sum << '\n';
        
        int x = 100 * d1 + 10 * d2 + d3;
        pq.push({sum, x});
        return;
    }
    
    if (cnt)
        visited[y][x] = true;
    
    for (int i = 1; i <= 4; ++i) {
        
        int d = 0;
        if (i == 1) d = 3;
        else if (i == 2) d = 1;
        else if (i == 3) d = 7;
        else d = 5;
        
        int ny = y + dy[d];
        int nx = x + dx[d];
        
        if (ny < 1 || ny > 4 || nx < 1 || nx > 4)
            continue;
        
        int ns = sum;
        if (!visited[ny][nx])
            ns = sum + Map[ny][nx].size();
            
        //cout << y << ' ' << x << ' ' << sum << '\n';
        //cout << d << ' ' << ny << ' ' << nx << ' ' << ns << '\n';    
            
        if (!cnt) d1 = i; 
        else if (cnt == 1) d2 = i;
        else if (cnt == 2) d3 = i;
        
        dfs(ns, cnt + 1, ny, nx, d1, d2, d3);
    }
    
    visited[y][x] = false;
}

int convert_dir(int num) {
    if (num == 1)
        return 3;
    else if (num == 2)
        return 1;
    else if (num == 3)
        return 7;
    else 
        return 5;
}

void shark_move() {
    
    priority_queue <POS, vector<POS>, cmp> tmp_pq;
    pq = tmp_pq;
    
    memset(visited, false, sizeof(visited));
    dfs(0, 0, sy, sx, 0, 0, 0);
    
    int t1 = pq.top().x / 100;
    int a1 = convert_dir(t1);
    sy += dy[a1]; sx += dx[a1];
    if (Map[sy][sx].size()) {
        scent[sy][sx] = 3;
        Map[sy][sx].clear();
    }
    
    int t2 = (pq.top().x / 10) % 10; 
    int a2 = convert_dir(t2);
    sy += dy[a2]; sx += dx[a2];
    if (Map[sy][sx].size()) {
        scent[sy][sx] = 3;
        Map[sy][sx].clear();
    }
    
    int t3 = pq.top().x % 10;
    int a3 = convert_dir(t3);
    sy += dy[a3]; sx += dx[a3];
    if (Map[sy][sx].size()) {
        scent[sy][sx] = 3;
        Map[sy][sx].clear();
    }
    
}

void scent_delete() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            if (scent[i][j])
                scent[i][j]--;
        }
    }
}

void copy_complete() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (auto k : waited[i][j]) 
                Map[i][j].push_back(k);
        }
    }
}

void print_progress() {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (auto k : Map[i][j]) {
                cout << i << ' ' << j << ' ' << k << '\n';
            }
        }
    }
    cout << '\n';
}

void solve() {
    while (S--) {
        fish_copy();
        //print_progress();
        fish_move();
        //print_progress();
        
        shark_move();
        //print_progress();
        
        scent_delete();
        //print_progress();
        copy_complete();
        //print_progress();
    }
    
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            ans += Map[i][j].size();
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