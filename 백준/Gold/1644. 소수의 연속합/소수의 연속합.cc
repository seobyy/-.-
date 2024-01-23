#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 4'000'000
using namespace std;

int N;
int ans;
vector <int> v;
bool isPrime[MAX_N + 5];

void Eratos() {
    for (int i = 1; i <= N; ++i) {
        isPrime[i] = true;
    }
    for (int i = 2; i <= N; ++i) {
        if (isPrime[i]) {
            v.push_back(i);
            for (int j = 2 * i; j <= N; j += i) 
                isPrime[j] = false;
        }
    }
} 

void solve() {
    int l = 0, r = 0;
    int sum = 0;
    int len = v.size();
    v.push_back(0);
    while (r <= len) {
        if (sum < N) 
            sum += v[r++];
        else if (sum > N)
            sum -= v[l++];
        else {
            ans++;
            sum -= v[l++];
        }
    }
}

int main() {
    
    fastio;
    cin >> N;
    Eratos();
    solve();
    
    cout << ans << '\n';
    
    return 0;
}