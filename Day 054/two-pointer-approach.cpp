/*
    Title: Count Pairs with Sum Equal to Target (Using Two Pointers)

    Problem Statement:
        - Given an array of integers and a target sum `target`, 
          count the number of unique pairs `(arr[i], arr[j])` such that:
              arr[i] + arr[j] == target  (where i < j)

    Approach:
        - First, sort the array.
        - Use two pointers: one at the start and one at the end.
        - Move them inward based on the sum, and count pairs using frequency if duplicates are found.

    Time Complexity:
        - **O(n log n)** for sorting + **O(n)** for two-pointer traversal → **O(n log n)** total.

    Space Complexity:
        - **O(1)** (in-place sorting and a few variables)

    Assumption:
        - Duplicates are allowed, and all valid `(i, j)` pairs (including duplicates) are counted.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Count pairs with sum equal to target using two-pointer approach
int countPair(vector<int> arr, int target) {
    int n = arr.size();
    if (n < 2) {
        cout << "Array must have at least two elements!" << endl;
        return -1;
    }

    sort(arr.begin(), arr.end()); // Sort array

    int left = 0, right = n - 1;
    int count = 0;

    while (left <= right) {
        int sum = arr[left] + arr[right];

        if (sum > target) {
            right--;
        } 
        else if (sum < target) {
            left++;
        } 
        else {
            int cnt1 = 0, cnt2 = 0;
            int ele1 = arr[left], ele2 = arr[right];

            // Count duplicates for arr[left]
            while (left <= right && arr[left] == ele1) {
                cnt1++;
                left++;
            }

            // Count duplicates for arr[right]
            while (left <= right && arr[right] == ele2) {
                cnt2++;
                right--;
            }

            if (ele1 == ele2) {
                count += (cnt1 * (cnt1 - 1)) / 2;  // nC2 when both pointers point to the same number
            } else {
                count += cnt1 * cnt2;
            }
        }
    }

    return count;
}

int main() {
    vector<int> arr = {2, 4, 4, 4, 5, -1, 3, 3, 8, 9, -2, 11}; // Unsorted array
    int target = 8;

    cout << "Number of pairs with sum equal to " << target << " is: ";
    cout << countPair(arr, target) << endl;

    return 0;
}
