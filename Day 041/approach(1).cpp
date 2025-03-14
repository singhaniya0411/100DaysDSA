/*
    Title: Set Matrix Zeroes

    Problem Statement:
        - Implement a function to modify an M × N matrix such that if an element 
          is 0, its entire row and column are set to 0.

    Approach:
        - Use two boolean vectors to track which rows and columns should be zeroed.
        - Traverse the matrix once to mark the rows and columns that contain 0.
        - Traverse the matrix again to update the marked rows and columns to 0.

    Returns:
        - The modified matrix with appropriate rows and columns set to zero.

    Time Complexity:
        - **O(M * N)** (traverse the matrix twice)

    Space Complexity:
        - **O(M + N)** (extra space for row and column markers)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to modify the matrix by setting entire rows and columns to zero if an element is zero
void setZeroMatrix(vector<vector<int>> &arr) {
    int m = arr.size();
    int n = arr[0].size();
    
    // Boolean vectors to track zero rows and columns
    vector<bool> row(m, false);
    vector<bool> col(n, false);
    
    // Step 1: Identify rows and columns that should be zeroed
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 0) {
                row[i] = true;
                col[j] = true;
            }
        }
    }
    
    // Step 2: Update the matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (row[i] || col[j]) {
                arr[i][j] = 0;
            }
        }
    }
    
    // Step 3: Print the final matrix
    cout << "Matrix after setting zeroes:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

// Main function to test the setZeroMatrix function
int main() {
    int m = 4, n = 3;
    vector<vector<int>> matrix = {
        {0, 2, 0},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12}
    };
    
    // Call the function
    setZeroMatrix(matrix);

    return 0;
}
