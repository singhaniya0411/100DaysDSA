/*
    Title:
        Search an Element in a Row-wise and Column-wise Sorted Matrix
    
    Problem Statement:
        - Implement a function to search for an element in an M x N matrix 
          where each row and column is sorted in increasing order.

    Approach:
        - Start from the **top-right** corner.
        - Move **left** if the target is smaller.
        - Move **down** if the target is larger.
        - This ensures that we eliminate either a row or a column in each step.

    Returns:
        - true if the element is found, false otherwise
    Time Complexity:
        - **O(M + N)** (where M = rows, N = columns)

    Space Complexity:
        - **O(1)** (constant extra space)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;



bool search(vector<vector<int>> &arr, int m, int n, int k) {
    int i = 0;
    int j = m - 1;

    while (i < n && j >= 0) {
        if (k > arr[i][j]) {
            i++;
        } else if (k < arr[i][j]) {
            j--;
        } else {
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
    int k = 10;

    if (search(matrix, m, n, k)) {
        cout << "Element found \n";
    } else {
        cout << "Not found \n";
    }
    
    return 0;
}
