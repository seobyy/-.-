#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#define MAX_C 30
using namespace std;

int clothes_cnt;
vector <string> v[MAX_C + 5];
unordered_map <string, int> um;

int solution(vector <vector<string>> clothes) {

    for (auto i : clothes) {
        vector <string> tmp = i;
        if (!um[tmp[1]]) {
            um[tmp[1]] = ++clothes_cnt;
            int n = um[tmp[1]];
            v[n].push_back(tmp[0]);
        }
        else {
            int n = um[tmp[1]];
            v[n].push_back(tmp[0]);
        }
    }
    
    int ans = 1;
    for (int i = 1; i <= clothes_cnt; ++i) {
        ans *= (v[i].size() + 1);
    }

    return ans - 1;
}