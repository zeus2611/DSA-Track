/*
Painter Partition Problem
n - length of n different boards
m - painter available

A painter paints 1 unit of board in 1 unit of time and each painter will paint consecutive boards. Find the minimum times that will be required to paint all the boards.

Strategy:-
1) Apply Binary Search for minimum and maximum possible values of 'min' length of boards to be painted.
2) check feasibility for sol.
3) Feasibility:-
    Assign boards to each painter in sequential manner, while the current length of assigned boards don't exceed the value set by binary search.
*/

#include<bits/stdc++.h>
using namespace std;

int feasible(int boards[], int n, int min) {
    int painters = 1, sum = 0;
    for (int i=0; i<n; i++){
        sum += boards[i];
        if(sum > min){
            sum = boards[i];
            painters++;
        }
    }

    return painters;
}

int painterPart(int boards[], int n, int m){
    int sum = 0, k = 0;
    for (int i=0; i<n; i++){
        k = max(boards[i], k);
        sum += boards[i];
    }

    int start = k, end = sum;
    while(start < end) {
        int mid = (start+end)/2;
        int painters = feasible(boards, n, mid);
        if(painters <= m){
            end = mid;  // if feasible then we look in left side of array
        } else {
            start = mid + 1;  // if not feasible then we look in right side of array
        }
    }

    return start;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    int n = 4;
    int m = 2;

    cout << painterPart(arr, n, m);
}