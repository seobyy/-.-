#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int N;
int x, y, d, g;
int ans;
bool Map[105][105];

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {1, 0, -1, 0};

vector <int> dir;

void make_curve() {
    
    int gen = 1;
    while (gen <= g) {
        int len = dir.size();
        for (int i = len - 1; i >= 0; --i) {
            int d = (dir[i] + 1) % 4;
            dir.push_back(d);
            
            y += dy[d]; x += dx[d];
            if (y > 100 || y < 0 || x > 100 || x < 0)
                continue;
            
            Map[y][x] = true;
        }
        gen++;
    }
}

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> x >> y >> d >> g;
        Map[y][x] = true;
        y += dy[d];
        x += dx[d];
        Map[y][x] = true;
        dir.clear();
        dir.push_back(d);
        
        make_curve();
    }
}

void solve() {
    
    for (int i = 0; i <= 99; ++i) {
        for (int j = 0; j <= 99; ++j) {
            if (Map[i][j] && Map[i][j + 1]
                && Map[i + 1][j] && Map[i + 1][j + 1])
                ans++;
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