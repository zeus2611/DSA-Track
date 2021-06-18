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

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

// Diameter = Number of nodes in longest path beween any 2 Leaves
// Time Complexity = O(N^2)
int diameter(Node* root){
    if(root == NULL){
        return 0;
    }
    int lHeight = height(root->left);
    int rHeight = height(root->right);
    int currDiamete = lHeight + rHeight + 1;

    int lDiameter = diameter(root->left);
    int rDiameter = diameter(root->right);

    return max(currDiamete, max(lDiameter, rDiameter));
}

//Time Complexity = O(N)
int optimizedDiameter(Node* root, int* height){
    if(root == NULL){
        *height = 0;
        return 0;
    }
    int lh = 0, rh = 0;
    int lDiameter = optimizedDiameter(root->left, &lh);
    int rDiameter = optimizedDiameter(root->right, &rh);

    int currDiameter = lh + rh + 1;
    *height = max(lh, rh) +1;

    return max(currDiameter, max(lDiameter, rDiameter));
}

int32_t main(){
    int height = 0;
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout<< diameter(root) << "\n";
    cout << optimizedDiameter(root, &height) << "\n";
}