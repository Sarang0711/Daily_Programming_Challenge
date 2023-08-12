// You're given a string S,  consisting of "{", "}", "(", ")", "[" and "]". Return true is S is balanced, else return false.

#include<iostream>
#include<stack>
using namespace std;

bool checkParenthesis(string str, int len) {
    stack<char>stk;
    for(int i=0; i<len; i++) {
        if(str[i] == '(' || str[i] == '[' || str[i] == '{') {
            stk.push(str[i]);
        }
        else if(str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if(!stk.empty()) {
                char ch = stk.top();
                if((ch == '(' && str[i] == ')') || (ch == '[' && str[i] == ']') || (ch == '{' && str[i] == '}')) {
                    stk.pop();
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
    return stk.empty();
}

int main() {
    string str = "[()][{[()]}]";
    int len = str.length();
    if(checkParenthesis(str, len)) {
        cout<<"The parenthesis are balanced \n";
    }
    else {
        
        cout<<"The parenthesis are not balanced \n";
    }

    return 0;
}