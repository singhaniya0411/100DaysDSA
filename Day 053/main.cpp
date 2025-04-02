/*
    Title: Find the Pair with Sum Closest to Target (Two-Pointer Approach)

    Problem Statement:
        - Given a **sorted** array of integers and a target sum `target`, 
          find the pair `(arr[i], arr[j])` such that:
              |arr[i] + arr[j] - target| is minimized.
        - If multiple pairs have the same difference, return the pair with the **largest difference** between numbers.

    Approach:
        - Use the **two-pointer technique**:
            1. Initialize `left` at the beginning and `right` at the end of the array.
            2. Calculate `sum = arr[left] + arr[right]`.
            3. Compare the absolute difference `|sum - target|`:
               - If it is smaller than `minDiff`, update the result pair.
               - If it is equal, prioritize the pair with a **larger difference** (`arr[right] - arr[left]`).
            4. Move pointers based on sum comparison:
               - If `sum > target`, decrement `right` to reduce the sum.
               - If `sum < target`, increment `left` to increase the sum.
               - If `sum == target`, break early.

    Time Complexity:
        - **O(n log n)** (Sorting takes O(n log n) if array is unsorted, otherwise O(n) with two pointers)

    Space Complexity:
        - **O(1)** (Only a few extra variables used)

    Author: Vishal Singhaniya
    
*/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

// Function to find the pair with sum closest to target
void pairClosestToTarget(vector<int> arr, int target) {
    int n = arr.size();
    if (n < 2) {
        cout << "Array must have at least two elements!" << endl;
        return;
    }

    int minDiff = INT_MAX;  // Stores minimum difference found
    int left = 0, right = n - 1;
    vector<int> res;  // Stores the resulting closest pair
    
    sort(arr.begin(), arr.end());  // Ensure the array is sorted

    while (left < right) {
        int sum = arr[left] + arr[right];
        int diff = abs(sum - target);

        // If new minimum difference is found, update result
        if (diff < minDiff) {
            minDiff = diff;
            res = {arr[left], arr[right]};
        }
        // If the same difference is found, prefer the pair with a larger gap
        else if (diff == minDiff && (arr[right] - arr[left] > res[1] - res[0])) {
            res = {arr[left], arr[right]};
        }

        // Move pointers based on sum comparison
        if (sum > target) right--;
        else if (sum < target) left++;
        else break;  // If exact match found, exit early
    }

    // Print the closest pair
    cout << "Closest Pair: " << res[0] << ", " << res[1] << endl;
}

int main() {
    // Sample sorted array
    vector<int> arr = {-2, 1, 2, 3, 4, 5, 8, 9, 11};
    int target = 8;

    // Find and print the closest pair
    cout << "Finding the closest pair to target " << target << "..." << endl;
    pairClosestToTarget(arr, target);

    return 0;
}
