#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 1'000'000
using namespace std;

struct POS {
    int dis;
    int num;
    vector <int> v;
};

int N;
bool visited[MAX_N + 5];

void bfs() {
    
    visited[N] = true;
    vector <int> v;
    queue <POS> q;
    q.push({0, N, v});
    
    while (!q.empty()) {
        
        int d = q.front().dis;
        int num = q.front().num;
        vector <int> v = q.front().v;
        v.push_back(num);
        q.pop();
        
        if (num == 1) {
            cout << d << '\n';
            for (auto i : v) {
                cout << i << ' ';
            }
            return;
        }
        
        
        if (num % 3 == 0 && !visited[num / 3]) {
            visited[num / 3] = true;
            q.push({d + 1, num / 3, v});
        }
        
        if (num % 2 == 0 && !visited[num / 2]) {
            visited[num / 2] = true;
            q.push({d + 1, num / 2, v});
        }
        
        if (!visited[num - 1]) {
            visited[num - 1] = true;
            q.push({d + 1, num - 1, v});
        }
    }
}


int main() {
    
    fastio;
    cin >> N;
    
    bfs();
    
    return 0;
}