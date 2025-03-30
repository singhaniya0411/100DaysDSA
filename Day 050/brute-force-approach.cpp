/*
    Title: Count Subarrays with a Given XOR (Brute Force Approach)

    Problem Statement:
        - Given an array of integers and a target XOR value `k`, find the number of subarrays whose XOR equals `k`.

    Approach:
        - Use a **nested loop** to iterate over all possible subarrays.
        - Maintain a `preXOR` variable to store the current subarray XOR.
        - If `preXOR` matches `k`, increment the count.

    Time Complexity:
        - **O(n²)** (Due to nested loops iterating over all subarrays)

    Space Complexity:
        - **O(1)** (No extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to count subarrays with XOR equal to k (Brute Force)
int subArrayXOR(vector<int> arr, int k) {
    int res = 0;
    
    for (int i = 0; i < arr.size(); i++) {
        int preXOR = 0;  // Reset XOR for each new starting point
        
        for (int j = i; j < arr.size(); j++) {
            preXOR ^= arr[j];  // Compute XOR of subarray [i...j]
            
            if (preXOR == k) {
                res++;
            }
        }
    }
    
    return res;
}

int main() {
    vector<int> arr = {12, 12, 9, 7, 3};  
    int k = 12;

    // Print the count of subarrays with XOR = k
    cout << "The subarray count having XOR = " << k << " is " << subArrayXOR(arr, k) << endl;
    
    return 0;
}
