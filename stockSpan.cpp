/*
Stock Span
    the span of stock's price is defined as the maximun number of consecutive days(including today) for which the price of the stocks was less than or equal to today's price.
*/

/*
Brute Force
for(int i=0; i<n; i++){
    int days=0;
    for(int j=i; j>=0; j--){
        if(price[i] >= price[j])
            days++;
        else
            break;
    }
    span of i'th day is "days".
}
*/

/*
Stack Approach
Create a stack<pair<int,int>> representing {price, days}
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> stockspan(vector<int> prices){
    vector<int> ans;

    stack<pair<int, int>> s;
    for(auto price: prices){
        int days = 1;
        while(!s.empty() && s.top().first <= price){
            days += s.top().second;
            s.pop();
        }
        s.push({price,days});
        ans.push_back(days);
    }

    return ans;
}

int32_t main(){
    vector<int> a = {100, 80, 60, 70, 60, 75, 85};
    vector<int> res = stockspan(a);
    for(auto i : res)
        cout << i << " ";
    cout << "\n";
}