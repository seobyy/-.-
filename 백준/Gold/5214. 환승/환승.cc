#include <iostream>
#include <vector>
#include <queue>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 100'000
#define MAX_M 1000
using namespace std;

struct POS {int dis; int n;};

int N, K, M;
int ans = -1;
vector <int> hypertube[MAX_M + 5];
vector <int> stationNum[MAX_N + 5];
bool visited[MAX_N + 5];

void bfs() {
    
    queue <POS> q;
    q.push({1, 1});
    visited[1] = true;
    
    while (!q.empty()) {
        
        int d = q.front().dis;
        int n = q.front().n;
        q.pop();
        
        if (n == N) {
            ans = d;
            break;
        }
        
        for (auto hNum : stationNum[n]) {
            for (auto i : hypertube[hNum]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push({d + 1, i});
                }
            }
        }
    }
}

int main() {
    
    fastio;
    cin >> N >> K >> M;
    
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < K; ++j) {
            int n;
            cin >> n;
            hypertube[i].push_back(n);
            stationNum[n].push_back(i);
        }
    }
    
    bfs();
    
    cout << ans << '\n';
    
    return 0;
}