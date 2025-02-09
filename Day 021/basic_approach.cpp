/*
    Title: Sort an Array of 0s, 1s, and 2s
    Description:
        - This program sorts an array containing only 0s, 1s, and 2s.
        - It counts occurrences of 0, 1, and 2, then reconstructs the array.

    Approach:
        - Count occurrences of 0s, 1s, and 2s.
        - Overwrite the array based on the counts.

    Time Complexity:
        - O(n), as we traverse the array twice.

    Space Complexity:
        - O(1), as we use only a few extra variables.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Function to sort the array containing only 0s, 1s, and 2s
void sort012(int arr[], int n) {
    int c1 = 0, c2 = 0, c3 = 0;

    // Counting occurrences of 0, 1, and 2
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            c1++;
        } else if (arr[i] == 1) {
            c2++;
        } else {
            c3++;
        }
    }


    // Overwriting array with counted values
    for (int i = 0; i < n; i++) {
        if (c1 > 0) {
            arr[i] = 0;
           
            c1--;
        } else if (c2 > 0) {
            arr[i] = 1;
           
            c2--;
        } else {
            arr[i] = 2;
            
            c3--;
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

    // Sorting the array
    sort012(arr, n);

    // Printing the sorted array
    cout << "\n\nThe sorted array is: ";
    printArray(arr, n);

    return 0;
}
