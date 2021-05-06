/*

*/

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

// Case 1
void printSubTreeNode(Node* root, int k){
    if(root == NULL || k < 0){
        return;
    }

    if(k == 0){
        cout << root->data << " ";
        return;
    }

    printSubTreeNode(root->left, k-1);
    printSubTreeNode(root->right, k-1);
}

//Case 2
int printNodesAtK(Node* root, Node* target, int k){
    if(root == NULL){
        return -1;
    }
    if(root == target){
        printSubTreeNode(root, k);
        return 0;
    }
    int dl = printNodesAtK(root->left,target, k);
    if(dl != -1){
        if(dl+1 == k){
            cout << root->data<< " ";
        } else {
            printSubTreeNode(root->right, k-dl-2);
        }
        return dl+1;
    }
    int dr = printNodesAtK(root->right,target, k);
    if(dr != -1){
        if(dr+1 == k){
            cout << root->data<< " ";
        } else {
            printSubTreeNode(root->left, k-dr-2);
        }
        return dr+1;
    }

    return -1;
}

int32_t main(){

}