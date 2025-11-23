/*
    Title: Largest Zero-Sum Submatrix in a 2D Matrix

    Problem Statement:
        - You are given a 2D matrix of integers (positive, negative, or zero).
        - Your task is to find the area (number of cells) of the largest
          rectangular submatrix whose sum of all elements is exactly 0.

    Subproblems:
        1. Find the longest subarray in 1D whose sum is 0.
        2. Extend this idea to 2D matrices.

    Approach:

        Part 1: Longest Zero-Sum Subarray (1D)
        --------------------------------------
        - Use prefix sum and a hash map:
            • Maintain running sum `prefSum`.
            • If `prefSum == 0`, then subarray [0..i] has sum 0.
            • If `prefSum` was seen earlier at index `j`, then subarray (j+1..i)
              has sum 0 and length = i - j.
            • Use `unordered_map<prefSum, earliest_index>` to track first occurrence.

        Part 2: Largest Zero-Sum Submatrix (2D)
        ---------------------------------------
        - Fix a pair of rows (top = i, bottom = j).
        - For these rows, compress the matrix into a 1D array `temp` of size `col`:
              temp[c] = sum of elements from row i to row j in column c.
        - Now the problem becomes:
              "Find longest zero-sum subarray in temp"
          using the 1D method from Part 1.
        - The area contributed by this submatrix is:
              height = (j - i + 1)
              width  = longest zero-sum subarray length
              area   = height * width
        - Iterate over all possible row pairs and update the maximum area.

    Example:
        Input:
            mat = {
                { 1,  2,  3},
                {-3, -2, -1},
                { 1,  7,  5}
            }

        One zero-sum submatrix:
            Rows 0..1, Cols 0..2:
                [ 1,  2,  3
                 -3, -2, -1 ] → sum = 0

            Area = 2 (rows) * 3 (cols) = 6

        Output:
            Largest rectangular area = 6

    Dry Run (High-level):
        - Fix top row i = 0:
            For bottom j = 0,1,2 build temp and run longest zero-sum subarray.
        - Fix top row i = 1:
            For bottom j = 1,2 do the same.
        - Fix top row i = 2:
            For bottom j = 2.
        - Track maximum area across all combinations.

    Time Complexity:
        - O(R² * C), where:
              R = number of rows,
              C = number of columns.
        - Explanation:
              • O(R²) row pairs,
              • Each pair builds a temp array in O(R*C) over the loop,
              • plus O(C) for 1D zero-sum subarray (amortized).

    Space Complexity:
        - O(C) for temp array and hash map used in the 1D routine.

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the longest subarray with sum = 0 in 1D array
int maxZeroSumSubarray(vector<int> &arr) {
    int prefSum = 0;
    int maxLength = 0;
    unordered_map<int,int> mp;  // prefixSum -> first index

    for (int i = 0; i < (int)arr.size(); i++) {
        prefSum += arr[i];

        // Case 1: subarray from 0..i has sum 0
        if (prefSum == 0) {
            maxLength = i + 1;
        }

        // Case 2: subarray from (mp[prefSum] + 1 .. i) has sum 0
        if (mp.find(prefSum) != mp.end()) {
            maxLength = max(maxLength, i - mp[prefSum]);
        } else {
            // store first occurrence of this prefix sum
            mp[prefSum] = i;
        }
    }
    return maxLength;
}

// Function to find the largest-area zero-sum submatrix
int zeroSumSubmat(vector<vector<int>>& mat) {
    int row = mat.size();
    if (row == 0) return 0;
    int col = mat[0].size();
    int maxArea = 0;

    // Fix top row
    for (int top = 0; top < row; top++) {
        vector<int> temp(col, 0);

        // Extend bottom row
        for (int bottom = top; bottom < row; bottom++) {
            // Add current row to temp
            for (int k = 0; k < col; k++) {
                temp[k] += mat[bottom][k];
            }

            // Find longest zero-sum subarray in temp
            int len = maxZeroSumSubarray(temp);
            int height = bottom - top + 1;
            maxArea = max(maxArea, height * len);
        }
    }
    return maxArea;
}

int main() {
    vector<vector<int>> mat = {
        { 1,  2,  3},
        {-3, -2, -1},
        { 1,  7,  5}
    };

    cout << "Given matrix:\n";
    for (auto &row : mat) {
        for (auto val : row) {
            cout << setw(2) << val << " ";
        }
        cout << "\n";
    }

    int res = zeroSumSubmat(mat);
    cout << "\nLargest rectangular area with sum 0: " << res << "\n";

    return 0;
}









