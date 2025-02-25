/*
    Title: Finding a Peak Element in an Array

    Description:
        - A peak element is an element that is **greater than both its neighbors**.
        - The problem guarantees at least one peak.
        - If multiple peaks exist, any peak index can be returned.

    Approach:
        1. **Naive Approach (O(n))**:
           - Traverse the array and check each element.
           - If an element is greater than both neighbors, return its index.
        

    Time Complexity:
        - **O(n)** (Naive approach)

    Space Complexity:
        - **O(1)** (No extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;


int findPeakNaive(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        bool left = (i == 0 || arr[i] > arr[i - 1]);   // True if left neighbor is smaller
        bool right = (i == n - 1 || arr[i] > arr[i + 1]); // True if right neighbor is smaller

        if (left && right) {
            return i; // Found a peak
        }
    }
    return -1;
}

int main() {
    int n;
    
    // Taking input for array size
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n]; // Declaring array

    // Taking input for array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Finding peak using binary search (optimized approach)
    int peakIndex = findPeakBinary(arr, 0, n - 1, n);

    // Output the result
    cout << "Peak element found at index: " << peakIndex << " (Value: " << arr[peakIndex] << ")\n";

    return 0;
}
