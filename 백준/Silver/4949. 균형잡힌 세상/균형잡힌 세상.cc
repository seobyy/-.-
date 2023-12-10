#include <iostream>
#include <sstream>
#include <stack>
#define fastio ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
    
    fastio;
    while (1) {
        
        string str;
        getline(cin, str);
        if (str[0] == '.' && str.length() == 1)
            break;
        stringstream ss(str);
        bool isBalanced = true;
        
        stack <char> stack;
        string s;
        while (getline(ss, s, ' ')) {
            int len = s.length();
            for (int i = 0; i < len; ++i) {
                if (s[i] == '(' || s[i] == '[') 
                    stack.push(s[i]);
                else if (s[i] == ')') {
                    if (stack.empty())
                        isBalanced = false;
                    else {
                        if (stack.top() == '[')
                            isBalanced = false;
                        stack.pop();
                    }
                }
                else if (s[i] == ']') {
                    if (stack.empty())
                        isBalanced = false;
                    else {
                        if (stack.top() == '(')
                            isBalanced = false;
                        stack.pop();
                    }
                }
            }
        }
        
        if (!stack.empty())
            isBalanced = false;
        if (isBalanced)
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
        
    }
    
    return 0;
}