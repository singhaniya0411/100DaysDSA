/*
    Title: Sudoku Solver using Recursion and Backtracking

    Problem Statement:
        - Given a 9x9 Sudoku board with some cells filled and others empty (denoted by 0),
        - Fill the board such that each row, column, and 3x3 subgrid contains digits 1 to 9 exactly once.

    Approach:
        - Use backtracking with pruning to try placing numbers from 1 to 9 in empty cells.
        - Use bitmasking to efficiently track which numbers are already used in:
            1. each row (rows[i])
            2. each column (cols[j])
            3. each 3x3 subgrid (squ[k])
        - For each empty cell, try placing valid digits, and recursively solve the rest of the board.
        - Backtrack if no valid number fits.

    Time Complexity:
        - Worst-case O(9^(n^2)) due to recursion, but bitmasking and pruning reduce unnecessary calls.

    Space Complexity:
        - O(1) extra space (only arrays of size 9 used for rows, columns, and squares).
        

    Author: Vishal Singhaniya.
*/

#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int num, int i, int j, vector<int>& rows, vector<int>& cols, vector<int>& squ) {
    
    // Checking whether a element is already placed in row,col or 3x3 grid.
    if (cols[j] & (1 << num)) return false;
    if (rows[i] & (1 << num)) return false;
    if (squ[(i / 3) * 3 + (j / 3)] & (1 << num)) return false;
    return true;
}

bool sudokuRecursion(int i, int j, int n, vector<vector<int>>& mat,
                     vector<int>& rows, vector<int>& cols, vector<int>& squ) {
    
    // If reached at last then return true
    if (i == n - 1 && j == n) return true;
    
    // If reached at last in row then switch to first col of next row
    if (j == n) { 
        i++; j = 0;
    }
        
    // If mat[i][j] already filled with a number then skip this col of current row
    if (mat[i][j] != 0) 
        return sudokuRecursion(i, j + 1, n, mat, rows, cols, squ);
    
    // Try num 1-9 for the particular col if it is empty
    for (int num = 1; num <= 9; num++) {
        if (isSafe(num, i, j, rows, cols, squ)) {
            mat[i][j] = num;
            
            // bit manipulating in rows ,col and grid using bitwise OR
            rows[i] |= (1 << num);
            cols[j] |= (1 << num);
            squ[(i / 3) * 3 + (j / 3)] |= (1 << num);
                
            
            if (sudokuRecursion(i, j + 1, n, mat, rows, cols, squ)) {
                return true;
            }

            // Backtrack
            mat[i][j] = 0;
            rows[i] &= ~(1 << num);
            cols[j] &= ~(1 << num);
            squ[(i / 3) * 3 + (j / 3)] &= ~(1 << num);
        }
    }
    return false;
}

void solveSudoku(vector<vector<int>>& mat, int n) {
    vector<int> rows(n, 0), cols(n, 0), squ(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] != 0) {
                int num = mat[i][j];
                rows[i] |= (1 << num);
                cols[j] |= (1 << num);
                squ[(i / 3) * 3 + (j / 3)] |= (1 << num);
            }
        }
    }

    if (sudokuRecursion(0, 0, n, mat, rows, cols, squ)) {
        cout << "Solved Sudoku:\n\n";
        for (const auto& row : mat) {
            for (int num : row) cout << num << "  ";
            cout << endl;
        }
    } else {
        cout << "No Solution exists.\n";
    }
}

int main() {
    int n = 9;

    vector<vector<int>> mat = {
        {0, 0, 0, 1, 0, 0, 3, 0, 0},
        {0, 8, 2, 0, 6, 0, 4, 7, 0},
        {0, 0, 0, 0, 4, 0, 0, 1, 0},
        {0, 2, 0, 4, 0, 1, 7, 0, 8},
        {8, 5, 0, 7, 0, 0, 2, 0, 0},
        {7, 0, 3, 9, 8, 2, 0, 0, 0},
        {2, 7, 0, 5, 9, 4, 0, 0, 3},
        {4, 0, 6, 8, 1, 0, 5, 0, 7},
        {3, 0, 0, 0, 2, 0, 0, 9, 0}
    };

    solveSudoku(mat, n);
    
    return 0;
}
