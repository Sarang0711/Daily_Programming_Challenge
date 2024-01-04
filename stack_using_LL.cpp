#include<iostream>
using namespace std;

class node {
  public: 
    int data;
    node *next;  
    node(int val) {
      data = val;
      next = NULL;
    }
};
class Stack {
  public:
    node *top;
    Stack() {
      top = NULL;
    }
    bool isEmpty() {
      if(top == NULL) {
        return 1;
      }
      return 0;
    }
    void push(int val) {
      node *temp;
      temp = new node(val);
      if(isEmpty()) {
        top = temp;
      }
      else {
        temp->next = top;
        top = temp;
      }
    }
    void peek() {
      if(!isEmpty()) {
        cout<<top->data<<endl;
      }
    }
    void pop() {
      if(isEmpty()) {
        cout<<"Stack underflow, no element to pop \n";
      }
      else {
        node *temp;
        temp = top;
        top = top->next;
        delete temp;
      }
    }
};

int main() {
  Stack stk;
  stk.push(22);
  stk.peek();
  return 0;
}