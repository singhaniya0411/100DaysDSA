/*
    Title:     
           Search an Element in a Row-wise and Column-wise Sorted Matrix
    
    Problem Statement:
        - Implement a function to search for an element in an M x N matrix 
          where each row and column is sorted in increasing order.

    Approach:
        - Iterate through the entire matrix using a **brute-force** approach.
        - Compare each element with the target value.
        - If the target value is found, return `true`, else return `false`.

    Returns:
        - true if the element is found, false otherwise

    Time Complexity:
        - **O(M * N)** (where M = rows, N = columns)

    Space Complexity:
        - **O(1)** (constant extra space)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to search for an element in a matrix
bool search(vector<vector<int>> &arr, int m, int n, int k) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (k == arr[i][j]) {
                return true; // Element found
            }
        }
    }
    return false; // Element not found
}

int main() {
    int m = 3;
    int n = 3;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int k = 6;

    if (search(matrix, m, n, k)) {
        cout << "Element found \n";
    } else {
        cout << "Not found \n";
    }

    return 0;
}
