// Reverse a string using recursion.
#include<iostream>
using namespace std;

void reverseString(string str, int index, int len) {
    if(index < len) {
        reverseString(str, index+1, len);
    }
    cout<<str[index];
}
int main() {
    string str = "DECODE";
    int len = str.length() - 1;
    reverseString(str, 0, len);
    return 0;
}