/*
    Title: Rotate an N × N Matrix 90 Degrees Clockwise (In-Place)

    Approach:
    - Process the matrix **layer by layer** (like peeling an onion).
    - Swap **four elements** at a time, moving them **clockwise**.
    - Repeat for all **layers** from outermost to innermost.

    Time Complexity: **O(N²)**
    Space Complexity: **O(1)** (In-Place)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;


void rotateByNinety(vector<vector<int>> &arr, int n) {
    for (int i = 0; i < (n / 2); i++) {  
        for (int j = i; j < n - i - 1; j++) {  
            // Perform 4-way swap for 90-degree rotation
            int temp = arr[i][j];
            arr[i][j] = arr[n - 1 - j][i];  
            arr[n - 1 - j][i] = arr[n - 1 - i][n - 1 - j];  
            arr[n - 1 - i][n - 1 - j] = arr[j][n - 1 - i];  
            arr[j][n - 1 - i] = temp;
        }
    }
}

/**
 * @brief Prints the matrix in a formatted way.
 * @param arr The matrix to print.
 */
void printMatrix(const vector<vector<int>> &arr) {
    for (const auto& row : arr) {
        for (int val : row) {
            cout << val << "  ";
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

    cout << "Original Matrix:\n";
    printMatrix(matrix);

    rotateByNinety(matrix, n);

    cout << "\nRotated Matrix (90 degrees clockwise):\n";
    printMatrix(matrix);

    return 0;
}
