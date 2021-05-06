 #include<bits/stdc++.h>
using namespace std;

// Method 1:- Making push operation costly
class stack1{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    stack1(){
        N=0;
    }

    void push(int val){
        q2.push(val);
        N++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }

        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop(){
        q1.pop();
        N--;
    }

    int top(){
        return q1.front();
    }

    int size(){
        return N;
    }
};

// Method 2:- Making pop operation costly
class stack2{
    int N;
    queue<int> q1;
    queue<int> q2;

    public:
    stack2(){
        N = 0;
    }

    void pop(){
        if(q1.empty()){
            return;
        }

        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        N--;

        queue<int> temp = q1;
        q1 = q2;
        q2 =temp;
    }

    void push(int val){
        q1.push(val);
        N++;
    }

    int top(){
       if(q1.empty()){
            return -1;
        }

        while(q1.size() != 1){
            q2.push(q1.front());
            q1.pop();
        }

        int ans = q1.front();
        q2.push(ans);

        queue<int> temp = q1;
        q1 = q2;
        q2 =temp;

        return ans;
    }

    int size(){
        return N;
    }
};

int32_t main(){
    stack2 st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.pop();
    cout << st.top() << "\n";
    cout << st.size() << "\n";
    return 0;
}