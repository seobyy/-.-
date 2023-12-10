#include <iostream>
#include <stack>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    
    fastio;
    int N;
    cin >> N;
    
    int cnt = 0;
    for (int i = 0; i < N; ++i) {
        string str;
        cin >> str;
        bool isGoodWord = true;
        int len = str.length();

        stack <char> stack;
        for (int i = 0; i < len; ++i) {
            if (stack.empty())
                stack.push(str[i]);
            else {
                if (stack.top() == str[i])
                    stack.pop();
                else
                    stack.push(str[i]);
            }
        }
        
        if (!stack.empty())
            isGoodWord = false;
            
        if (isGoodWord)
            cnt++;
    }
    
    cout << cnt << '\n';
    
    return 0;
}