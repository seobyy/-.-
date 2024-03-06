#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 2'147'000'000
using namespace std;

int N;
int ans = -INF;
string str;

bool brace[25];

void input() {
    cin >> N >> str;
}

int operate(int a, int b, char x) {
    int res = 0;
    switch (x) {
        case '+':
            return a + b;
            
        case '-':
            return a - b;
            
        case '*':
            return a * b;
            
        default: return 0;
    }
}

void cal_res() {
    
    vector <int> v1;
    vector <char> v2;
    
    for (int i = 0; i < N; ++i) {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
            if (brace[i + 1]) {
                int n = operate(str[i] - '0', str[i + 2] - '0', str[i + 1]);
                v1.push_back(n);
                i += 2;
            }
            else
                v1.push_back(str[i] - '0');
        }
        else {
            if (!brace[i])
                v2.push_back(str[i]);
        }
    }
    
    
    
    int res = v1[0];
    int len = v1.size();
    int idx = 0;
    for (int i = 1; i < len; ++i) {
        res = operate(res, v1[i], v2[idx++]);
    }
    
    ans = max(ans, res);
}

void make_brace(int index) {
    
    if (index >= N) {
        cal_res();
        return;
    }
    
    if (index % 2 == 0) {
        make_brace(index + 1);
        return;
    }
    
    make_brace(index + 2);
    brace[index] = true;
    make_brace(index + 4);
    brace[index] = false;
}

void solve() {
    for (int i = 0; i < N; ++i) {
        make_brace(i);
    }
}

void output() {
    cout << ans << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}