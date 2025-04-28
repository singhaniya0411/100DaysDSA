/*
    Title: Longest Subarray with Sum K (Brute Force Approach)

    Problem Statement:
        - Given an array of integers and an integer k,
          find the length of the longest subarray whose sum equals k.

    Approach:
        - For every possible subarray, calculate its sum.
        - If the sum equals k, update the maximum length.
        - Brute-force method using two nested loops.

    Time Complexity:
        - **O(n²)** — Two nested loops.

    Space Complexity:
        - **O(1)** — No extra space used.

    Assumption:
        - The array can contain positive, negative, or zero elements.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

// Function to find the longest subarray with sum k (brute-force)
int subArray(vector<int> arr, int n, int k) {
    unordered_map<int,int> mp;
    int res = 0;
    int p_Sum=0;
    
    for (int i  =0 ;i<n;i++){
        p_Sum+=arr[i];
        
        if(p_Sum==k){
            res=i+1;
        }
        else if (mp.count(p_Sum-k)){
            res = max(res,i-mp[p_Sum-k]);
        }
        
        if(!mp.count(p_Sum)){
            mp[p_Sum]=i;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 15, -11, 4, 3, -3};
    int k = 11;

    int longestLength = subArray(arr, arr.size(), k);

    cout << "Length of longest subarray with sum " << k << " is: " << longestLength << endl;

    return 0;
}
