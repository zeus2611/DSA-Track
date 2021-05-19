/*
Problem Statement:-
For given root nodes of 2 binary search trees, print if the BSTs are identical or not. Identical BSTs are structurally identical & have equal values for the nodes in the structure.

Strategy:-
1) If both empty, return true
2) If both not empty,
    a) Check that the data at nodes is equal
    b) Check if left subtree are same
    c) Check if right subtree are same

3) if(a,b,c) are true, return true
    else return false
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

bool isIdentical(Node* root1, Node* root2) {
    if (root1 == NULL && root2 == NULL) {
        return true;
    }
    else if (root1 == NULL || root2 == NULL) {
        return false;
    }
    else {
        bool cond1 = root1->data == root2->data;
        bool cond2 = isIdentical(root1->left, root2->left);
        bool cond3 = isIdentical(root1->right, root2->right);

        if(cond1 && cond2 && cond3){
            return true;
        }
        return false;
    }

}

int32_t main() {

}