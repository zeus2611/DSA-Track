/*
Problem Statement:-
Given is an array with n elements that represents n positions along a straight line. Find K elements such that the minimum distance between any 2 elements is the maximum possible.

Approach 1-
Find all possible subsets of size K and compare the minimum distance between all of them.

Approach 2-
a) Sort the array for binary search technique
b) Pick middle element as result and check for its feasibility.
c) If feasible, search the right half of the array with larger minimum distance.
d) Else, search the left half of the array.
*/

#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int mid, int arr[], int n , int k){
    int pos = arr[0], elements = 1;

    for(int i = 1; i<n; i++){
        if(arr[i] - pos >= mid){
            pos = arr[i];
            elements++;
            if(elements == k){
                return true;
            }
        }
    } 

    return false;
}

int largestMinDis(int arr[], int n, int k){
    sort(arr, arr+n);

    int result = -1; 
    int left = 1, right = arr[n-1];

    while(left < right){
        int mid = (left+right)/2;
        if(isFeasible(mid, arr, n, k)){
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return result;
}

int main(){

}