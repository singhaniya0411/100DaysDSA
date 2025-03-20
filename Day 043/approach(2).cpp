/*
    Title: Count Pairs with a Given Sum (Optimized Two-Pointer Approach)

    Problem Statement:
        - Given an array of integers, count the number of unique pairs (i, j) such that arr[i] + arr[j] equals a target sum.

    Approach:
        - **Sort the array** to enable two-pointer traversal.
        - Initialize two pointers: `left` (start) and `right` (end).
        - Traverse the array:
            - If `arr[left] + arr[right] == target`:
                - Count duplicate occurrences of `arr[left]` and `arr[right]` for multiple pairs.
                - Add `c1 * c2` to the total count.
            - If sum is greater than target → Move `right` pointer left.
            - If sum is smaller than target → Move `left` pointer right.
        - Continue until `left < right`.

    Returns:
        - The number of unique pairs that satisfy the condition.

    Time Complexity:
        - **O(n log n) + O(n) = O(n log n)** (Sorting + Two-pointer traversal)

    Space Complexity:
        - **O(1)** (In-place sorting and two-pointer traversal)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function to count the number of pairs with a given sum
int countPairsWithSum(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    sort(arr, arr + n); // Sorting the array
    int pairCount = 0;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == target) {
            int c1 = 1, c2 = 1;
            
            // Count duplicate occurrences of arr[left]
            while (left + 1 < right && arr[left] == arr[left + 1]) {
                c1++;
                left++;
            }
            
            // Count duplicate occurrences of arr[right]
            while (right - 1 > left && arr[right] == arr[right - 1]) {
                c2++;
                right--;
            }

            // If both pointers meet, handle duplicate pairs correctly
            if (left == right) {
                pairCount += c1 * (c1 - 1) / 2;  // Choose 2 out of c1
            } else {
                pairCount += c1 * c2;  // Multiply the counts
            }
            
            left++;
            right--;
        } 
        else if (sum > target) {
            right--; // Reduce sum
        } 
        else {
            left++;  // Increase sum
        }
    }

    return pairCount;
}

int main() {
    int n = 3;
    int arr[n] = {1, 1, 1}; // All elements are the same
    
    int target = 2;
    cout << "Number of pairs in the array that sum up to " << target << ": " 
         << countPairsWithSum(arr, n, target) << endl;
    
    return 0;
}
