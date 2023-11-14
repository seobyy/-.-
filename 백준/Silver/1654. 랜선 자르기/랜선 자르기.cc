#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_K 10'000
using namespace std;

typedef long long int ll;

int K, N;
int lan[MAX_K + 5];

ll binarySearch(ll s, ll e) {
    
    int res = 0;
    ll mid = s + (e - s) / 2;
    
    if (s > e)
        return mid - 1;
    
    for (int i = 0; i < K; ++i) {
        res += lan[i] / mid;
    }
    
    if (res < N) 
        return binarySearch(s, mid - 1);
    
    else
        return binarySearch(mid + 1, e);
}

int main() {
    
    fastio;
    cin >> K >> N;
    
    int max_lan = 0;
    for (int i = 0; i < K; ++i) {
        cin >> lan[i];
        if (lan[i] > max_lan)
            max_lan = lan[i];
    }
    
    cout << binarySearch(1, max_lan) << '\n';
    
    return 0;
}