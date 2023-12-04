#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX_N 500'000
using namespace std;

int rTower[MAX_N + 5];
unordered_map <int, int> towerIndex;

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    stack <int> stack;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        towerIndex[n] = i + 1;
        stack.push(n);
    }
    
    priority_queue <int, vector<int>, greater<int>> pq;
    while (!stack.empty()) {
        int n = stack.top();
        stack.pop();
        while (!pq.empty()) {
            int x = pq.top();
            if (n > x) {
                rTower[towerIndex[x]] = towerIndex[n];
                pq.pop();
            }
            else
                break;
        }
        pq.push(n);
    }
    
    for (int i = 1; i <= N; ++i) {
        cout << rTower[i] << ' ';
    }
    cout << '\n';
    
    return 0;
}