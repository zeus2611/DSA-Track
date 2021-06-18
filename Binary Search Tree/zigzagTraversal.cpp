/*
At every level we change the direction in which we a printing the value of nodes
e.g. if in 1st level we are printing in left to right then in 2nd level we will be printing in right to left direction.

Strategy:-
1) Use 2 stacks - currentLevel & nextLevel
2) variable LeftToRight
3) If LeftToRight, push left child then right
   else push right child then left
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void zigzagTrav(Node *root){
    stack<Node *> currLevel;
    stack<Node *> nextLevel;

    bool leftToRight = true;

    currLevel.push(root);

    while (!currLevel.empty()){
        Node* temp = currLevel.top();
        currLevel.pop();

        if (temp){
            cout << temp->data << " ";

            if (leftToRight){
                if (temp->left){
                    nextLevel.push(temp->left);
                }
                if (temp->right){
                    nextLevel.push(temp->right);
                }
            }
            else{
                if (temp->right){
                    nextLevel.push(temp->right);
                }
                if (temp->left){
                    nextLevel.push(temp->left);
                }
            }
        }
        if(currLevel.empty()){
            leftToRight = !leftToRight;
            swap(currLevel,nextLevel);
        }
    }
}

int32_t main(){

}