/*
    Title: Fill a Matrix in Spiral Order .

    Problem Statement:
        Given a 1D array of size n*m, fill a matrix of size n x m 
        in a spiral order starting from the top-left corner.

    Example:
        Input: arr = [1,2,3,4,5,6,7,8,9,10,11,12], n = 3, m = 4
        Output:
            [ 1,  2,  3,  4 ]
            [10, 11, 12,  5 ]
            [ 9,  8,  7,  6 ]

    Approach:
        - Initialize 4 boundaries: top, bottom, left, right
        - Fill top row → right column → bottom row → left column
        - Shrink boundaries after each spiral cycle
        - Continue until all elements are placed

    Time Complexity:  O(N*M)
    Space Complexity: O(1)

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> spiralMatrix(vector<int> &arr, int n, int m) {
    vector<vector<int>> res(n, vector<int>(m, 0));
    
    int top = 0, bottom = n - 1, left = 0, right = m - 1;
    int index = 0;

    while (index < arr.size()) {
        // Traverse from left to right
        for (int j = left; j <= right && index < arr.size(); j++) {
            res[top][j] = arr[index++];
        }
        top++;

        // Traverse from top to bottom
        for (int i = top; i <= bottom && index < arr.size(); i++) {
            res[i][right] = arr[index++];
        }
        right--;

        // Traverse from right to left
        for (int j = right; j >= left && index < arr.size(); j--) {
            res[bottom][j] = arr[index++];
        }
        bottom--;

        // Traverse from bottom to top
        for (int i = bottom; i >= top && index < arr.size(); i--) {
            res[i][left] = arr[index++];
        }
        left++;
    }

    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int n = 3, m = 4;

    vector<vector<int>> matrix = spiralMatrix(arr, n, m);

    cout << "Matrix filled in spiral order:\n";
    for (auto &row : matrix) {
        for (int x : row) cout << setw(3) << x;
        cout << "\n";
    }

    return 0;
}





