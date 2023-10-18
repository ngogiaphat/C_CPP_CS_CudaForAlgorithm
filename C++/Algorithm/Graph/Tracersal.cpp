#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;
};
// recursive function to traverse the tree by preorder
void preOrder(Node *node){
    if(node == NULL){
        return;
    };
    cout << node -> data << " ";
    preOrder(node -> left);
    preOrder(node -> right);
};
int main(){
    // create simple binary tree
    Node* root = new Node();
    root -> data = 1;
    Node* left = new Node();
    left -> data = 2;
    Node* right = new Node();
    right -> data = 3;
    root -> left = left;
    root -> right = right;
    // check tree by preorder
    preOrder(root);
    return 0;
};