/*
    Title: 
        Maximum Circular Subarray Sum
    Description:
        This program calculates the maximum sum of a subarray in a circular array.
        A circular array allows wrapping around, enabling subarrays to span the connection 
        between the end and the beginning of the array.

    Input:
        - An integer representing the size of the array
        - The array elements as integers

    Output:
        - The maximum sum of a circular subarray

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate the maximum circular subarray sum
int circularMaxSum(int arr[], int size) {
    int suffixSum = arr[size - 1];
    int maxSuffix[size + 1];
    maxSuffix[size - 1] = arr[size - 1];

    // Build the suffix max array
    for (int i = size - 2; i >= 0; i--) {
        suffixSum += arr[i];
        maxSuffix[i] = max(maxSuffix[i + 1], suffixSum);
    }

    int circularSum = arr[0];
    int normalSum = arr[0];
    int currSum = 0;
    int prefix = 0;

    // Calculate normal and circular subarray sums
    for (int i = 0; i < size; i++) {
        currSum = max(currSum + arr[i], arr[i]);  // Maximum sum subarray (normal)
        normalSum = max(normalSum, currSum);

        prefix += arr[i];  // Prefix sum for circular subarray

        if (i < size - 1) {
            circularSum = max(circularSum, prefix + maxSuffix[i + 1]);  // Combine with suffix
        }
    }

    return max(circularSum, normalSum);  // Return the maximum of the two sums
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
    cout << "Maximum circular subarray sum is " << circularMaxSum(arr, size) << "\n";

    return 0;
}
