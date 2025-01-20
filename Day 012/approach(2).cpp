#include <iostream>
#include <cmath>
using namespace std;

/*
    Title: Maximum Circular Subarray Sum
    Description:
        This program calculates the maximum sum of a circular subarray.
        A circular subarray considers the wrapping of indices, allowing subarrays
        to span from the end of the array back to the beginning.

    Approach:
        - Use Kadane's Algorithm to find:
          1. Maximum subarray sum (`normal_sum`).
          2. Minimum subarray sum (`minimum_sum`).
        - Compute total array sum (`total_sum`).
        - Calculate circular sum as `circular_sum = total_sum - minimum_sum`.
        - Return the maximum of `normal_sum` and `circular_sum`.

        Special Case:
        - If all elements are negative, return `normal_sum` directly,
          as `circular_sum` would incorrectly consider the entire array.

    Input:
        - Size of the array (integer).
        - Array elements (integers).

    Output:
        - Maximum sum of a circular subarray.

    Time Complexity:
        - O(n), as it uses a single loop to calculate all required sums.

    Space Complexity:
        - O(1), as no additional data structures are used apart from variables.

    Author: Vishal Singhaniya
*/

int maximimum_sum_circular_subarray(int arr[], int size) {
    int maximum_sum = arr[0];   // Maximum subarray sum
    int minimum_sum = arr[0];   // Minimum subarray sum
    int curr_max_sum = 0;       // Current max sum for Kadane's algorithm
    int curr_min_sum = 0;       // Current min sum for Kadane's algorithm
    int total_sum = 0;          // Sum of all elements in the array

    for (int i = 0; i < size; i++) {
        // Compute the maximum subarray sum
        curr_max_sum = max(curr_max_sum + arr[i], arr[i]);
        maximum_sum = max(maximum_sum, curr_max_sum);

        // Compute the minimum subarray sum
        curr_min_sum = min(curr_min_sum + arr[i], arr[i]);
        minimum_sum = min(minimum_sum, curr_min_sum);

        // Update the total sum
        total_sum += arr[i];
    }

    int normal_sum = maximum_sum;
    int circular_sum = total_sum - minimum_sum;

    // Handle the edge case where all elements are negative
    if (minimum_sum == total_sum) {
        return normal_sum;
    }

    return max(normal_sum, circular_sum);
}

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
    cout << "Maximum sum of circular subarray: " << maximimum_sum_circular_subarray(arr, size) << "\n";

    return 0;
}
