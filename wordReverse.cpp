//You are given a string S, the task is to reverse the string word by word.

// Input - "i love programming"
// Input - "programming love i"

#include<iostream>
using namespace std;

void reverse(string str, int n) {
    string ans = "";
    int end = n-1;
    for(int i=n; i>=0; i--) {
        int start=i;
        if(str[i] == ' ' || i==0) { 
            ans = ans + str.substr(start, end);
            end = start;
            start = i;
        }
    }
    cout<<ans;
}

int main() {
    string str= "i love programming";
    int len = str.length();
    reverse(str, len);
    return 0;
}