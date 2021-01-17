#include<iostream>
#include<vector>
using namespace std;

bool myCompare(pair<int, int>p1, pair<int, int>p2){
    return p1<p2;
}

int main(){
    int arr[]={10,16,7,14,5,3,2,9};
    vector < pair<int, int> > v;

    for (int i = 0; i < sizeof(arr); i++)
    {
        pair<int,int> p;
        v.push_back(make_pair(arr[i],i));
    }
    
    sort(v.begin(), v.end(), myCompare);

}
