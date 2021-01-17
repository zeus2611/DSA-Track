#include <iostream>
using namespace std;

void swap(int arr[], int low, int mid){
    int temp = arr[mid];
    arr[mid] = arr[low];
    arr[low] = temp;
}

void waveSort(int arr[], int n)
{
    for(int i = 1; i < n-1; i += 2){
        if(arr[i] > arr[i-1]){
            swap(arr, i, i-1);
        }
        if(arr[i] > arr[i+1]){
            swap(arr, i, i+1);
        }
    }
}

int main()
{

    int arr[] = {1,3,4,7,5,6,2};
    int n = 7;
    waveSort(arr, n);

    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}