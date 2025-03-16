/*
    Title: Check if a Pair Exists with a Given Sum using Binary Search
    
    Problem Statement:
        - Implement a function to check whether a pair of numbers in an array 
          sums up to a given target using **binary search** for optimization.

    Approach:
        - **Sort the array** first.
        - Iterate through the array and for each element, compute the **required complement**.
        - Use **binary search** to check if the complement exists in the remaining part of the array.

    Returns:
        - `true` if a pair exists with the target sum, otherwise `false`.

    Time Complexity:
        - **O(n log n)** (sorting: O(n log n), binary search for each element: O(log n))

    Space Complexity:
        - **O(1)** (no extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Binary search function to find the target in the sorted array
bool binarySearch(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return true;
        } else if (arr[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
}

// Function to check if a pair exists with the given sum
bool checkSum(int arr[], int n, int target) {
    sort(arr, arr + n); // Step 1: Sort the array
    for (int i = 0; i < n; i++) {
        int second = target - arr[i];
        if (binarySearch(arr, i + 1, n - 1, second)) { // Step 2: Use binary search for complement
            return true;
        }
    }
    return false;
}

int main() {
    int n = 6;
    int arr[n] = {4, 1, 7, 8, 5, 9};
    int target = 1;

    if (checkSum(arr, n, target)) {
        cout << "True";
    } else {
        cout << "False";
    }
    
    return 0;
}
