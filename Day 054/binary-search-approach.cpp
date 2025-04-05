/*
    Title: Count Pairs with Sum Equal to Target (Using Binary Search)

    Problem Statement:
        - Given an array of integers and a target sum `target`, 
          count the number of unique pairs `(arr[i], arr[j])` such that:
              arr[i] + arr[j] == target  (where i < j)

    Approach:
        - First, sort the array.
        - For each element `arr[i]`, use binary search to find how many times 
          `target - arr[i]` appears in the subarray `arr[i+1...n-1]`.
        - Accumulate the count accordingly.

    Time Complexity:
        - **O(n log n)** for sorting + **O(n log n)** for binary search → **O(n log n)** total.

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

// Binary Search helper to count occurrences of target in arr[left...right]
int countOccurence(const vector<int>& arr, int left, int right, int target) {
    int count = 0;
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target) {
            int l = mid - 1, r = mid + 1;
            count = 1; // Count mid itself

            while (l >= left && arr[l] == target) {
                count++;
                l--;
            }
            while (r <= right && arr[r] == target) {
                count++;
                r++;
            }
            break;
        } 
        else if (arr[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return count;
}

// Count pairs with sum equal to target using binary search
int countPair(vector<int> arr, int target) {
    int n = arr.size();
    if (n < 2) {
        cout << "Array must have at least two elements!" << endl;
        return -1;
    }

    sort(arr.begin(), arr.end()); // Sort array

    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        int complement = target - arr[i];
        count += countOccurence(arr, i + 1, n - 1, complement);
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
