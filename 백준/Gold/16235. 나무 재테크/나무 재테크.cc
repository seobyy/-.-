#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 10
using namespace std;

int N, M, K;
int ans;
int A[MAX_N + 5][MAX_N + 5];
int nutri[MAX_N + 5][MAX_N + 5];

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

vector <int> Map[MAX_N + 5][MAX_N + 5];

void init() {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            nutri[i][j] = 5;
    }
}

void input() {
    cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j)
            cin >> A[i][j];
    }
    for (int i = 1; i <= M; ++i) {
        int x, y, z; cin >> x >> y >> z;
        Map[x][y].push_back(z);
    }
}

void solve() {
    
    while (K--) {   
        
        // 봄, 여름
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                
                sort(Map[i][j].begin(), Map[i][j].end());
                int die_tree = 0;
                vector <int> tmp;
                
                for (auto k : Map[i][j]) {
                    if (k <= nutri[i][j]) {
                        nutri[i][j] -= k;
                        tmp.push_back(k + 1);
                    }
                    else 
                        die_tree += k / 2;
                }
                
                Map[i][j].clear();
                for (auto k : tmp) {
                    Map[i][j].push_back(k);
                }
                nutri[i][j] += die_tree;
            }
        }
        
        
        // 가을
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                for (auto k : Map[i][j]) {
                    if (k % 5 == 0) {
                        for (int d = 0; d < 8; ++d) {
                            int ny = i + dy[d];
                            int nx = j + dx[d];
                            
                            if (ny < 1 || ny > N || nx < 1 || nx > N)
                                continue;
                                
                            Map[ny][nx].push_back(1);
                        }
                    }
                }
            }
        }
        
        // 겨울
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j)
                nutri[i][j] += A[i][j];
        }
        
    }
    
    // 살아있는 나무 카운트 
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
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
    init();
    solve();
    output();
    
    return 0;
}