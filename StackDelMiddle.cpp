// Given a stack with push(), pop(), and empty() operations, The task is to delete the middle element of it without using any additional data structure.

#include<iostream>
#include<stack>
using namespace std;


void delMiddle(stack<int> stk, int size, int count) {
    if(stk.empty()) {
        return;
    }
    if(size == 1) {
        stk.pop();
        return;
    }
    
    if(!stk.empty()) {
        int top = stk.top();
        stk.pop();
        delMiddle(stk, size, count+1);

        if(count != size/2) {
            stk.push(top);
            cout<<top<<endl;
        }
    }
}



int main() {
    stack<int> stk;
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    stk.push(60);
    stk.push(70);

    int count = 0;
    int curr = 0;
    int size = stk.size();
    delMiddle(stk, size, count);
    return 0;
}