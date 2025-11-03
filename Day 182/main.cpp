/*
    Title: Minimum Operations to Make Matrix Beautiful.

    Problem Statement:
        - You are given a square matrix `mat` of size n × n.
        - A matrix is called "beautiful" if all rows and columns have equal sums.
        - In one operation, you can increment any element of the matrix by 1.
        - The task is to find the **minimum number of operations** required to make the matrix beautiful.

    Approach:
        1. Compute the sum of every row and every column.
        2. Find the **maximum sum** among all rows and columns → this will be the target sum for each row/column.
        3. Compute the **total sum** of all elements in the matrix.
        4. The required operations = (n × maxSum) - totalMatrixSum

    Example:
        Input:
            mat = {
                    {1, 3, 4},
                    {3, 2, 4},
                    {5, 1, 2}
                  }

        Process:
            - Row sums: [8, 9, 8]
            - Column sums: [9, 6, 10]
            - Maximum sum = 10
            - Total sum = 25
            - Required operations = (3 × 10) - 25 = 5

        Output:
            Minimum 5 operations are required to make the matrix beautiful.

    Time Complexity:
        - O(n²), as every element is visited a constant number of times.

    Space Complexity:
        - O(1), using only a few variables for calculations.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int matrixBeautiful(vector<vector<int>> &mat) {
    int n = mat.size();
    
    int matSum = 0;
    int maxSum = 0;
    
    // Find max row sum
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += mat[i][j];
        }
        maxSum = max(sum, maxSum);
    }
    
    // Find max column sum
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            sum += mat[j][i];
        }
        maxSum = max(sum, maxSum);
    }
    
    // Calculate total sum of matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matSum += mat[i][j];
        }
    }
    
    // Formula: (n * maxSum) - totalMatrixSum
    return (n * maxSum) - matSum;
}

int main() {
    vector<vector<int>> mat = {
        {1, 3, 4},
        {3, 2, 4},
        {5, 1, 2}
    };
    
    int minOperation = matrixBeautiful(mat);
    
    cout << "Minimum " << minOperation 
         << " operations are required to make the matrix beautiful.\n";
    
    return 0;
}





















