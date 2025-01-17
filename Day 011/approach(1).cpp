/*
    Title: Maximum Product Subarray
    Description:
        This function calculates the maximum product of a contiguous subarray
        in a given array of integers. It uses dynamic programming and tracks
        the current maximum and minimum products to handle negative values effectively.

    Input:
        - Array of integers (size > 0)
        
    Output:
        - The maximum product of any contiguous subarray

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function to find the maximum product of a contiguous subarray

int maximum_product_subarray(int arr[], int size) {
    if (size < 1) {
        return -1; // Invalid input size
    }

    int curr_min = arr[0]; // Minimum product ending at the current position
    int curr_max = arr[0]; // Maximum product ending at the current position
    int max_product = arr[0]; // Overall maximum product

    for (int i = 1; i < size; i++) {
        // Store current maximum before updating, to avoid overwriting issues
        int temp_max = max({arr[i], curr_max * arr[i], curr_min * arr[i]});

        // Update current minimum product
        curr_min = min({arr[i], curr_max * arr[i], curr_min * arr[i]});

        // Update current maximum product
        curr_max = temp_max;

        // Update the overall maximum product
        max_product = max(max_product, curr_max);
    }

    return max_product;
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
