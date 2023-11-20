#include <iostream>
#include <queue>
#include <unordered_map>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    
    fastio;
    int T;
    cin >> T;
    
    for (int tc = 1; tc <= T; ++tc) {
        
        int k, cnt = 0;
        cin >> k;
        
        priority_queue <int> pq_max;
        priority_queue <int, vector<int>, greater<int>> pq_min; 
        unordered_map <int, int> maxDel;
        unordered_map <int, int> minDel;
        
        for (int i = 0; i < k; ++i) {
            char c;
            int num;
            cin >> c >> num;
        
            if (c == 'I') {
                pq_max.push(num);
                pq_min.push(num);
                cnt++;
            }
        
            else if (c == 'D') {
                if (!cnt)
                    continue;
                
                cnt--;
                if (num == 1) {
                    while (!pq_max.empty()) {
                        int x = pq_max.top();
                        if (!minDel[x]) {
                            pq_max.pop();
                            maxDel[x]++;
                            break;
                        }
                        else {
                            minDel[x]--;
                            pq_max.pop();
                        }
                    }
                }
                else if (num == -1) {
                    while (!pq_min.empty()) {
                        int x = pq_min.top();
                        if (!maxDel[x]) {
                            pq_min.pop();
                            minDel[x]++;
                            break;
                        }
                        else {
                            maxDel[x]--;
                            pq_min.pop();
                        }
                    }
                }
            }
        }
        
        if (!cnt) {
            cout << "EMPTY" << '\n';
            continue;
        }
        
        while (!pq_max.empty()) {
            int n = pq_max.top();
            if (minDel[n]) {
                pq_max.pop();
                minDel[n]--;
            }
            else {
                cout << n << ' ';
                break;
            }
        }
            
        while (!pq_min.empty()) {
            int n = pq_min.top();
            if (maxDel[n]) {
                pq_min.pop();
                maxDel[n]--;
            }
            else {
                cout << n << '\n';
                break;
            }
        }
    }
    
    return 0;
}