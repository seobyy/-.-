#include <iostream>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    
    fastio;
    string str;
    cin >> str;
    
    bool is_minus = false;
    string tmp = "";
    int len = str.size();
    int ans = 0;
    
    for (int i = 0; i <= len; ++i) {
        
        if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
            
            if (is_minus)
                ans -= stoi(tmp);
            else
                ans += stoi(tmp);
            
            tmp = ""; 
            if (str[i] == '-')
                is_minus = true;
        }
        else
            tmp += str[i];
        
    }
    
    cout << ans << '\n';
    
    return 0;
}