/*
    Title: Count Subarrays with a Given Sum (Brute Force Approach)

    Problem Statement:
        - Given an array of integers and a target sum `k`, find the number of subarrays whose sum equals `k`.

    Approach:
        - Use a **nested loop** to iterate over all possible subarrays.
        - Maintain a `sum` variable to store the current subarray sum.
        - If `sum` matches `k`, increment the count.

    Time Complexity:
        - **O(n²)** (Due to nested loops iterating over all subarrays)

    Space Complexity:
        - **O(1)** (No extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to count subarrays with sum equal to k
int countSubarray(vector<int> arr, int k) {
    int ans = 0;

    // Iterate over all starting points of subarrays
    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;  

        // Iterate over all possible ending points of subarrays
        for (int e = i; e < arr.size(); e++) {
            sum += arr[e];  // Update sum of current subarray
            
            // If sum equals k, increment count
            if (sum == k) {
                ans++;
            }
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {4, 5, 2, 17, 12, 9, 7, 3};  
    int k = 19;

    // Print the count of subarrays whose sum is k
    cout << "The subarray count having sum " << k << " is " << countSubarray(arr, k) << endl;
    
    return 0;
}
