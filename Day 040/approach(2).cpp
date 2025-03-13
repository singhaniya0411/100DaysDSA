/*
    Title: Search an Element in a Sorted Matrix using Single Binary Search
    
    Problem Statement:
        - Implement a function to search for an element in an M x N matrix 
          where each row is sorted in increasing order.
        - Treat the 2D matrix as a flattened 1D array and apply binary search.

    Approach:
        - Perform **binary search on the virtual 1D array**.
        - Convert **1D index to 2D indices** using:
          - **row = mid / columns**
          - **col = mid % columns**

    Returns:
        - true if the element is found, false otherwise

    Time Complexity:
        - **O(log(M * N))** (binary search on M × N elements)

    Space Complexity:
        - **O(1)** (constant extra space)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to search an element in a sorted 2D matrix using binary search
bool searchMatrix(vector<vector<int>> &arr, int k) {
    int m = arr.size();     // Number of rows
    int n = arr[0].size();  // Number of columns

    int low = 0, high = (m * n) - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        int row = mid / n;  // Correct row calculation
        int col = mid % n;  // Correct column calculation

        if (arr[row][col] == k) {
            return true; // Element found
        }
        if (arr[row][col] > k) {
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1;  // Search in the right half
        }
    }
    return false; // Element not found
}

int main() {
    int m = 4, n = 3;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    int k = 7;

    if (searchMatrix(matrix, k)) {
        cout << "Element found \n";
    } else {
        cout << "Not found \n";
    }

    return 0;
}
