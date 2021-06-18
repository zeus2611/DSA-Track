/*
Strategy:-
For each node store the following info:
1) min in subtree
2) max in subtree
3) subtree size
4) size of largest BST
5) isBST

Recursively, traverse in bottom-up manner & find out the size of the largest BST
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

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBST(Node* root){
    if(root == NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    if(root->left == NULL && root->right == NULL){
        return {1, root->data, root->data, 1, true};
    }
    
    Info leftInfo = largestBST(root->left);
    Info rightInfo = largestBST(root->right);

    Info curr;
    curr.size = (1 + leftInfo.size + rightInfo.size);

    if(leftInfo.isBST && rightInfo.isBST && leftInfo.max < root->data && rightInfo.min > root->data){
        curr.min = min(leftInfo.min , min(rightInfo.min, root->data));
        curr.max = max(rightInfo.max , min(leftInfo.max, root->data));

        curr.ans = curr.size;
        curr.isBST = true;

        return curr;
    }

    curr.ans = max(leftInfo.ans, rightInfo.ans);
    curr.isBST = false;

    return curr;
}

int32_t main() {

}