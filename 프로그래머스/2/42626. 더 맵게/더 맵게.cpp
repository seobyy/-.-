#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    int ans = 0;
    priority_queue <int, vector<int>, greater<int>> pq;
    
    for (auto i : scoville) {
        pq.push({i});
    }
    while (!pq.empty()) {
        int a1 = pq.top();
        pq.pop();
        
        if (a1 >= K)
            break;
        if (pq.empty()) {
            ans = -1;
            break;
        }
        
        int a2 = pq.top();
        pq.pop();
        
        int new_sco = a1 + a2 * 2;
        pq.push(new_sco);
        ans++;
    }
    
    return ans;
}