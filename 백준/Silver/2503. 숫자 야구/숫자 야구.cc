#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

using namespace std;

int ans;
bool canAns[1005];

int main() {
    
    fastio;
    int N; cin >> N;
    memset(canAns, true, sizeof(canAns));
    for (int i = 0; i < N; ++i) {
        int n, s, b;
        cin >> n >> s >> b;
        
        int real1 = n / 100;
        int real2 = (n / 10) % 10;
        int real3 = n % 10;
        
        bool nums[15];
        memset(nums, false, sizeof(nums));
        nums[real1] = true;
        nums[real2] = true;
        nums[real3] = true;
        
        for (int num = 100; num <= 999; ++num) {
            
            if (!canAns[num])
                continue;
            
            int sCnt = 0, bCnt = 0;
            
            int n1 = num / 100;
            int n2 = (num / 10) % 10;
            int n3 = num % 10;
            
            
            if (n1 == n2 || n2 == n3 || n3 == n1 ||
                !n1 || !n2 || !n3) {
                canAns[num] = false;
                continue;
            }
            
            if (n1 == real1) sCnt++;
            else if (nums[n1]) bCnt++;
            
            if (n2 == real2) sCnt++;
            else if (nums[n2]) bCnt++;
            
            if (n3 == real3) sCnt++;
            else if (nums[n3]) bCnt++;
            
            //cout << num << ' ' << sCnt << " " << bCnt << '\n';
            
            
            if (sCnt == s && bCnt == b) 
                canAns[num] = true;
            else
                canAns[num] = false;
        }
        
    }
    
    for (int i = 100; i <= 999; ++i) {
        if (canAns[i]) 
            ans++;
    }
    
    cout << ans << '\n';
    
    return 0;
}