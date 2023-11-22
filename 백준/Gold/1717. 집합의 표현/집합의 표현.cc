#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1'000'000
using namespace std;

int parent[MAX_N + 5];

int find(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = find(parent[x]);
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    
    if (x != y) 
        parent[y] = x;
}

int main() {
    
    fastio;
    int n, m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
    }
    
    
    for (int i = 0; i < m; ++i) {
        int c, a, b;
        cin >> c >> a >> b;
        
        if (!c) 
            Union(a, b);
        
        else {
            if (find(a) == find(b))
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
    
    return 0;
}