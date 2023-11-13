#include <iostream>
#include <map>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    
    fastio;
    
    map <string, int> m;
    int cnt = 0;
    string s;
    while (getline(cin, s)) {
        m[s]++;
        cnt++;
    }
    
    for (auto i : m) {
        
        cout << fixed;
        cout.precision(4);
        
        float ans = (float) i.second / cnt;
        cout << i.first << ' ' << ans * 100 << '\n'; 
    }
    
    return 0;
}