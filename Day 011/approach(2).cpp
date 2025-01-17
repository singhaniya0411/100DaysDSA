/*
    Title: Maximum Product of a Contiguous Subarray
    Description:
        This program calculates the maximum product of a contiguous subarray 
        from a given array of integers. It handles both positive and negative values 
        effectively, considering edge cases like zeros and negative numbers.

    Input:
        - Size of the array (must be greater than 0)
        - Elements of the array

    Output:
        - Maximum product of a contiguous subarray

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

// Function to find the maximum product of a contiguous subarray
int maximum_product_subarray(int arr[], int size) {
    if (size < 1) {
        return -1; // Invalid input size
    }
    int leftToRight = 1;
    int rightToLeft = 1;

    int maxProduct = INT_MIN;
    int j = size - 1;
    for (int i = 0; i < size; i++) {
        if (leftToRight == 0) {
            leftToRight = 1;
        }
        if (rightToLeft == 0) {
            rightToLeft = 1;
        }

        leftToRight = leftToRight * arr[i];

        j = size - 1 - i;

        rightToLeft = rightToLeft * arr[j];

        maxProduct = max({leftToRight, rightToLeft, maxProduct});
    }
    return maxProduct;
}

int main() {
    int size;

    // Input: Size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) {
        cout << "Invalid size. Array size must be greater than 0.\n";
        return 1;
    }

    // Input: Array elements
    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Output: Maximum product of a contiguous subarray
    cout << "\nMaximum product of a subarray in the array: " << maximum_product_subarray(arr, size) << "\n";

    return 0;
}
