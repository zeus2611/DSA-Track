#include<iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
    
    node(int val){
        data=val;
        next=NULL;
    }
};

class queue{
    node* front;
    node* back;

    public:
        queue(){
            front=NULL;
            back=NULL;
        }

    void push(int x){
        node* n=new node(x);

        if(front==NULL){
            back=n;
            front=n;
            return;
        }
        back->next=n;
        back=n;
    }

    void pop(){
        if(front=NULL){
            cout << "Queue Underflow\n";
            return;
        }

        node* todelete=front;
        front=front->next;

        delete todelete;
    }

    int peek(){
        if(front==NULL){
            cout << "No element in queue\n";
            return;
        }

        return front->data;
    }

    bool empty(){
        if(front==NULL) 
            return true;
        else
            return false;
    }
};

int32_t main(){

    return 0;
}