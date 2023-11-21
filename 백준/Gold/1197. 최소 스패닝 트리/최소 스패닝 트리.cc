#include <iostream>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_V 10005
using namespace std;

////////////////////////
// MST by kruskal
////////////////////////

typedef long long int ll;
int parent[MAX_V];

int find(int node) {
    if (parent[node] == node)
        return node;
    return parent[node] = find(parent[node]);
}

void merge(int n1, int n2) {
    parent[n2] = n1;
}

int main() {
    
    fastio;
    int V, E;
    cin >> V >> E;
    
    vector <pair<int, pair<int, int>>> edge;
    for (int i = 1; i <= V; ++i) {
        parent[i] = i;
    }
    
    for (int i = 0; i < E; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        edge.push_back({C, {A, B}});
    }
    sort(edge.begin(), edge.end());
    
    int len = edge.size();
    ll ans = 0;
    for (int i = 0; i < len; ++i) {
        
        int w = edge[i].first;
        int s = edge[i].second.first;
        int e = edge[i].second.second;
        
        int p1 = find(s);
        int p2 = find(e);
        
        if (p1 == p2)
            continue;
        
        merge(p1, p2);
        ans += w;

    }
    
    cout << ans << '\n';
}