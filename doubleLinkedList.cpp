#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;
        node* prev;

        node(int val){
            prev = NULL;
            data = val;
            next = NULL;
        }
};

void insertAtHead(node* &head, int val){
    node* m = new node(val);
    m->next = head;
    if(head != NULL){
        head->prev = m;
    }
    head = m;
}

void insertAtTail(node* &head, int val){
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }

    node* n = new node(val);
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
}

void display(node* head){
    node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

void deleteAtHead(node* &head){
    node* toDelete = head;
    head = head->next;
    head->prev = NULL;
    delete toDelete;
}

void deletion(node* &head, int pos){
    if(pos == 1){
        deleteAtHead(head);
        return;
    }

    node* temp = head;
    int count = 1;

    while(count != pos && temp != NULL){
        temp = temp->next;
        count++;
    }

    temp->prev->next = temp->next;
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    delete temp;
}

int main(){
    node* head = NULL;
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    insertAtHead(head,1);
    cout<<"\n";
    display(head);
    cout<<"\n";
    deletion(head,5);
    display(head);
    cout << "\n";
    deleteAtHead(head);
    display(head);

    return 0;
}