/*
Approach 1:-
node > left child
node < right child
but no effective as
        4
      /   \
    2       7
  /       /   \
1       3       8
it satisfies the above condition but s=is not BST

Approach 2:-
find Max of left subTree (maxL)
find Min of right subTree (minR)
node > maxL
node < minR

Approach 3:-
Modification of Approach 2
traverse node once
min allowed < node
max allowed > node
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

// Time Complexity = O(N) 
bool isBST(Node* root, Node* minA = NULL, Node* maxA = NULL){
    if(root == NULL){
        return true;
    }
    if(minA != NULL && root->data <= minA->data){
        return false;
    }
    if(maxA != NULL && root->data >= maxA->data){
        return false;
    }
    bool leftValid = isBST(root->left, minA, root);
    bool rightValid = isBST(root->right, root, maxA);

    return leftValid and rightValid; 
}

int32_t main() {

}