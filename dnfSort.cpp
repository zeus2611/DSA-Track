#include <iostream>
#include <vector>
using namespace std;

void swap(int arr[], int low, int mid){
    int temp = arr[mid];
    arr[mid] = arr[low];
    arr[low] = temp;
}

void dnfSort(int arr[], int low, int mid, int high)
{
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr,low,mid);
            low++;mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else if(arr[mid]==2){
            swap(arr,mid,high);
            high--;
        }
    }
}

int main()
{

    int arr[] = {1,1,0,0,0,1,2,2,1,2};
    int low=0,mid=0,high=9;
    dnfSort(arr, low, mid,high);

    for (int i = 0; i < 10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}