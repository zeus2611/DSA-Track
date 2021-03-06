/*
LCA = Point of path change when we go from root to node
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

bool getPath(Node* root, int k, vector<int> path){
    if(root == NULL){
        return false;
    }
    path.push_back(root->data);
    if(root->data == k){
        return true;
    }
    if(getPath(root->left, k, path) || getPath(root->right, k, path)){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){
    vector<int> path1, path2;

    if(!getPath(root, n1, path1) || !getPath(root, n2, path2)){
        return -1;
    }

    int pc; // pc= pathChange
    for(pc = 0; pc<path1.size() && path2.size(); pc++){
        if(path1[pc] != path2[pc]){
            break;
        }
    }

    return path1[pc-1];
}

Node* optimizedLCA(Node* root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }

    if(root->data == n1 || root->data == n2){
        return root;
    }

    Node* leftLCA = optimizedLCA(root->left, n1, n2);
    Node* rightLCA = optimizedLCA(root->right, n1, n2);

    if(leftLCA && rightLCA ){
        return root;
    }

    if(leftLCA != NULL){
        return leftLCA;
    }
    
    return rightLCA;
}

int32_t main() {

}