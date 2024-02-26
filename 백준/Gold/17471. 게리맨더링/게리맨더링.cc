#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define INF 2'147'000'000
using namespace std;

int N;
int ans = INF;
int target;
int people[15];
bool selected[15];
bool adj[15][15];

bool chk1[15];
bool chk2[15];

void input() {
    cin >> N;
    for (int i = 1; i <= N; ++i) 
        cin >> people[i];
    
    for (int i = 1; i <= N; ++i) {
        int n; cin >> n;
        for (int j = 0; j < n; ++j) {
            int num; cin >> num;
            adj[i][num] = true;   
        }
    }
}

void check_area() {
    
    memset(chk1, false, sizeof(chk1));
    memset(chk2, false, sizeof(chk2));
    
    queue <int> q1;
    queue <int> q2;
    
    for (int i = 1; i <= N; ++i) {
        if (selected[i]) { 
            q1.push(i);
            break;
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (!selected[i]) { 
            q2.push(i);
            break;
        }
    }
    
    while (!q1.empty()) {
        int n = q1.front();
        q1.pop();
        
        chk1[n] = true;
        for (int i = 1; i <= N; ++i) {
            if (adj[n][i] && selected[i] && !chk1[i]) 
                q1.push(i);
        }    
    }
    
    while (!q2.empty()) {
        int n = q2.front();
        q2.pop();
        
        chk2[n] = true;
        for (int i = 1; i <= N; ++i) {
            if (adj[n][i] && !selected[i] && !chk2[i]) 
                q2.push(i);
        }    
    }
    
    bool can_divide = true;
    for (int i = 1; i <= N; ++i) {
        if (selected[i] && !chk1[i]) {
            can_divide = false;
            break;
        }
        else if (!selected[i] && !chk2[i]){
            can_divide = false;
            break;
        }
    }
    
    if (can_divide) {
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i <= N; ++i) {
            if (selected[i]) sum1 += people[i];
            else sum2 += people[i];
        }
        ans = min(ans, abs(sum1 - sum2));
    }
}

void sel_area(int index, int cnt) {
    
    if (cnt == target) {
        check_area();
        return;
    }
    
    for (int i = index; i <= N; ++i) {
        selected[i] = true;
        sel_area(i + 1, cnt + 1);
        selected[i] = false;
    }
}

void solve() {
    for (target = 1; target <= N / 2; ++target) {
        memset(selected, false, sizeof(selected));
        sel_area(1, 0);
    }
}

void output() {
    if (ans == INF) cout << -1 << '\n';
    else cout << ans << '\n';
}

int main() {
    
    fastio;
    input();
    solve();
    output();
    
    return 0;
}