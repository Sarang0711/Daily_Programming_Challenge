#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<stack>
using namespace std;

// Using Vector
void reverseKElement(queue<int> que, int k) {
    vector<int> vec;

    while(!que.empty()) {
        int ele = que.front();
        vec.push_back(ele);
        que.pop();
    }
    reverse(vec.begin(), vec.begin()+k);

    for(int i=0; i<vec.size(); i++) {
        que.push(vec[i]);
        cout<<vec[i]<<" ";
    }
}

// Using Stack 
void reverseQ(queue<int> que, int k) {
    stack<int> stk;
    int size = que.size();
    for(int i=0; i<k; i++) {
        stk.push(que.front());
        que.pop();
    }
    while(! stk.empty()) {
        int ele = stk.top();
        que.push(ele);
        stk.pop();
    }
    for(int i=0; i<size-k; i++) {
        int ele = que.front();
        que.pop();
        que.push(ele);
    }
    while(! que.empty()) {
        cout<<que.front();
        que.pop();
    }
}

int main() {
    queue <int> que;
    que.push(1);
    que.push(2);
    que.push(3);
    que.push(4);
    que.push(5);
    int k;
    cout<<"Enter how many elements you want to reverse \n";
    cin>>k;
    // reverseKElement(que, k);
    reverseQ(que, k);
    return 0;
}