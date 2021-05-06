// Given a binary Tree, Flatten it into linked list in-place.
// After Flattening, left of each node should point to NULL and right should contain next node in preorder Sequence.
// (Not Allowed to use other Data Structure)

// Strategy:- 
// a) Recursively, flatten left & right subTree.
// b) Store left and right tail. (tail = last node)
// c) Store right subtree in "temp" & make left subtree as right subtree
// d) Join right subtree with left tail.
// e) Recursively, return right tree

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node( int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

void flatten(Node* root){
    if(root == NULL || root->left == NULL && root->right == NULL){
        return;
    }

    if(root->left != NULL){
        flatten(root->left);

        Node* temp = root->right;
        root->right = root->left;
        root->left = NULL;

        Node* tail = root->right;
        while(tail->right != NULL){
            tail = tail->right;
        }

        tail->right = temp;
    }

    flatten(root->right);
}

int32_t main(){

}