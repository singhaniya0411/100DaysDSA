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
using namespace std;

// Function to find the longest subarray with sum k (brute-force)
int subArray(vector<int> arr, int n, int k) {
    int res = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = i; j < n; j++) {
            sum += arr[j];

            if (sum == k) {
                int subLength = j - i + 1;
                res = max(res, subLength);
            }
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
