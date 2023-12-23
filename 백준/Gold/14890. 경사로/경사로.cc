#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100
using namespace std;

int N, L;
int ans;
int mapp[MAX_N + 5][MAX_N + 5];
bool isSlope[MAX_N + 5][MAX_N + 5];

void solve() {
    
    for (int i = 0; i < N; ++i) {
        memset(isSlope, false, sizeof(isSlope));
        bool canSlope = true;
        int prev = mapp[i][0];
        for (int j = 1; j < N; ++j) {
            if (mapp[i][j] == prev)
                continue;
                
            if (prev - mapp[i][j] == 1) {
                for (int k = 0; k < L; ++k) {
                    if (mapp[i][j + k] != mapp[i][j] || j + k >= N || isSlope[i][j + k]) {
                        canSlope = false;
                        break;
                    }
                }
                
                if (canSlope) {
                    for (int k = 0; k < L; ++k) {
                        isSlope[i][j + k] = true;
                    }
                }
            }
            
            else if (prev - mapp[i][j] == -1) {
                for (int k = 1; k <= L; ++k) {
                    if (mapp[i][j - k] != prev || j - k < 0 || isSlope[i][j - k]) {
                        canSlope = false;
                        break;
                    }
                }
                
                if (canSlope) {
                    for (int k = 1; k <= L; ++k) {
                        isSlope[i][j - k] = true;
                    }
                }
            }
            
            else {
                canSlope = false;
                break;
            }
            
            prev = mapp[i][j];
            if (!canSlope)
                break;
            
        }
        
        if (canSlope) 
            ans++;
        
    }
    
    for (int j = 0; j < N; ++j) {
        memset(isSlope, false, sizeof(isSlope));
        bool canSlope = true;
        int prev = mapp[0][j];
        for (int i = 1; i < N; ++i) {
            if (mapp[i][j] == prev)
                continue;
                
            if (prev - mapp[i][j] == 1) {
                for (int k = 0; k < L; ++k) {
                    if (mapp[i + k][j] != mapp[i][j] || i + k >= N || isSlope[i][j]) {
                        canSlope = false;
                        break;
                    }
                }
                
                if (canSlope) {
                    for (int k = 0; k < L; ++k) {
                        isSlope[i + k][j] = true;
                    }
                }
                
            }
            
            else if (prev - mapp[i][j] == -1) {
                for (int k = 1; k <= L; ++k) {
                    if (mapp[i - k][j] != prev || i - k < 0 || isSlope[i - k][j]) {
                        canSlope = false;
                        break;
                    }
                }
                
                if (canSlope) {
                    for (int k = 1; k <= L; ++k) {
                        isSlope[i - k][j] = true;
                    }
                }
    
            }
            
            else {
                canSlope = false;
                break;
            }
            
            prev = mapp[i][j];
            if (!canSlope)
                break;
            
        }
        
        if (canSlope) 
            ans++;
        
    }
}

int main() {
    
    fastio;
    cin >> N >> L;
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> mapp[i][j];
        }
    }
    
    solve();
    
    cout << ans << '\n';
    
    return 0;
}