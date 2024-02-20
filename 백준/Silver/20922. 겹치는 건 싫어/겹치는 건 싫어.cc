#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 200'000
#define MAX_NUM 100'000
using namespace std;

int N, K;
int ans;
int arr[MAX_N + 5];
int cnt[MAX_NUM + 5];

void input() {
    cin >> N >> K;
    for (int i = 0 ; i < N; ++i) {
        cin >> arr[i];
    }
}

void solve() {
    int e = 0;
    cnt[arr[e]]++;
    
    for (int s = 0; s < N; ++s) {
        if (s) cnt[arr[s - 1]]--;
        while (e + 1 < N && cnt[arr[e + 1]] + 1 <= K) 
            cnt[arr[++e]]++;
        
        ans = max(ans, e - s + 1);
        if (e == N - 1) break;
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