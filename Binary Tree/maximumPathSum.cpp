/*
Maximum possible sum of a path in the binary tree, starting and ending at any node.
Strategy:
1) Node val
2) Max path through left child + node val
3) Max path through right child + node val
4) Max path through left child + Max path through right child + node val
*/

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

int maxPathSumUtil(Node* root, int &ans){
    if(root == NULL){
        return 0;
    }

    int left = maxPathSumUtil(root->left, ans);
    int right = maxPathSumUtil(root->right, ans);

    int nodeMax = max( max(root->data, root->data + left + right), max(root->data + left, root->data + right));

    ans = max(ans, nodeMax);

    int singlePathSum = max(root->data, max(root->data + left, root->data + right));

    return singlePathSum;
}

int maxPathSum(Node* root){
    int ans = INT_MIN;
    maxPathSumUtil(root, ans);
    
    return ans;
}

int32_t main(){

}