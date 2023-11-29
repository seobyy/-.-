#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1'000'000
#define ll long long 
using namespace std;

int stockPrice[MAX_N + 5];

int main() {
    
    fastio;
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        
        int N;
        cin >> N;
        
        for (int i = 0; i < N; ++i) {
            cin >> stockPrice[i];
        }

        ll ans = 0;
        int maxP = 0;
        for (int i = N - 1; i >= 0; --i) {
            if (stockPrice[i] > maxP)
                maxP = stockPrice[i];
            ans += maxP - stockPrice[i];
        }

        cout << ans << '\n';
    }
    
    return 0;
}