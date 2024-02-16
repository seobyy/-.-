#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 500
#define MAX_M 500
using namespace std;

int N, M;
int ans;
int Map[MAX_N + 5][MAX_M  + 5];
int B[6] = {0, 2, 1, 8, 4, 4};

void input() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j)
            cin >> Map[i][j];
    }
}

void calArea(int block, int type) {
    
    int sum = 0;
    if (block == 1) {
        if (!type) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (j + 1 >= M || j + 2 >= M || j + 3 >= M)
                        continue;
                    for (int k = 0; k < 4; ++k)
                        sum += Map[i][j + k];
                    ans = max(ans, sum);
                }
            }
        }
        else {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (i + 1 >= N || i + 2 >= N || i + 3 >= N)
                        continue;
                    for (int k = 0; k < 4; ++k)
                        sum += Map[i + k][j];
                    ans = max(ans, sum);
                }
            }
        }
    }
    
    else if (block == 2) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                sum = 0;
                if (i + 1 >= N || j + 1 >= M)
                    continue;
                sum += (Map[i][j] + Map[i][j + 1] + Map[i + 1][j] + Map[i + 1][j + 1]);
                ans = max(ans, sum);
            }
        }
    }
    
    else if (block == 3) {
        
        if (type < 4) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (i + 1 >= N || i + 2 >= N)
                        continue;
                    sum += Map[i][j] + Map[i + 1][j] + Map[i + 2][j];
                    if (!type) {
                        if (j - 1 < 0)
                            continue;
                        sum += Map[i][j - 1];
                        ans = max(ans, sum);
                    }
                    else if (type == 1) {
                        if (j + 1 >= M)
                            continue;
                        sum += Map[i][j + 1];
                        ans = max(ans, sum);
                    }
                    else if (type == 2) {
                        if (j - 1 < 0)
                            continue;
                        sum += Map[i + 2][j - 1];
                        ans = max(ans, sum);
                    }
                    else if (type == 3) {
                        if (j + 1 >= M)
                            continue;
                        sum += Map[i + 2][j + 1];
                        ans = max(ans, sum);
                    }
                }
            }
        }
        
        else {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (j + 1 >= M || j + 2 >= M)
                        continue;
                    sum += Map[i][j] + Map[i][j + 1] + Map[i][j + 2];
                    if (type == 4) {
                        if (i - 1 < 0)
                            continue;
                        sum += Map[i - 1][j];
                        ans = max(ans, sum);
                    }
                    else if (type == 5) {
                        if (i - 1 < 0)
                            continue;
                        sum += Map[i - 1][j + 2];
                        ans = max(ans, sum);
                    }
                    else if (type == 6) {
                        if (i + 1 >= N)
                            continue;
                        sum += Map[i + 1][j];
                        ans = max(ans, sum);
                    }
                    else if (type == 7) {
                        if (i + 1 >= N)
                            continue;
                        sum += Map[i + 1][j + 2];
                        ans = max(ans, sum);
                    }
                }
            }
        }
        
        
    }
    else if (block == 4) {
        if (!type) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (i + 1 >= N || i + 2 >= N || j + 1 >= M)
                        continue;
                    sum += (Map[i][j] + Map[i + 1][j] + Map[i + 1][j + 1] + Map[i + 2][j + 1]);
                    ans = max(ans, sum);
                }
            }
        }
        else if (type == 1) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (i + 1 >= N || i + 2 >= N || j - 1 < 0)
                        continue;
                    sum += (Map[i][j] + Map[i + 1][j] + Map[i + 1][j - 1] + Map[i + 2][j - 1]);
                    ans = max(ans, sum);
                }
            }
        }
        else if (type == 2) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (i - 1 < 0 || j + 1 >= M || j + 2 >= M)
                        continue;
                    sum += (Map[i][j] + Map[i][j + 1] + Map[i - 1][j + 1] + Map[i - 1][j + 2]);
                    ans = max(ans, sum);
                }
            }
        }
        else if (type == 3) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (i + 1 >= N || j + 1 >= M || j + 2 >= M)
                        continue;
                    sum += (Map[i][j] + Map[i][j + 1] + Map[i + 1][j + 1] + Map[i + 1][j + 2]);
                    ans = max(ans, sum);
                }
            }
        }
    }
    else if (block == 5) {
        if (type == 0) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (i - 1 < 0 || j + 1 >= M || j + 2 >= M)
                        continue;
                    sum += (Map[i][j] + Map[i][j + 1] + Map[i - 1][j + 1] + Map[i][j + 2]);
                    ans = max(ans, sum);
                }
            }
        }
        else if (type == 1) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (i + 1 >= N || j + 1 >= M || j + 2 >= M)
                        continue;
                    sum += (Map[i][j] + Map[i][j + 1] + Map[i + 1][j + 1] + Map[i][j + 2]);
                    ans = max(ans, sum);
                }
            }
        } 
        else if (type == 2) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (i + 1 >= N || i + 2 >= N || j - 1 < 0)
                        continue;
                    sum += (Map[i][j] + Map[i + 1][j] + Map[i + 1][j - 1] + Map[i + 2][j]);
                    ans = max(ans, sum);
                }
            }
        }
        else if (type == 3) {
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < M; ++j) {
                    sum = 0;
                    if (i + 1 >= N || i + 2 >= N || j + 1 >= M)
                        continue;
                    sum += (Map[i][j] + Map[i + 1][j] + Map[i + 1][j + 1] + Map[i + 2][j]);
                    ans = max(ans, sum);
                }
            }
        }
    }
}

void solve() {
    for (int b = 1; b <= 5; ++b) {
        for (int a = 0; a < B[b]; ++a) {
            calArea(b, a);
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