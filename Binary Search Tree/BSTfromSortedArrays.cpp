/*
1) Make middle element the root
2) Recursively, do same for subtrees
    a) start to mid-1 for left subtree
    b) mid+1 to end for right subtree
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node* sortedArrayToBST(int arr[], int start, int end){
    if(start > end){
        return NULL;
    }
    int mid = (start + end)/2;
    Node* root = new Node(arr[mid]);

    root->left = sortedArrayToBST(arr, start, mid-1);
    root->right = sortedArrayToBST(arr, mid+1, end);

    return root;
}

void preOrder(Node* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int32_t main() {
    int arr[] = {10,20,30,40,50};
    Node* root = sortedArrayToBST(arr, 0, 4);
    preOrder(root);
    cout << endl;
}