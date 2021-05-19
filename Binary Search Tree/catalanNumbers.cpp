/*
Application of Catalan Numbers:
a) Possible BSTs from given no. of nodes
b) Parenthesis / Bracket Combinations
c) Possible forests
d) Ways of triangulation
e) Possible paths in matrix
f) Dividing a circle using N chords
g) Dyck words of given length 
and many more
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

int catalan(int n) {
    if(n <= 1){
        return 1;
    }
    int res = 0;
    for (int i = 0; i < n; i++){
        res += catalan(i) * catalan(n-i-1);
    }
    return res;
}

vector<Node*> constructTrees(int start, int end){
    vector<Node*> trees;
    if(start > end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i = start; i<=end; i++){
        vector<Node*> leftSubTree = constructTrees(start, i-1);
        vector<Node*> rightSubTree = constructTrees(i+1, end);

        for(int j=0; j<leftSubTree.size(); j++){
            Node* left = leftSubTree[j];
            for(int k=0; k<rightSubTree.size(); k++){
                Node* right = rightSubTree[k];
                Node* node = new Node(i);
                node->left = left;
                node->right = right;
                trees.push_back(node);
            }
        }
    }

    return trees;
}

int32_t main() {
    
}