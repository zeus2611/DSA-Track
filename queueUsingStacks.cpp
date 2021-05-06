/*
Approach 1:-
Using 2 stacks and deQueue operation is costly.
enQueue Operation - 
    push x to stack1
deQueue Operation - 
    1) If both stacks are empty then print error.
    2) if stack2 is empty
        while stack1 is not empty, push everything from stack1 to stack2.
    3) Pop the element from stack2 and return it.
*/

#include <bits/stdc++.h>
#include <queue>
using namespace std;

class qu1{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        if (s1.empty() and s2.empty()){
            cout << "Queue is empty\n";
            return -1;
        }
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval = s2.top();
        s2.pop();
        return topval;
    }

    bool empty(){
        if (s1.empty() and s2.empty())
            return true;
        return false;
    }
};

/*
Approach 2:-
Using Function call Stack
enQueue Operation - 
    push x to stack1
deQueue Operation - 
    1) If stack1 is empty then print error
    2) If stack2 has only one element then return it.
    3) Recursively pop everything from stack1 store the popped item in a variable res, push the res back to stack1 and return res.
*/

class qu2{
    stack<int> s1;

public:
    void push(int x){
        s1.push(x);
    }

    int pop(){
        if (s1.empty()){
            cout << "Queue is empty\n";
            return -1;
        }
        int res = s1.top();
        s1.pop();
        if(s1.empty()){
            return res;
        }
        int item = pop();
        s1.push(res);
        return item;
    }

    bool empty(){
        if (s1.empty())
            return true;
        return false;
    }
};

int32_t main(){
    qu2 q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    if(q.empty())
        cout<<"empty\n";
    else
        cout<<"not empty\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    cout<<q.pop()<<"\n";
    if(q.empty())
        cout<<"empty\n";
    
    return 0;
}
