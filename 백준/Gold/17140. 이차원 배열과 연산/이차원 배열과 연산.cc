#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct NUM { int n; int cnt; };
struct cmp {
    bool operator()(NUM a, NUM b) {
        if (a.cnt == b.cnt)
            return a.n > b.n;
        return a.cnt > b.cnt;
    }
};

int r, c, k;
int cur_r = 3, cur_c = 3;
int ans = -1;

int A[105][105];
int cnt[105];

void input() {
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j)
            cin >> A[i][j];
    }
}

void R() {
    for (int i = 1; i <= cur_r; ++i) {
        priority_queue <NUM, vector<NUM>, cmp> pq;
        memset(cnt, 0, sizeof(cnt));
        for (int j = 1; j <= cur_c; ++j) 
            cnt[A[i][j]]++;
        
        for (int k = 1; k <= 100; ++k) {
            if (cnt[k]) 
                pq.push({k, cnt[k]});
        }
        
        int st = 1;
        while (!pq.empty()) {
            int n = pq.top().n;
            int c = pq.top().cnt;
            pq.pop();
            
            A[i][st] = n;
            A[i][st + 1] = c;
            
            st += 2;
            cur_c = max(cur_c, st - 1);
            if (st > 99)
                break;
        }
        
        for (int j = st; j <= cur_c; ++j)
            A[i][j] = 0;
        
    }
}

void C() {
    for (int j = 1; j <= cur_c; ++j) {
        priority_queue <NUM, vector<NUM>, cmp> pq;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 1; i <= cur_r; ++i) 
            cnt[A[i][j]]++;
        
        for (int k = 1; k <= 100; ++k) {
            if (cnt[k]) 
                pq.push({k, cnt[k]});
        }
        
        int st = 1;
        while (!pq.empty()) {
            int n = pq.top().n;
            int c = pq.top().cnt;
            pq.pop();
            
            A[st][j] = n;
            A[st + 1][j] = c;
            
            st += 2;
            cur_r = max(cur_r, st - 1);
            if (st > 99)
                break;
        }
        
        for (int i = st; i <= cur_r; ++i)
            A[i][j] = 0;
        
    }
}

void solve() {
    int turn = 0;
    while (turn <= 100) {
        if (A[r][c] == k) {
            ans = turn;
            break;
        }
        
        if (cur_r >= cur_c) R();
        else C();
        /*
        for (int i = 1; i <= cur_r; ++i) {
            for (int j = 1; j <= cur_c; ++j)
                cout << A[i][j] << ' ';
            cout << '\n';
        }
        cout << '\n';
        */
        turn++;
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