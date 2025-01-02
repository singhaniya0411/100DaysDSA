/*
    Title: Find the Second Largest Element in an Array
    Description:
        This program finds the second largest distinct element in an integer array.
        If the array has fewer than two elements or there is no second largest distinct element, it returns -1.

    Input:
        - The size of the array (n)
        - Array elements (n integers)

    Output:
        - The second largest distinct element in the array, or -1 if not applicable.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<climits>
using namespace std;

int second_largest(int arr[],int n){
    if(n<2){
        return -1;
    }
    
    int largest=INT_MIN;
    int second_largest_element=INT_MIN;
    for(int i = 0; i<n; i++){
        if(arr[i]>largest){
            second_largest_element=largest;
            largest=arr[i];
        }
        else if(arr[i]>second_largest_element && arr[i]!=largest){
            second_largest_element=arr[i];
        }
    }
    return second_largest_element == INT_MIN ? -1 : second_largest_element;
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
    cout<<second_largest(arr,n);
    return 0;
}
