/*
    Title: Search an Element in a Sorted Matrix using Binary Search

    Problem Statement:
        - Implement a function to search for an element in an M x N matrix
          where each row is sorted in increasing order.

    Approach:
        - **Two-Step Binary Search**:
          1. Perform **binary search on the first column** to determine the potential row.
          2. Perform **binary search on the identified row** to find the element.

    Returns:
        - true if the element is found, false otherwise

    Time Complexity:
        - **O(logM + logN)** (where M = rows, N = columns)
        - First binary search takes **O(logM)** to find the row.
        - Second binary search takes **O(logN)** to search within the row.

    Space Complexity:
        - **O(1)** (constant extra space)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to perform binary search on a 1D row
bool search(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
        {
            return true; // Element found
        }
        if (arr[mid] > k)
        {
            high = mid - 1; // Search in the left half
        }
        else
        {
            low = mid + 1; // Search in the right half
        }
    }
    return false; // Element not found
}

// Function to search for an element in a row-wise sorted matrix
bool searchMatrix(vector<vector<int>> &arr, int m, int n, int k)
{
    int row = -1;
    int low = 0, high = m - 1; // Binary search on the first column

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid][0] == k)
        {
            return true; // Element found at the first column
        }

        if (arr[mid][0] < k)
        {
            low = mid + 1;
            row = mid; // Track the last valid row
        }
        else
        {
            high = mid - 1;
        }
    }

    if (row == -1)
    {
        return false; // No suitable row found
    }

    return search(arr[row], k); // Binary search on the selected row
}

int main()
{
    int m = 3, n = 3;
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    int k = 2;

    if (searchMatrix(matrix, m, n, k))
    {
        cout << "Element found \n";
    }
    else
    {
        cout << "Not found \n";
    }

    return 0;
}
