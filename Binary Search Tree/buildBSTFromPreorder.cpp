#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Time Complexity = O(N)
Node* constructBST(int preorder[], int* preorderIdx, int val, int min, int max, int n){
    if(*preorderIdx >= n){
        return NULL;
    }
    
    Node* root = NULL;
    if(val > min && val < max){
        root = new Node(val);
        *preorderIdx = *preorderIdx + 1;

        if(*preorderIdx < n){
            root->left = constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, val, n);
        }
        if(*preorderIdx < n){
            root->right = constructBST(preorder, preorderIdx, preorder[*preorderIdx], val, max, n);
        }
    }

    return root;
}

int32_t main() {
    int preorder[] = {10, 2, 1, 13, 11};
    int n = 5;
    int preorderIdx = 0;
    Node* root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);
    inorder(root);

}