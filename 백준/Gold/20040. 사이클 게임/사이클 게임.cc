#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 500'000
using namespace std;

int n, m;
int ans;
bool isCycle;
int parent[MAX_N + 5];

int Find(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    
    if (x == y)
        isCycle = true;
    else
        parent[y] = x;
    
}


int main() {
    
    fastio;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        parent[i] = i;
    }
    
    for (int i = 1; i <= m; ++i) {
        int a, b;
        cin >> a >> b;
        
        Union(a, b);
        
        if (!ans && isCycle)
            ans = i;
            
    }
    
    cout << ans << '\n';
    
    return 0;
}