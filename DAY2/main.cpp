/*
    Title: Move All Zeros to the End of the Array
    Description:
        This program rearranges the elements of an array such that all non-zero elements
        are moved to the front while preserving their relative order, and all zeroes 
        are placed at the end. The transformation is done in-place.
    Input:
        - The size of the array (n)
        - Array elements (n integers)

    Output:
        - The transformed array with non-zero elements at the front and zeroes at the end.
    Author: Vishal
*/
#include<iostream>
#include<climits>
using namespace std;

void zeros_move_end(int arr[], int n){
    int prev=0;
    for(int i = 0;i<n;i++){
        
        if(arr[i]!=0){
            arr[prev]=arr[i];
            prev++;
        }
    }
    for(int i=prev;i<n;i++){
        arr[i]=0;
    }
}


int main(){
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    int arr[n];
    cout<<"Enter the array elements : ";
    for (int i = 0; i < n; i++) {
        cin>>arr[i];
    }
    zeros_move_end(arr,n);
    for(int i = 0; i<n; i++){
        cout<<arr[i];
    }
    return 0;
}