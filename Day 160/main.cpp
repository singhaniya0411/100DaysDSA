./*
    Title: Missing Number in an Array using XOR

    Problem Statement:
        - You are given an array containing 'n-1' distinct numbers from 1 to n.
        - Find the missing number efficiently without using extra space.

    Example:
        Input:  arr = {1, 3, 2, 5, 6, 9, 8, 4}
        Expected Range: 1 to 9
        Missing Number = 7

    Approach (Using XOR):
        - XOR has two key properties:
            1. a ^ a = 0
            2. a ^ 0 = a
        - XOR of all numbers from 1 to n gives a combined pattern.
        - XOR of all elements in the array cancels out all common numbers.
        - The remaining value after XORing both results is the missing number.

        Steps:
        1. Compute xor1 = XOR of all numbers from 1 to n.
        2. Compute xor2 = XOR of all elements in the array.
        3. Missing number = xor1 ^ xor2.

    Time Complexity:
        - O(n), single traversal of array and one XOR loop.

    Space Complexity:
        - O(1), no extra space used.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int missingNum(vector<int> &arr){
    int n = arr.size() + 1;
    int xor1 = 0, xor2 = 0;
    
    // XOR of numbers f


#include<bits/stdc++.h>
using namespace std;

int missingNum(vector<int> & arr){
    int n  = arr.size()+1;
    
    int xor1=0, xor2=0;
    
    for(int i = 1;i<=n;i++){
        xor1^=i;
    }
    
    for(int i =0;i<n-1;i++){
        xor2^=arr[i];
    }
    
    return xor2^xor1;
}

int main(){
    
    vector<int> arr = {1,3,2,5,6,9,8,4};
    
    cout<<"The missing number from array is : "<<missingNum(arr);
    return 0;
}
