#include <iostream>
#include <unordered_map>
#include <memory.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 200'000
using namespace std;

int parent[MAX_N + 5];
int network[MAX_N + 5];

int Find(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    
    if (x != y) {
        parent[y] = x;
        network[x] += network[y];
    }
}

int main() {
    
    fastio;
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        int F;
        cin >> F;
        
        memset(parent, 0, sizeof(parent));
        memset(network, 0, sizeof(network));
        
        int nameCnt = 0;
        unordered_map <string, int> nameIndex;
        
        for (int i = 0; i < F; ++i) {
            string a, b;
            cin >> a >> b;
            if (!nameIndex[a]) {
                nameIndex[a] = ++nameCnt;
                parent[nameIndex[a]] = nameIndex[a];
                network[nameIndex[a]] = 1;
            }
            if (!nameIndex[b]) {
                nameIndex[b] = ++nameCnt;
                parent[nameIndex[b]] = nameIndex[b];
                network[nameIndex[b]] = 1;
            }
            
            int a1 = nameIndex[a];
            int a2 = nameIndex[b];
            Union(a1, a2);
            
            int x = Find(a1);
            
            cout << network[x] << '\n';
        }
        
    }
    
    return 0;
}