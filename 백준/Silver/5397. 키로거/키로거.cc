#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

string str;
list <char> L;
auto it = L.begin();

void init() {
    list <char> tmp;
    L = tmp;
    it = L.begin();
}

void input() {
    cin >> str;
}

void solve() {
    int len = str.length();
    for (int i = 0; i < len; ++i) {
        
        if (str[i] == '<') {
            if (it != L.begin()) 
                it--;
        }
        
        else if (str[i] == '>') {
            if (it != L.end())
                it++;
        }
        
        else if (str[i] == '-') {
            if (it != L.begin())
                it = L.erase(--it);
        }
        
        else {
            it = L.insert(it, str[i]);
            it++;
        }

    }
}

void output() {
    for (auto i : L) 
        cout << i;
    cout << '\n';
}

int main() {
    
    fastio;
    int T; cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        
        input();
        init();
        solve();
        output();
        
    }
    
    return 0;
}