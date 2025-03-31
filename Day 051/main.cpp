/*
    Title: Count Unique Triplets with a Given Sum (Two-Pointer Approach)

    Problem Statement:
        - Given a sorted array of integers, find the number of unique triplets (i, j, k) such that arr[i] + arr[j] + arr[k] == target.

    Optimized Approach:
        - Use a **two-pointer approach** to find pairs that sum to (target - arr[i]).
        - If a valid pair is found, count occurrences efficiently.

    Time Complexity:
        - **O(n²)** (For each element, we use a two-pointer technique)

    Space Complexity:
        - **O(1)** (No extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count unique triplets with sum equal to target
int countTriplet(vector<int> arr, int target) {
    int n = arr.size();
    if (n < 3) return 0;  // Edge case: If less than 3 elements, return 0
    
    int res = 0;
    sort(arr.begin(), arr.end());  // Sort array for two-pointer approach

    for (int i = 0; i < n - 2; i++) {
        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = arr[i] + arr[left] + arr[right];

            if (sum < target) {
                left++;
            } 
            else if (sum > target) {
                right--;
            } 
            else {
                int ele1 = arr[left], ele2 = arr[right];
                int count1 = 0, count2 = 0;

                // Count occurrences of arr[left]
                while (left <= right && arr[left] == ele1) {
                    left++;
                    count1++;
                }

                // Count occurrences of arr[right]
                while (left <= right && arr[right] == ele2) {
                    right--;
                    count2++;
                }

                // If both elements are the same, use combination formula
                if (ele1 == ele2) {
                    res += (count1 * (count1 - 1)) / 2;
                } 
                else {
                    res += (count1 * count2);
                }
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};  
    int target = 6;

    // Print the count of triplets
    cout << "The number of triplets with sum " << target << " is " << countTriplet(arr, target) << endl;

    return 0;
}
