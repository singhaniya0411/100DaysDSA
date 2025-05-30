/*
    Title: Word Search in a 2D Grid

    Problem Statement:
        - Given a 2D board of characters and a word,
        - Check whether the word exists in the grid by moving horizontally or vertically.

    Approach:
        - Use DFS to explore all paths starting from each cell that matches the first letter.
        - Use a visited marker (`#`) to avoid revisiting the same cell in one path.
        - Try all 4 directions (up, down, left, right) for each character match.

    Time Complexity:
        - O(m*n*4^l) where l = length of the word, and m*n = matrix size

    Space Complexity:
        - O(l) recursion stack, where l = length of the word

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool searchWord(int k, int l, int m, int n, vector<vector<char>>& mat, string word,
                int i, int j, vector<vector<int>>& dir) {
    if (k == l) return true;
    if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] != word[k]) return false;

    char temp = mat[i][j];
    mat[i][j] = '#'; // mark as visited

    for (auto d : dir) {
        int x = i + d[0];
        int y = j + d[1];
        if (searchWord(k + 1, l, m, n, mat, word, x, y, dir)) {
            mat[i][j] = temp; // restore before return
            return true;
        }
    }

    mat[i][j] = temp; // restore cell
    return false;
}

bool iswordExist(vector<vector<char>> mat, string word) {
    int m = mat.size(), n = mat[0].size(), l = word.length();

    vector<vector<int>> dir = {{-1,0},{1,0},{0,-1},{0,1}}; // up, down, left, right

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == word[0]) {
                if (searchWord(0, l, m, n, mat, word, i, j, dir))
                    return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> mat = {
        {'t','e','g'},
        {'w','e','k'},
        {'f','a','s'}
    };

    string word = "geeksg";

    bool result = iswordExist(mat, word);

    if (result)
        cout << "Word is present in Matrix.\n";
    else
        cout << "Word is not present.\n";

    return 0;
}
