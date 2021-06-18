/*
Problem Statement:-
Two nodes of a BST are swapped. Our task is to restore(correct) the BST.

Strategy:-
Inorder of a BST is sorted
Two elements in a sorted array are swapped
Maintain 3 pointers -> first, mid, last

Case 1) Swapped elements are not adjacent to each other
First: Pervious node of node at which data < previous node data
Mid: Number where data < previous node data
Last: 2nd node where number < previous
Swap First and Last

Case 2) Swapped elements are adjacent to each other
First: Pervious node of node at which data < previous node data
Mid: Number where data < previous node data
Last: NULL
Swap First and Mid

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

void calcPointers(Node* root, Node** first, Node** mid, Node** last, Node** prev){
    if(root == NULL){
        return;
    }

    calcPointers(root->left, first, mid, last, prev);

    if(*prev && root->data < (*prev)->data){
        if(!*first){
            *first = *prev;
            *mid = root;
        }
        else{
            *last = root;
        }
    }

    *prev = root;
    calcPointers(root->right, first, mid, last, prev);
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void restorBST(Node* root){
    Node* first = NULL, *mid = NULL, *last = NULL, *prev = NULL;

    calcPointers(root, &first, &mid, &last, &prev);

    if(first && last){
        swap(&(first->data), &(last->data));
    }
    else if(first && mid){
        swap(&(first->data), &(mid->data));
    }
}

int32_t main() {

}