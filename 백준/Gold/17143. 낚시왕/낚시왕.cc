#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_R 100
#define MAX_C 100
using namespace std;

struct SHARK { int s, d, z; };
SHARK S[10005];

int R, C, M;
int ans;
int Map[MAX_R + 5][MAX_C + 5];
int tmp[MAX_R + 5][MAX_C + 5];

const int dy[5] = {0, -1, 1, 0, 0};     // 위 아래 오 왼 
const int dx[5] = {0, 0, 0, 1, -1};

void input() {
    cin >> R >> C >> M;
    for (int i = 1; i <= M; ++i) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        S[i] = {s, d, z};
        Map[r][c] = i;
    }
}

void move_shark() {
    
    memset(tmp, 0, sizeof(tmp));
    
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (Map[i][j]) {
                
                int num = Map[i][j];
                int s = S[num].s;
                int d = S[num].d;
                int z = S[num].z;
                
                int ny = i + dy[d] * s;
                int nx = j + dx[d] * s;
                
                if (ny < 1 || ny > R || nx < 1 || nx > C) {
                    
                    if (d == 1 || d == 2) {
                        
                        int y = (R - 1) * 2;
                        int idx = (ny - 1) % y;
                        if (!idx) idx = y;
                        
                        
                        if (d == 2) {
                            if (idx >= R) {
                                int gap = (idx - (R - 1));
                                idx = R - gap;
                                d = 1;
                            }
                            else 
                                idx += 1;
                        }
                        
                        else {
                            
                            idx = ((ny - 1) * -1) % y;
                            if (!idx) idx = y;
                            
                            if (idx >= R) {
                                int gap = (idx - (R - 1));
                                idx = R - gap;
                            }
                            else {
                                idx += 1;
                                d = 2;
                            }
                            
                        }
                        
                        //cout << num << ' ' << idx << ' ' << nx << ' ' << tmp[idx][nx] << '\n';
                        
                        
                        if (!tmp[idx][nx])
                            tmp[idx][nx] = num;
                        else {
                            if (S[tmp[idx][nx]].z < S[num].z)
                                tmp[idx][nx] = num;
                        } 
                        
                    }
                    
                    else {
                        
                        int x = (C - 1) * 2;
                        int idx = (nx - 1) % x;
                        if (!idx) idx = x;
                        
                        if (d == 3) {
                            
                            if (idx >= C) {
                                int gap = (idx - (C - 1));
                                idx = C - gap;
                                d = 4;
                            }
                            else 
                                idx += 1;
                            
                        }
                        
                        else {
                            
                            idx = ((nx - 1) * -1) % x;
                            if (!idx) idx = x;
                            
                            if (idx >= C) {
                                int gap = (idx - (C - 1));
                                idx = C - gap;
                            }
                            else {
                                idx += 1;
                                d = 3;
                            }
                            
                        }    
                        
                        if (!tmp[ny][idx])
                            tmp[ny][idx] = num;
                        else {
                            if (S[tmp[ny][idx]].z < S[num].z)
                                tmp[ny][idx] = num;
                        }
                        
                        //cout << num << ' ' << ny << ' ' << idx << '\n';
                    }
                    
                    S[num].d = d;
                    
                }
                else {
                    if (!tmp[ny][nx])
                        tmp[ny][nx] = num;
                    else {
                        if (S[tmp[ny][nx]].z < S[num].z)
                            tmp[ny][nx] = num;
                    }
                }
            }
        }
    }
    
    memmove(Map, tmp, sizeof(Map));
}
/*
void print_progress() {
    cout << ans << '\n';
    
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cout << Map[i][j] << ' ';
        }
        cout << '\n';
    }
}
*/
void solve() {
    for (int j = 1; j <= C; ++j) { 
        for (int i = 1; i <= R; ++i) {
            if (Map[i][j]) {
                ans += S[Map[i][j]].z;
                Map[i][j] = 0;
                break;
            }
        }
        move_shark();
        
        //print_progress();
        
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