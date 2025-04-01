/*
    Title: Count Pairs with Sum Less Than Target (Two-Pointer Approach)

    Problem Statement:
        - Given a **sorted** array of integers and a target sum `target`, 
          find the number of pairs `(arr[i], arr[j])` such that:
              arr[i] + arr[j] < target  (where i < j)

    Approach:
        - Use the **two-pointer technique**:
            1. Initialize `left` at the beginning and `right` at the end of the array.
            2. If `arr[left] + arr[right] < target`, all pairs from `left` to `right` are valid.
               - Increment `count` by `(right - left)`.
               - Move `left` forward to check more pairs.
            3. Otherwise, move `right` backward.
        - This ensures **O(n) time complexity**, which is more efficient than brute force.

    Time Complexity:
        - **O(n)** (Linear time due to the two-pointer traversal)

    Space Complexity:
        - **O(1)** (No extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count pairs whose sum is less than the target (Two-Pointer Approach)
int sumLessThanTarget(vector<int> arr, int target) {
    int count = 0;
    int n = arr.size();

    int left = 0;
    int right = n - 1;

    // Two-pointer approach to count valid pairs
    while (left < right) {
        if (arr[left] + arr[right] < target) {
            count += (right - left);  // All pairs from left to right are valid
            left++;  // Move left pointer forward
        } else {
            right--;  // Move right pointer backward
        }
    }
    return count;
}

int main() {
    // Sample sorted array
    vector<int> arr = {-2, 1, 2, 3, 4, 5, 8, 9, 11};
    
    int target = 8;

    // Print the count of pairs whose sum is less than the target
    cout << "Pairs with sum less than " << target << ": " << sumLessThanTarget(arr, target) << endl;
    
    return 0;
}
