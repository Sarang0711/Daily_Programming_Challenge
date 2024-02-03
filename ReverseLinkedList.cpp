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


// Leetcode


//  * Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 

 //* Recursion


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *newHead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newHead;

    }
};


//* Iterative

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *tempnext;
        while(curr != NULL) {
            tempnext = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tempnext;
        }
      
        return prev;

    }
};

