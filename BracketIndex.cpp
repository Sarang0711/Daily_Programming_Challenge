// Given a string with brackets. If the start index of the open bracket is given, find the index of the closing bracket.

#include <iostream>
#include<stack>
using namespace std;

int calculateIndex(string str, int len, int ind) {
    stack<char>stk;
    for(int i=ind+1; i<len; i++) {
        if(str[i] == '[') {
            stk.push(str[i]);
        }
        else if(str[i] == ']' && !stk.empty()) {
            stk.pop();
            // continue;
        }
        else if(str[i] == ']' && stk.empty()) {
            return i;
        }
    }
    return -1;
}

int main()
{
    string str = "[ABC[23]][89]";
    int len = str.length();
    int ind = 9;
    cout<<calculateIndex(str, len, ind);
    return 0;
}