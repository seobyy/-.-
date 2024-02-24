#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

string p;
int n;
int len;
bool is_error;
bool is_front;
deque <int> dq; 

void init() {
    dq.clear();
    is_error = false;
    is_front = true;
}

void input() {
    cin >> p >> n;
    string str; cin >> str;
    int l = str.length();
    string tmp = "";
    for (int i = 0; i < l; ++i) {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9) 
            tmp += str[i];
            
        else {
            if (tmp != "") {
                dq.push_back(stoi(tmp));
                tmp = "";    
            }
        }
    }
    len = n;
}

void solve() {
    
    int l = p.length();
    for (int i = 0; i < l; ++i) {
        if (p[i] == 'R') {
            if (dq.empty())
                continue;
            is_front = !is_front;
        }
            
        else if (p[i] == 'D') {
            if (dq.empty()) {
                is_error = true;
                break;
            }
            
            if (is_front)
                dq.pop_front();
            else
                dq.pop_back();
        }
    }
}

void output() {
    if (is_error)
        cout << "error" << '\n';
    else {
        cout << '[';
        if (!dq.empty()) {
            while (dq.size() != 1) {
                if (is_front) {
                    cout << dq.front() << ',';
                    dq.pop_front();
                }
                else {
                    cout << dq.back() << ',';
                    dq.pop_back();
                }
            }
            if (is_front)
                cout << dq.front();
            else
                cout << dq.back();
        }
        cout << ']' << '\n';
    }
}

int main() {
    
    fastio;
    int T; cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        
        init();
        input();
        solve();
        output();
        
    }
    
    return 0;
}