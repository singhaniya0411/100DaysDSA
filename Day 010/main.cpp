/*

    Title: 
        Maximum Sum of Subarray
    Description:
        This program computes the maximum sum of a contiguous subarray in a given array of integers using Kadane's Algorithm. It efficiently tracks the maximum sum as the array is traversed.

    Input:
        - Size of the array (n)
        - Array of integers (n elements)

    Output:
        - The maximum sum of any contiguous subarray within the input array

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to find the maximum sum of a contiguous subarray
int maximum_sum_subarray(int arr[], int size) {
    if (size == 1) { // If the array has only one element
        return arr[0];
    }

    int res = arr[0]; // Initialize result with the first element
    int maxEnding = arr[0]; // Initialize max sum ending at the first element

    for (int i = 1; i < size; i++) {
        // Update maxEnding with the maximum of extending the previous subarray or starting fresh
        maxEnding = max(maxEnding + arr[i], arr[i]);
        // Update the result if maxEnding is greater than the current result
        res = max(res, maxEnding);
    }
    return res;
}

int main() {
    int size;

    // Input: Size of the array
    cout << "Enter the size of the array: ";
    cin >> size;

    if (size <= 0) { // Handle invalid array size
        cout << "Invalid size. Array size must be greater than 0.\n";
        return 1;
    }

    // Input: Array elements
    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Output: Maximum sum of a contiguous subarray
    cout << "\nMaximum sum of a subarray in the array: " << maximum_sum_subarray(arr, size) << "\n";

    return 0;
}
