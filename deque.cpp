/*
Deque - Double ended queue
    1. Push and Pop from the end
    2. Insert and delete from the start

    Operations:
        1. push_front
        2. push_back
        3. pop_front
        4. pop_back
*/

#include<iostream>
#include<deque>
using namespace std;

int32_t main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    for(auto i : dq)
        cout << i << " ";
    cout << "\n";

    return 0;
}