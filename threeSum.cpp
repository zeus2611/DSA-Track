#include<bits/stdc++.h>
using namespace std;

/*
Brute Force
Try Out all combinations
for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
        for(int k=j+1; k<n; K++)
            if(arr[i]+arr[j]+arr[k] == target)
                found = true;

Time Complexity: O(N^3)
*/

/*
Two Pointer Alogo:
1. Sort the array
2. Traverse the array and fix the first of the triplet. The problem reduces to find if threre exist two elements having sum equal to x-arr[i]
Gets converted to Two sum
Time Complexity:
sorting the array: O(N logN)
Iterating each element and applying two sum to rest of the arrat: O(N^2)
Final Time Complexity: O(N^2)
*/

int32_t main(){
    int n, target;
    cin >> n >> target;
    vector<int> a(n);
    for(auto &i : a)
        cin >> i;
    bool found = false;

    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        int lo=i+1, hi =n-1;
        while(lo<hi){
            int curr = a[i] + a[lo] + a[hi];
            if(curr == target){
                found = true;
                break;
            }
            else if(curr < target)
                lo++;
            else
                hi--;
        }
    }
    cout << (found ? "YES\n" : "NO\n");

    return 0;
}