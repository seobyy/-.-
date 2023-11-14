#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1'000'000
using namespace std;

typedef long long int ll;

int N, M;
int wood[MAX_N + 5];

ll binarySearch(ll s, ll e) {
    
    if (s > e)
        return e;
    
    ll mid = s + (e - s) / 2;
    ll res = 0;
    
    for (int i = 0; i < N; ++i) {
        if (wood[i] > mid)
            res += (wood[i] - mid);
    }
    
    if (res < M)
        return binarySearch(s, mid - 1);
    else
        return binarySearch(mid + 1, e);
    
}

int main() {
    
    fastio;
    cin >> N >> M;
    
    int max_height = 0;
    for (int i = 0; i < N; ++i) {
        cin >> wood[i];
        if (wood[i] > max_height)
            max_height = wood[i];
    }
    
    cout << binarySearch(0, max_height) << '\n';
    
    return 0;
}