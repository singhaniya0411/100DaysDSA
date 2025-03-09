/*
    Title: Rotate a Matrix by 90 Degrees
    
    Problem Statement:
        - Given an N x N matrix, rotate it 90 degrees in a anticlockwise direction.
        - The rotation should be performed using an auxiliary matrix.
    
    Approach:
        1. **Use an extra matrix** to store the rotated values.
        2. **Iterate over the original matrix** and place each element in its correct position.
        3. **Print the rotated matrix** as the final output.
    
    Time Complexity: **O(N²)**
    Space Complexity: **O(N²)** (Since we use an extra matrix)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

/**
 * @brief Rotates an NxN matrix by 90 degrees clockwise using an auxiliary matrix.
 * 
 * @param arr The original 2D matrix.
 * @param n The dimension of the square matrix.
 */
void rotateByNinety(vector<vector<int>> &arr, int n) {
    // Step 1: Create an auxiliary matrix of size n x n
    vector<vector<int>> res(n, vector<int>(n));

    // Step 2: Rotate the matrix by placing elements in the correct position
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res[n - 1 - j][i] = arr[i][j];
        }
    }

    // Step 3: Print the rotated matrix
    cout << "Rotated Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << res[i][j] << "  ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 3;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateByNinety(matrix, n);
    return 0;
}
