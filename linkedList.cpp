#include <iostream>
using namespace std;

class node{
    public:
        int data;
        node* next;

        node(int val){
            data = val;
            next = NULL;
        }
};

/*------------- Insertion -------------*/
void insertAtHead(node* &head, int val){
    node* n =  new node(val);
    n->next = head;
    head = n;
}

void insertAtTail(node* &head, int val){         // we use by reference bcz we have to modify the linedList
    node* n = new node(val);
    
    if(head == NULL){                           //  to check if its 1st element in list
        head = n;
        return;
    }

    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->next = n;
}
/*--------------------------------------*/

/*------------- Display -------------*/
void display(node* head){                 // we use by value bcz we have dont have to modify but just print
    node* temp = head;
    while(temp != NULL){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "\n";
}
/*-----------------------------------*/

/*------------- Search -------------*/
bool search(node* head, int val){     // searching in linkedLIst
    node* temp = head;
    while(temp != NULL){
        if(temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}
/*--------------------------------*/

/*------------- Deletion -------------*/
void deleteAtHead(node* &head){
    node* todelete = head; 
    head = head->next;
    delete todelete;
}

void deletion(node* &head,int val){
    if(head == NULL){
        return;
    }

    if(head->next == NULL){
        deleteAtHead(head);
        return;
    }

    node* temp = head;

    while(temp->next->data != val){
        temp = temp->next;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}
/*-----------------------------------*/

/*------------- Reverse -------------
/*++++++++++ Iterative ++++++++++*/
node* reverse(node* &head){
    node* pervptr = NULL;
    node* curptr = head;
    node* nextptr;

    while(curptr != NULL){
        nextptr = curptr->next;
        curptr->next = pervptr;

        pervptr = curptr;
        curptr = nextptr;
    }

    return pervptr;
}

/*++++++++++ Recursive ++++++++++ (Complexity = O(n) because we are travesing our list single time)*/
node* reverseRecursive(node* &head){
    if(head->next == NULL || head == NULL){
        return head;
    }
    node* newhead = reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return newhead;
}
/*----------------------------------*/

node* reverseK(node* &head, int k){
    /*
        Time complexity = O(n)
        because we are traversing the link list a single time
    */
    
    node* prevpt = NULL;
    node* currpte = head;
    node* nextptr;

    int count = 0;
    while(currpte != NULL && count < k){
        nextptr = currpte->next;
        currpte->next = prevpt;
        prevpt = currpte;
        currpte = nextptr;
        count++;
    }

    if(nextptr != NULL){
    head->next = reverseK(nextptr, k);
    }

    return prevpt;
}

 /* Detect cycle(next of two node point to same node ) in linkedList
    using floyd's / hare and tortoise algorithm
    hare moves 2 steps while tortoise move 1 step
    when both meet at a node we can say Linkedlist
    has cycle
 */
bool detectCycle(node* &head){
    node* slow = head;
    node* fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if (fast == slow){
            return true;
        }
    }
    return false;
}

/* Remove cycle:-
    when both hare and tortoise both are at same node
    we make one of the point to head and move both pointer
    by 1 step and check when their next is pointing to same
    node. And, then we point the other pointer to null
*/
void removeCycle(node* &head){
    node* slow = head;
    node* fast = head;

    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (fast != slow );
    
    fast = head;
    while(slow->next != fast->next){
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = NULL;
}

/*
--------Append last K nodes of LinkedList--------
last K nodes becomes starting K nodes
we put newtail = l-k
and, newhead = l-k+1 
but first we find length of linkedlist
time complexity = O(n)
*/
int length(node* head){
    int l = 0;
    node* temp = head;
    while(temp!=NULL){
        l++;
        temp = temp->next;
    }
    return l;
}
node* appendK(node* &head, int k){
    node* newHead;
    node* newtail;
    node* tail = head;

    int l = length(head);
    k %= l;
    int count = 1;

    while (tail->next != NULL){
        if(count == l - k)
            newtail = tail;
        if(count == l-k+1)
            newHead = tail;
        tail = tail->next;
        count++;
    }
    newtail = NULL;
    tail = head; 
    
    return newHead;
}

/*Time Complexity = O(laregest length of linkedlist)*/
int intersection(node* &head1, node* &head2){
    int l1 = length(head1),
        l2 = length(head2);

    int d = 0;
    node* ptr1; node* ptr2;
    if(l1 > l2){
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else{
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1; 
    }

    while (d){
        ptr1 = ptr1->next;
        if(ptr1 == NULL)
            return -1;
        d--;
    }

    while (ptr1 != NULL && ptr2 == NULL){
        if(ptr1 == ptr2)
            return ptr1->data;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    } 
}

/*  Merge 2 Sorted LinkedList
    Time Complexity : O(n+m)
    n = length of 1st LinkedList
    m = length of 2nd LinkedList
*/
node* merge(node* &head1, node* &head2){
    node* p1 = head1;
    node* p2 = head2;
    node* dummyNode = new node(-1);
    node* p3 = dummyNode;

    while(p1!=NULL && p2!= NULL){
        if(p1->data < p2->data){
            p3->next=p1;
            p1 = p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while (p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while (p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummyNode->next;
}

node* mergeRecursive(node* &head1, node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    node* result;
    if(head1->data < head2->data){
        result = head1;
        result->next = mergeRecursive(head1->next, head2);
    }
    else{
        result = head2;
        result->next = mergeRecursive(head1, head2->next);
    }
    return result;
}

int main(){
    node* head = NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    display(head);
    // deletion(head,2);
    // display(head);

    // node* newhead = reverseRecursive(head);
    // display(newhead);
    // int k = 2;
    // node* newhead = reverseK(head, k);
    // display(newhead);

    node* newHead = appendK(head, 3);
    display(newHead);

    return 0;
}