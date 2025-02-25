/*
    Title: Finding a Peak Element in an Array (Binary Search Approach)

    Description:
        - A peak element is an element that is **greater than or equal to its neighbors**.
        - The program efficiently finds a peak using **binary search**.

    Approach:
        1. **Binary Search (O(log n))**:
           - Calculate `mid` of the current search space.
           - If `arr[mid]` is **greater than both** neighbors, return `mid`.
           - If the **right neighbor is greater**, move **right** (`low = mid + 1`).
           - Else, move **left** (`high = mid - 1`).

    Time Complexity:
        - **O(log n)** (Efficient binary search approach)

    Space Complexity:
        - **O(1)** (Only constant extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;


int findPeakBinary(int arr[], int low, int high, int n) {
    while (low <= high) {
        int mid = (low + high) / 2;

        // Check if mid is a peak element
        if ((mid == 0 || arr[mid] >= arr[mid - 1]) &&  // Check left neighbor
            (mid == n - 1 || arr[mid] >= arr[mid + 1])) {  // Check right neighbor
            return mid;
        }

        // If the right neighbor is greater, move right
        if (mid < n - 1 && arr[mid] < arr[mid + 1]) {
            low = mid + 1;
        }
        // Else, move left
        else {
            high = mid - 1;
        }
    }
    return -1; // This case should never be reached if input conditions are met
}

int main() {
    int n; 

    // Taking input for the array size
    cout << "Enter the size of the array: ";
    cin >> n;

    int arr[n]; // Declare array

    // Taking input for array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Finding the peak element index
    int peakIndex = findPeakBinary(arr, 0, n - 1, n);

    // Display result
    cout << "Peak element found at index: " << peakIndex << " (Value: " << arr[peakIndex] << ")\n";

    return 0;
}
