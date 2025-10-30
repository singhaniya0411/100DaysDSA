/*
    Title: Rotate a Square Matrix by 180 Degrees.

    Problem Statement:
        - Given an NxN matrix, rotate it **by 180 degrees in place**.
        - Rotation by 180° means each element at (i, j) moves to (n-1-i, n-1-j).

    Approach (In-place Swapping):
        1. For each element in the top half of the matrix (rows 0 → n/2):
           → Swap mat[i][j] with mat[n-1-i][n-1-j].
        2. This reverses both rows and columns simultaneously.
        3. If the matrix has an odd dimension (n is odd), 
           the **middle row** remains unprocessed in step 1.
           So, reverse that middle row separately.

    Example:
        Input:
            mat = [ [1, 2, 3],
                    [4, 5, 6],
                    [7, 8, 9] ]

        Process:
            After step 1:
                [ [9, 8, 7],
                  [6, 5, 4],
                  [3, 2, 1] ]

        Output:
            ✅ Rotated matrix by 180°:
                [ [9, 8, 7],
                  [6, 5, 4],
                  [3, 2, 1] ]

    Dry Run (n=3):
        i=0, j=0 → swap(1, 9)
        i=0, j=1 → swap(2, 8)
        i=0, j=2 → swap(3, 7)
        (middle row reversed for odd n)

    Time Complexity:  O(N²)
    Space Complexity: O(1)

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

// Function to rotate a square matrix by 180 degrees
void rotateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();

    // Swap symmetric elements from top and bottom
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            swap(mat[i][j], mat[n - 1 - i][n - 1 - j]);
        }
    }

    // If n is odd, reverse the middle row
    if (n % 2 == 1) {
        int mid = n / 2;
        for (int j = 0; j < n / 2; j++) {
            swap(mat[mid][j], mat[mid][n - j - 1]);
        }
    }
}

// Driver code
int main() {
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    for (auto &row : mat) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    rotateMatrix(mat);

    cout << "\nMatrix after 180° rotation:\n";
    for (auto &row : mat) {
        for (int x : row) cout << x << " ";
        cout << "\n";
    }

    return 0;
}










