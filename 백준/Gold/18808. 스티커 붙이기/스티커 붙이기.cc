#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 40
#define MAX_M 40
#define MAX_K 100
using namespace std;

struct sticker { int y, x; int shape[15][15]; };

sticker stickerPool[MAX_K + 5];

int N, M, K;
int ans;
int sticker[15][15];
bool Map[MAX_N + 5][MAX_M + 5];

void input() {
    cin >> N >> M >> K;
    for (int i = 0; i < K; ++i) {
        cin >> stickerPool[i].y >> stickerPool[i].x;
        for (int j = 0; j < stickerPool[i].y; ++j) {
            for (int k = 0; k < stickerPool[i].x; ++k) 
                cin >> stickerPool[i].shape[j][k];
        }
    }
}

void turnArr(int y, int x) {
    int tmp[15][15];
    for (int i = 0; i < y; ++i) {
        for (int j = 0; j < x; ++j) {
            tmp[i][j] = sticker[x - 1 - j][i];
        }
    }
    memmove(sticker, tmp, sizeof(sticker));
}

void solve() {
    for (int s = 0; s < K; ++s) {
        int sy = stickerPool[s].y;
        int sx = stickerPool[s].x;
        for (int i = 0; i < sy; ++i) {
            for (int j = 0; j < sx; ++j) 
                sticker[i][j] = stickerPool[s].shape[i][j];
        }
        
        for (int dir = 0; dir < 4; ++dir) {
            
            int y, x;
            if (dir % 2 == 0) {
                y = sy; x = sx;
            }
            else {
                y = sx; x = sy;
            }
            if (dir) 
                turnArr(y, x);
                
            bool isUsed = false;
            for (int i = 0; i + y <= N; ++i) {
                for (int j = 0; j + x <= M; ++j) {
                    bool canFit = true;
                    
                    for (int b = 0; b < y; ++b) {
                        for (int c = 0; c < x; ++c) {
                            if (sticker[b][c] && Map[i + b][j + c]) {
                                canFit = false;
                                break;
                            }
                        }
                    }
                    
                    if (canFit) {
                        for (int b = 0; b < y; ++b) {
                            for (int c = 0; c < x; ++c) {
                                if (sticker[b][c]) {
                                    Map[i + b][j + c] = true;
                                    ans++;
                                }
                            }
                        }
                        isUsed = true;
                        break;
                    }
                    
                }
                if (isUsed)
                    break;
            }
            if (isUsed)
                break;
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