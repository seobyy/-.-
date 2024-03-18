#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 20
using namespace std;

int N;
int ans;
int Map[MAX_N + 5][MAX_N + 5];
bool collided[MAX_N + 5][MAX_N + 5];

void input() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cin >> Map[i][j];
    }
}

void move_block(int dir) {
    
    memset(collided, false, sizeof(collided));
    switch(dir) {
        
        // 상
        case 0:
            
            for (int j = 0; j < N; ++j) {
                for (int i = 1; i < N; ++i) {
                    int num = Map[i][j];
                    if (!num)
                        continue;
                    for (int y = i - 1; y >= 0; --y) {
                        if (Map[y][j]) {
                            if (Map[y][j] == num && !collided[y][j]) {
                                Map[y + 1][j] = 0;
                                Map[y][j] = num * 2;
                                collided[y][j] = true;
                            }
                            break;
                        }
                        
                        else {
                            Map[y][j] = num;
                            Map[y + 1][j] = 0;
                        }
                    }
                }
            }
            
            break;
        
        
        // 하
        case 1:
            
            for (int j = 0; j < N; ++j) {
                for (int i = N - 2; i >= 0; --i) {
                    int num = Map[i][j];
                    if (!num)
                        continue;
                    for (int y = i + 1; y < N; ++y) {
                        if (Map[y][j]) {
                            if (Map[y][j] == num && !collided[y][j]) {
                                Map[y - 1][j] = 0;
                                Map[y][j] = num * 2;
                                collided[y][j] = true;
                            }
                            break;
                        }
                        
                        else {
                            Map[y][j] = num;
                            Map[y - 1][j] = 0;
                        }
                    }
                }
            }
        
            break;
        
        // 좌
        case 2:
            
            for (int i = 0; i < N; ++i) {
                for (int j = 1; j < N; ++j) {
                    int num = Map[i][j];
                    if (!num)
                        continue;
                    for (int x = j - 1; x >= 0; --x) {
                        if (Map[i][x]) {
                            if (Map[i][x] == num && !collided[i][x]) {
                                Map[i][x + 1] = 0;
                                Map[i][x] = num * 2;
                                collided[i][x] = true;
                            }
                            break;
                        }
                        
                        else {
                            Map[i][x] = num;
                            Map[i][x + 1] = 0;
                        }
                    }
                }
            }
            
            break;
        
        // 우
        case 3:
            
            for (int i = 0; i < N; ++i) {
                for (int j = N - 2; j >= 0; --j) {
                    int num = Map[i][j];
                    if (!num)
                        continue;
                    for (int x = j + 1; x < N; ++x) {
                        if (Map[i][x]) {
                            if (Map[i][x] == num && !collided[i][x]) {
                                Map[i][x - 1] = 0;
                                Map[i][x] = num * 2;
                                collided[i][x] = true;
                            }
                            break;
                        }
                        
                        else {
                            Map[i][x] = num;
                            Map[i][x - 1] = 0;
                        }
                    }
                }
            }
            
            
            break;
            
        default: break;
        
    }
}

void print_map() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j)
            cout << Map[i][j] << ' ';
        cout << '\n';
    }
}

void play_game(int cnt) {
    
    if (cnt == 5) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) 
                ans = max(ans, Map[i][j]);
        }
        return;
    }
    
    int tmp[MAX_N + 5][MAX_N + 5];
    memmove(tmp, Map, sizeof(tmp));
    
    for (int i = 0; i < 4; ++i) {
        
        move_block(i);
        //cout << cnt << ' ' << i << '\n';
        //print_map();
        play_game(cnt + 1);
        memmove(Map, tmp, sizeof(Map));
        
    }
}

void solve() {
    play_game(0);
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