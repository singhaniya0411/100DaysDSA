/*
    Title: Search an Element in a Row-wise Sorted Matrix using Binary Search
    
    Problem Statement:
        - Implement a function to search for an element in an M x N matrix 
          where each row is sorted in increasing order.

    Approach:
        - **Binary Search on Rows**:
          1. Perform a binary search on each row individually.
          2. If the element is found in any row, return `true`.
          3. If no match is found after checking all rows, return `false`.

    Returns:
        - true if the element is found, false otherwise

    Time Complexity:
        - **O(M * logN)** (where M = rows, N = columns)
        - Since each row is sorted, binary search runs in **O(logN)** for each of the **M** rows.

    Space Complexity:
        - **O(1)** (constant extra space)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search on a 1D row
bool search(vector<int> &arr, int k) {
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == k) {
            return true; // Element found
        }

        if (k < arr[mid]) {
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1;  // Search in the right half
        }
    }

    return false; // Element not found
}

// Function to search for an element in a row-wise sorted matrix
bool searchRowWise(vector<vector<int>> &arr, int m, int n, int k) {
    for (int i = 0; i < m; i++) {
        if (search(arr[i], k)) { // Perform binary search on each row
            return true;
        }
    }
    return false;
}

int main() {
    int m = 3;
    int n = 3;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k = 12;

    if (searchRowWise(matrix, m, n, k)) {
        cout << "Element found \n";
    } else {
        cout << "Not found \n";
    }

    return 0;
}
