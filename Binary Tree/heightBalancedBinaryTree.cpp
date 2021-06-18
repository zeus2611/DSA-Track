#include <bits/stdc++.h>
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
    int lh = height(root->left);
    int rh = height(root->right);

    return max(lh, rh) + 1;
}

/*
Balanced Height Tree 
<------------------->
For each node, the difference between the height of left subtree and right subtree <= 1
*/
//Time Complexity = O(N^2)
bool balanced(Node* root){
    if(root == NULL){
        return true;
    }
    if(balanced(root->left) == false){
        return false;
    }
    if(balanced(root->right) == false){
        return false;
    }
    int lh = height(root->left);
    int rh = height(root->right);
    if(abs(lh - rh) <= 1){
        return true;
    } else {
        return false;
    }
}

//Time Complexity = O(N)
bool optimizedBalanced(Node* root, int* height){
    if(root == NULL){
        return true;
    }

    int lh = 0, rh = 0;
    if(optimizedBalanced(root->left, &lh) == false){
        return false;
    }
    if(optimizedBalanced(root->right, &rh) == false){
        return false;
    }
    *height = max(lh, rh) + 1;
    if(abs(lh - rh) <= 1){
        return true;
    } else {
        return false;
    }
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

    cout << optimizedBalanced(root, &height);

}