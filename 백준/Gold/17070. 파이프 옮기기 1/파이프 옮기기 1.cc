#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 16
using namespace std;


int N; 
int ans;
int Map[MAX_N + 5][MAX_N + 5];

const int dy[3] = {0, 1, 1};
const int dx[3] = {1, 0, 1};


void input() {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> Map[i][j];
        }
    }
}

bool check_diagonal(int y, int x) {
    for (int i = 0; i < 3; ++i) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny > N || nx > N || Map[ny][nx])
            return false;
    }
    return true;
}

void movePipe(int type, int y, int x) {
    
    if (y == N && x == N) {
        ans++;
        return;
    }
    
    if (type == 0) {
        if (!Map[y][x + 1] && x + 1 <= N) 
            movePipe(0, y, x + 1);
        if (check_diagonal(y, x)) 
            movePipe(2, y + 1, x + 1);
    }
    else if (type == 1) {
        if (!Map[y + 1][x] && y + 1 <= N)
            movePipe(1, y + 1, x);
        if (check_diagonal(y, x))
            movePipe(2, y + 1, x + 1);
    }
    else {
        if (!Map[y][x + 1] && x + 1 <= N)
            movePipe(0, y, x + 1);
        if (!Map[y + 1][x] && y + 1 <= N)
            movePipe(1, y + 1, x);
        if (check_diagonal(y, x))
            movePipe(2, y + 1, x + 1);
    }
}


void solve() {
    movePipe(0, 1, 2);
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