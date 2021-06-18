/*
Rule 1 - The left subtree of a node contains only nodes with keys lesser than the node's key.
Rule 2 - The right subtree of a node contains only nodes with keys greater than the node's key.
Rule 3 - The left and right subtree each must be a binary search tree. There must be no dublicate node.

inOrder function gives us a sorted sequence of nodes
*/

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

Node * insertBST(Node *root, int val){
    if(root == NULL){
        return new Node(val);
    }

    if ( val < root->data){
        root->left = insertBST(root->left, val);
    } else {
        root->right = insertBST(root->right, val);
    }

    return root;
}

// Time Complexity = O(log N)
Node* searchBST(Node* root, int val){
    if(root == NULL){
        return NULL;
    }
    if(root->data == val){
        return root;
    }
    if(root->data > val){
        return searchBST(root->left,val);
    }
    return searchBST(root->right,val);
}

Node* inorderSucc(Node* root){
    Node * curr = root;
    while(curr && curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

Node* deleteBST(Node* root, int val){
    if(val < root->data){
        root->left = deleteBST(root->left, val);
    }
    else if(val > root->data){
        root->right = deleteBST(root->right, val);
    }
    else{
        if(root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node* temp  = root->left;
            free(root);
            return temp;
        }
        Node* temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = deleteBST(root->right, temp->data);
    }
    return root;
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " "; 
    inorder(root->right);
}

int32_t main() {
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    inorder(root);
    cout << "\n";
    root = deleteBST(root, 2);
    inorder(root);
    cout << "\n";

}