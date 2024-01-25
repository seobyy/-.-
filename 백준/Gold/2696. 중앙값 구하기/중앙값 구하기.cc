#include <iostream>
#include <queue>
#include <vector>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    
    fastio;
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        
        int M;
        cin >> M;
        
        priority_queue <int, vector<int>, greater<int>> min_heap;
        priority_queue <int> max_heap;
        vector <int> v;
        
        int first;
        cin >> first;
        max_heap.push(first);
        v.push_back(first);
        
        int len = (M - 1) / 2;
        for (int i = 0; i < len; ++i) {
            int X, Y, S, L;
            cin >> X >> Y;
            
            if (X == Y) {
                S = X;
                L = Y;
            }
            else {
                S = (X < Y) ? X : Y;
                L = (X > Y) ? X : Y;
            }
            
            min_heap.push(S);
            max_heap.push(L);
            
            int min_top = min_heap.top();
            int max_top = max_heap.top();
            
            if (max_top > min_top) {
                min_heap.pop();
                max_heap.pop();
                min_heap.push(max_top);
                max_heap.push(min_top);
            }
            
            int median = max_heap.top();
            v.push_back(median);
            
        }
        
        cout << v.size() << '\n';
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}