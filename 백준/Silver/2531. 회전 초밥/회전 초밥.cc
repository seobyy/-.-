#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 30'000
#define MAX_d 3'000
using namespace std;

int N, d, k, c;
int ans;
int sushi[MAX_N + 5];
int cnt[MAX_d + 5];
unordered_set <int> dish;

void input() {
    cin >> N >> d >> k >> c;
    for (int i = 0; i < N; ++i) {
        cin >> sushi[i];
    }
}

void init() {
    for (int i = 0; i < k; ++i) {
        dish.insert(sushi[i]);
        cnt[sushi[i]]++;
    }
    int sz = dish.size();
    if (!cnt[c]) sz++;
    ans = max(ans, sz);
}

void solve() {
    
    init();
    for (int s = 0; s < N; ++s) {
        int e = (s + k) % N;
        if (cnt[sushi[s]] == 1)
            dish.erase(sushi[s]);
        if (!cnt[sushi[e]])
            dish.insert(sushi[e]);
        cnt[sushi[s]]--;
        cnt[sushi[e]]++;
        
        int sz = dish.size();
        if (!cnt[c]) sz++;
        ans = max(ans, sz);
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