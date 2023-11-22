#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 200
using namespace std;

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
    
    if (x != y)
        parent[y] = x;
}


int main() {
    
    fastio;
    int N, M;
    cin >> N >> M;
    
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }
    
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            int x;
            cin >> x;
            if (x == 1) 
                Union(i, j);
        }
    }
    
    bool canGO = true;
    int last = 0;
    for (int i = 0; i < M; ++i) {
        int n;
        cin >> n;
        if (last) {
            if (Find(last) != Find(n))
                canGO = false;
        }
        last = n; 
    }
    
    if (canGO)
        cout << "YES" << '\n';
    else
        cout << "NO" << '\n';
    
    return 0;
}