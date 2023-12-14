#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

void display(Node *t) {
   if(t == NULL) {
    return;
   }
   cout<<t->data<<" ";
   display(t->left);
   display(t->right);
    
}

int main()
{
    Node *root = NULL;
    Node *temp = new Node(40);
    if (root == NULL)
    {
        root = temp;
    }
    root->left = new Node(30);
    root->right = new Node(50);
    root->left->left = new Node(10);
    root->left->right = new Node(20);
    root->right->left = new Node(45);
    root->right->right = new Node(60);
    display(root);
    return 0;
}

// Given a Binary Tree and a key, write a function that returns the level of the key.
