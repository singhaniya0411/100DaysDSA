#include<iostream>
using namespace std;

int findMinimum(int arr[],int low,int high){
    while(low<high){
        if(arr[low]<arr[high]){
            return arr[low];
        }
        
        int mid = (low+high)/2;
        
        if(arr[mid]>arr[high]){
            low=mid+1;
        }
        else{
            high=mid;
        }
    }
    return arr[low];
}

int main(){
    
    int size;
    cout<<"Enter the size of array : ";
    cin>>size;
    int arr[size];
    
    cout<<"Enter the elemenst of array : ";
    for (int i = 0; i < size; i++) {
        cin>>arr[i];
    }
    
    cout<<"Minimum in this rotated and sorted array : "<<findMinimum(arr,0,size-1);
    return 0;
}
