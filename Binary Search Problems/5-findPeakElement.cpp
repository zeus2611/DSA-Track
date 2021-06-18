/*
Find the Peak ELment in Array
For a given array, find the peak element in the array. Peak element is one which is greater than both leftand right neighbours of itself. 
Use binary search, analyze indices from 0 to n-1
Compute mid & for each mid check 
    if arr[mid] is peak element
        return mid;
    else if arr[mid-1] > arr[mid]
        check left for peak
    else if arr[mid] < arr[mid+!]
        check right for peak
*/

#include<bits/stdc++.h>
using namespace std;

int peakEle(int arr[], int low, int high, int n){
    int mid = low + (high-low)/2;

    if((mid == 0 || arr[mid] >= arr[mid-1]) && (mid == n-1 || arr[mid] >= arr[mid+1])){
        return mid;
    } else if(mid > 0 && arr[mid-1] > arr[mid]) {
        return peakEle(arr, low, mid-1, n);
    } else {
        return peakEle(arr, mid+1, high, n);
    }
}

int main() {
    int arr[] = {0, 6, 8, 5, 7, 9};
    int n = 6;

    cout << peakEle(arr, 0, n-1, n);

}