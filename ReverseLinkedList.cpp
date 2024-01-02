#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node *next;
    Node(int val) {
      data = val;
      next = NULL;
    }
};
class LinkedList {
  public:
    Node *head;
    void create(int val) {
      Node *temp, *t;
      temp = new Node(val);
      if(head == NULL) {
        head = temp;
      }
      else {
        t = head;
        while(t->next != NULL) {
          t = t->next;
        }
        t->next = temp;
      }
      
    }
};

int main() {
  LinkedList ll;
  ll.create(22);
  ll.create(23);
  ll.create(24);
  return 0;
}