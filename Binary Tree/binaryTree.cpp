/*
Binary Tree
can have maximun 2 childres:
    left child
    right child
Properties:
    a) Maximun nodes at level L = 2^L
    b) Maximun nodes in a tree of height H is 2^(H) -1
    c) For N nodes,Minimun possible height or minimun number of levels are log(base 2) (N+1)
    d) 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }    
};

void preOrder( Node* root){
/*  a) print root value
    b) go in left Subtree, traverse and when left subtree is fully traversed
    c) go in right Subtree, traverse
*/
    if(root == NULL)
        return;
    cout << root->data<< " ";
    preOrder(root->left);
    preOrder(root->right);
}
void inOrder( Node* root){
/*  a) go in left Subtree, traverse and when left subtree is fully traversed
    b) print root value
    c) go in right Subtree, traverse
*/
    if(root == NULL)
        return;
    inOrder(root->left);
    cout << root->data<< " ";
    inOrder(root->right);
}
void postOrder( Node* root){
/*  a) go in left Subtree, traverse and when left subtree is fully traversed
    b) go in right Subtree, traverse
    c) print root value
*/
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data<< " ";
}

int32_t main(){
    /*
              1
            /  \
           2    3
          / \  / \
         4  5 6  7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preOrder(root);
    inOrder(root);
    postOrder(root);
}