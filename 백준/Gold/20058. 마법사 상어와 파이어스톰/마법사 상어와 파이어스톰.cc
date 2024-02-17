#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_S 67
using namespace std;

int N, Q;
int S;
int large_ice_size;
int A[MAX_S][MAX_S];
int tmp_A[MAX_S][MAX_S];
bool visited[MAX_S][MAX_S];

const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

void rotate(int size) {
    
    int tmp[size][size] = {0};
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            tmp[i][j] = tmp_A[size - j - 1][i];
        }
    }
    
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            tmp_A[i][j] = tmp[i][j];
        }
    }
    
}

void firestorm(int level) {
    
    int l = pow(2, level);
    int s = S / l;
    int init_y = 0, init_x = 0;
    
    for (int i = 0; i < s; ++i) {
        init_x = 0;
        for (int j = 0; j < s; ++j) {
            
            for (int si = 0; si < l; ++si) {
                for (int sj = 0; sj < l; ++sj) {
                    tmp_A[si][sj] = A[init_y + si][init_x + sj];
                }
            }
            
            rotate(l);
            for (int si = 0; si < l; ++si) {
                for (int sj = 0; sj < l; ++sj) {
                    A[init_y + si][init_x + sj] = tmp_A[si][sj];
                }
            }
            
            init_x += l;
        }
        init_y += l;
    }
}

void countIce(int start_y, int start_x) {
    
    int cnt = 1;
    visited[start_y][start_x] = true;
    
    queue <pair<int, int>> q;
    q.push({start_y, start_x});
    
    while (!q.empty()) {
        
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; ++i) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= S || nx < 0 || nx >= S)
                continue;
                
            if (!visited[ny][nx] && A[ny][nx] > 0) {
                visited[ny][nx] = true;
                q.push({ny, nx});
                cnt++;
            }
        }
    }
    
    if (cnt > large_ice_size)
        large_ice_size = cnt;
}

void meltIce() {
    
    bool melt[MAX_S][MAX_S] = {false};
    
    for (int y = 0; y < S; ++y) {
        for (int x = 0; x < S; ++x) {
                
            if (!A[y][x])
                continue;
                
            int cnt = 0;
            for (int i = 0; i < 4; ++i) {
                    
                int ny = y + dy[i];
                int nx = x + dx[i];
                    
                if (ny < 0 || nx >= S || nx < 0 || nx >= S) 
                    continue;
                    
                if (A[ny][nx] > 0)
                    cnt++;
                        
            }
                
            if (cnt < 3)
                melt[y][x] = true;
                    
        }
    }

    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            if (melt[i][j])
                A[i][j]--;
        }
    }

}

int main() {
    fastio;
    cin >> N >> Q;
    S = pow(2, N);
    
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            cin >> A[i][j];
        }
    }
    
    vector <int> L;
    
    for (int i = 0; i < Q; ++i) {
        int l;
        cin >> l;
        L.push_back(l);
    }
    
    for (auto p : L) {
        firestorm(p);
        
        meltIce();
    }
    
    int sum = 0;
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            sum += A[i][j];
        }
    }
    
    large_ice_size = 0;
    for (int i = 0; i < S; ++i) {
        for (int j = 0; j < S; ++j) {
            if (!visited[i][j] && A[i][j] > 0)
                countIce(i, j);
        }
    }
    
    cout << sum << '\n' << large_ice_size << '\n';
    
    return 0;
}