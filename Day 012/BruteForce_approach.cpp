/*
    Title:
        Maximum Circular Subarray Sum
    Description:
        This program calculates the maximum sum of a circular subarray.
        A circular subarray considers the wrapping of indices, allowing subarrays
        to span from the end of the array back to the beginning.

    Input:
        - An integer representing the size of the array
        - The array elements as integers

    Output:
        - The maximum sum of a circular subarray

    Time Complexity:
        - Outer loop runs `n` times (for each starting index of the circular subarray).
        - Inner loop runs `n` times for each starting index.
        - Total Complexity: O(n^2), where `n` is the size of the array.

    Space Complexity:
        - O(1), as no extra space is used apart from a few variables.

    Author: Vishal
    Date: [Insert Date Here]
*/

#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate the maximum sum of a circular subarray
int max_circular_subarray_sum(int arr[], int size) {
    int res = arr[0];

    // Iterating through all starting points
    for (int i = 0; i < size; i++) {
        int curr_sum = 0;

        // Calculating sums for circular subarrays
        for (int j = 0; j < size; j++) {
            int idx = (i + j) % size; // Wrapping around with modulo
            curr_sum += arr[idx];
            res = max(res, curr_sum); // Update the maximum result
        }
    }

    return res;
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i == size - 1) {
            cout << "\n";
        } else {
            cout << "  ";
        }
    }
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

    int arr[size];

    // Input: Array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Output the entered array
    cout << "Your entered array: ";
    printArray(arr, size);

    // Output: Maximum circular subarray sum
    cout << "Maximum sum of circular subarray is: " << max_circular_subarray_sum(arr, size) << "\n";

    return 0;
}
