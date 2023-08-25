// You are given a binary tree. A binary tree is considered balanced if the heights of the two subtrees of any node never differ by more than 1. Write a code to determine if a given binary tree is balanced or not.

#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node *left;
        Node *right;
        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

int calculateHeight(Node* t1){
    if(t1 == NULL) {
        return 0;
    }
    int lheight = calculateHeight(t1->left) + 1;
    int rheight = calculateHeight(t1->right) + 1;

    if(lheight == -1 || rheight == -1) {
        return -1;
    }
    if(abs(lheight - rheight) > 1){
        return -1;
    }
    return max(lheight, rheight);
    
}
bool isBalanced(Node * t1) {
    int h = calculateHeight(t1);
    if(h == -1) {
        return false;
    }
    return true;
}
int main() {
    Node *head = NULL;
    Node *temp = new Node(25);

    if(head == NULL) {
        head = temp;
    }

    temp->left = new Node(30);
    temp->right = new Node(40);
    temp->left->left = new Node(50);
    temp->left->left->left = new Node(23);
    temp->left->left->left->left = new Node(23);
    temp->left->right = new Node(45);
    temp->right->left = new Node(60);
    temp->right->right = new Node(60);
    if(! isBalanced(head)) {
        cout<<"Not balanced \n";
    }
    else {
        cout<<"balanced \n";
    }
    return 0;
}