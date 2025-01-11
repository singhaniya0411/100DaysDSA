/*
    Title: Minimize Tower Height Difference
    Description:
        Given an array representing the heights of towers, this program minimizes 
        the difference between the tallest and shortest tower heights after modifying 
        each tower height by either adding or subtracting a value `k`.

    Input:
        - Array of tower heights
        - Positive integer `k`

    Output:
        - Minimum difference between the tallest and shortest tower heights

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int find_difference(int arr[], int size, int k) {
    // Sort the array to arrange towers by height
    sort(arr, arr + size);

    // Initial difference between the tallest and shortest towers
    int res = arr[size - 1] - arr[0];

    // Iterate to find the minimum difference
    for (int i = 1; i < size; i++) {
        // Ensure no tower height becomes negative
        if (arr[i] - k >= 0) {
            int minH = min(arr[0] + k, arr[i] - k);         // Potential new minimum height
            int maxH = max(arr[i - 1] + k, arr[size - 1] - k); // Potential new maximum height
            res = min(res, maxH - minH);                   // Update result with smaller difference
        }
    }
    return res;
}

int main() {
    int size, k;

    // Input: Size of the array
    cout << "Enter the size of the array: ";
    cin >> size;
    if (size <= 0) {
        cout << "Invalid size. The size of the array must be greater than 0.\n";
        return 1;
    }

    // Input: Tower heights
    int arr[size];
    cout << "Enter the heights of the towers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
        if (arr[i] < 0) {
            cout << "Invalid height. Tower heights must be non-negative.\n";
            return 1;
        }
    }

    // Input: Value of k
    cout << "Enter a positive integer (k): ";
    cin >> k;
    if (k < 0) {
        cout << "Invalid input. k must be a positive integer.\n";
        return 1;
    }

    // Output: Minimum difference
    int result = find_difference(arr, size, k);
    cout << "The minimum difference between the tallest and shortest towers after the operation is: " << result << "\n";

    return 0;
}