#include<bits/stdc++.h>
using namespace std;
// define node structure in binary tree
struct Node {
    int data;
    Node *left;
    Node *right;
    int height;
};
// calc height of node
int height(Node *node){
    if(node == NULL){
        return 0;
    };
    return node -> height;
};
// create new node
Node *newNode(int data){
    Node *newNode = new Node();
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    newNode -> height = 1;
    return newNode;
};
// turn left at node y
Node *leftRotate(Node *y){
    Node *x = y -> right;
    Node *T2 = x -> left;
    x -> left = y;
    y -> right = T2;
    y -> height = max(height(y -> left), height(y -> right)) + 1;
    x -> height = max(height(x -> left), height(x -> right)) + 1;
    return x;
};
// get the equilibrium number of a node
int getBalanceFactor(Node *node){
    if(node == NULL){
        return 0;
    };
    return height(node -> left) - height(node -> right);
};
// insert new node to binary tree
Node *insertNode(Node *node, int data){
    if(node == NULL){
        return newNode(data);
    };
    if(data < node -> data){
        node -> left = insertNode(node -> left, data);
    }
    else if(data > node -> data){
        node -> right = insertNode(node -> right, data);
    }
    else {
        return node;
    };
    node -> height = std::max(height(node -> left), height(node -> right)) + 1;
    int balanceFactor = getBalanceFactor(node);
    // check balance and turn around tree to balance
    if(balanceFactor > 1){
        if(data < node -> left -> data){
            return rightRotate(node);
        }
        else if(data > node -> left -> data){
            node -> left = leftRotate(node -> left);
            return rightRotate(node);
        };
    };
    if(balanceFactor < -1){
        if(data > node -> right -> data){
            return leftRotate(node);
        }
        else if(data < node -> right -> data){
            node -> right = rightRotate(node -> right);
            return leftRotate(node);
        };
    };
    return node;
};
// to print binary tree
void preOrder(Node *node){
    if(node != NULL){
        return;
        preOrder(node -> left);
        cout << node -> data << " ";
        preOrder(node -> right);
    };
};
int main(){
    Node *root = NULL;
    // insert elemnets to binary tree
    root = insertNode(root, 10);
    root = insertNode(root, 20);
    root = insertNode(root, 30);
    root = insertNode(root, 40);
    root = insertNode(root, 50);
    root = insertNode(root, 25);
    cout << "Preorder traversal of the constructed AVL tree is: ";
    preOrder(root);
    return 0;
};