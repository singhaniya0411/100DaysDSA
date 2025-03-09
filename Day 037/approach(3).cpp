/*
    Title: Rotate a Matrix 90 Degrees Clockwise

    Problem Statement:
        - Given an **N × N matrix**, rotate it **90 degrees clockwise** **in-place**.
        - Do this **without using extra space**.

    Approach:
        1. **Transpose the matrix** (swap arr[i][j] with arr[j][i]).
        2. **Reverse each row** to complete the rotation.

    Time Complexity: **O(N²)**
    Space Complexity: **O(1)** (In-place rotation)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;


void rotateByNinety(vector<vector<int>> &arr, int n) {
    // Step 1: Transpose the matrix (swap arr[i][j] with arr[j][i])
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(arr[i][j], arr[j][i]);
        }
    }

    // Step 2: Reverse each row to complete the rotation
    for (int i = 0; i < n; i++) {
        reverse(arr[i].begin(), arr[i].end());
    }

    // Print the rotated matrix
    cout << "Rotated Matrix (90 degrees clockwise):" << endl;
    for (const auto& row : arr) {
        for (int val : row) {
            cout << val << "  ";
        }
        cout << "\n";
    }
}

int main() {
    int n = 4;
    vector<vector<int>> matrix = {
        {1, 2, 3, 10},
        {4, 5, 6, 11},
        {7, 8, 9, 12},
        {13, 14, 15, 16}
    };

    rotateByNinety(matrix, n);
    return 0;
}
