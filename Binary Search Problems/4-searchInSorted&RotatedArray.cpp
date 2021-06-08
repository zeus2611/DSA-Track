/*
Search Element in Sorted and Rotated Array
We are given an ascending sorted array that has been rotated from a pivot point(unknown) and an element X.
Search for X in the array with complexity less than that of linear search(i.e. O(N)).

Strategy:-
1) Find the pivot point
    only element that will be greater than next element
    arr[i] > arr[i+1], i<=n-1
2) Apply BS in left half
3) Apply6 BS in right half
*/

#include <bits/stdc++.h>
using namespace std;

int searchinRotated(int arr[], int key, int left, int right){
    if(left > right){
        return -1;
    }

    int mid = (left+right)/2;
    if(arr[mid] == key){
        return mid;
    }

    if(arr[left] <= arr[mid]){
        if(key >= arr[left] && key <= arr[mid]){
            return searchinRotated(arr, key, left, mid-1);
        }
        return searchinRotated(arr, key, mid+1, right);
    }
    
    if(key >= arr[mid] && key <= arr[right]){
        return searchinRotated(arr, key, mid+1, right);
    }

    return searchinRotated(arr, key, left, mid-1);
}

int main() {

}