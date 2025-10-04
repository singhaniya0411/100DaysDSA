/*
    Title: Sum of XOR of All Subsets

    Problem Statement:
        - You are given an array of integers.
        - The task is to calculate the sum of XOR values of all possible subsets.
        - Example: If arr = {a, b}, subsets = {}, {a}, {b}, {a, b}
            XORs = 0, a, b, a^b → sum = 0 + a + b + (a^b).

    Approach (Bitwise Property):
        1. Each bit position contributes independently to the total XOR sum.
        2. Observation:
            - For n elements, each element participates in exactly 2^(n-1) subsets.
            - Therefore, each bit of OR(arr) contributes equally across subsets.
        3. Formula:
            Sum of XOR of all subsets = (bitwise OR of all elements) * (2^(n-1))

    Example:
        Input:
            arr = {2, 6, 9}
        
        Process:
            - OR = 2 | 6 | 9 = 15
            - n = 3
            - Total sum = 15 * (2^(3-1)) = 15 * 4 = 60
        
        Output:
            60

    Dry Run:
        arr = {2, 6, 9}
        - Subsets:
            {} → 0
            {2} → 2
            {6} → 6
            {9} → 9
            {2,6} → 2^6 = 4
            {2,9} → 2^9 = 11
            {6,9} → 6^9 = 15
            {2,6,9} → 2^6^9 = 13
        - Total = 0+2+6+9+4+11+15+13 = 60 

    Time Complexity:
        - O(n), for computing OR of all elements.

    Space Complexity:
        - O(1), only a few variables used.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int sumOfXor(vector<int> & arr){
    int n = arr.size();
    int bits = 0;
    
    for(int i = 0; i < n; i++){
        bits = bits | arr[i];
    }
    
    // Formula: OR(arr) * 2^(n-1)
    int ans = bits * (pow(2, n-1));
    return ans;
}

int main(){
    vector<int> arr = {2,6,9};
    int xorSum = sumOfXor(arr);
    cout << "Sum of all subset XOR is : " << xorSum;
    return 0;
}










