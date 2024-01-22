#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1000
using namespace std;

int N, K;
bool isPrime[MAX_N + 5];

void solve(int n) {
    for (int i = 1; i <= n; ++i) {
        isPrime[i] = true;
    }
    int cnt = 0;
    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            cnt++;
            if (cnt == K) {
                cout << i << '\n';
                return;
            }
            for (int j = i * 2; j <= n; j += i) {
                if (!isPrime[j])
                    continue;
                isPrime[j] = false;
                cnt++;
                if (cnt == K) {
                    cout << j << '\n';
                    return;
                }
            }
        }
    }
}

int main() {
    
    fastio;
    cin >> N >> K;
    solve(N);
    
    return 0;   
}