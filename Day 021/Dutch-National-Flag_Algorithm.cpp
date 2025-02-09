/*
    Title: Sort an Array of 0s, 1s, and 2s (Dutch National Flag Algorithm)
    Description:
        - This program sorts an array containing only 0s, 1s, and 2s.
        - It uses the **Dutch National Flag Algorithm** for sorting.

    Approach:
        - Maintain three pointers: `low`, `mid`, and `high`.
        - Swap elements and adjust pointers accordingly:
            - If `arr[mid] == 0`, swap with `arr[low]` and increment both `low` and `mid`.
            - If `arr[mid] == 1`, increment `mid`.
            - If `arr[mid] == 2`, swap with `arr[high]` and decrement `high`.

    Time Complexity:
        - O(n), as we traverse the array once.

    Space Complexity:
        - O(1), as sorting is done in place.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Function to sort the array containing only 0s, 1s, and 2s
void sort012(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        } else if (arr[mid] == 1) {
            mid++;
        } else { // arr[mid] == 2
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
            cout << "  ";
        } else {
            cout << "\n";
        }
    }
}

int main() {
    int n;

    // Taking input for array size
    cout << "Enter the size of array: ";
    cin >> n;

    int arr[n];

    // Taking input for array values
    cout << "Enter the values in array (only 0, 1, 2): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Printing the entered array
    cout << "Your entered array is: ";
    printArray(arr, n);

    // Sorting the array using Dutch National Flag Algorithm
    sort012(arr, n);

    // Printing the sorted array
    cout << "\n\nThe sorted array is: ";
    printArray(arr, n);

    return 0;
}
