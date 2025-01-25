/*
    Title: 
        Find Smallest Missing Positive Integer
    Description:
        This program identifies the smallest positive integer that is missing
        from an array of integers. The solution modifies the array in-place
        to achieve an O(n) time complexity without requiring extra space.

    Approach:
        - Rearrange the array such that each positive integer `x` is placed at index `x-1`
          if it falls within the range [1, size].
        - After rearranging, traverse the array to identify the first index `i`
          where `arr[i] != i+1`.
        - Return `i+1` as the smallest missing positive integer.
        - If all indices are correctly arranged, return `size+1`.

        Special Case:
        - Handles cases where the array size is zero or contains all negative integers.

    Input:
        - Size of the array (integer).
        - Array elements (integers).

    Output:
        - Smallest missing positive integer.

    Time Complexity:
        - O(n), as each element is moved to its correct position at most once.

    Space Complexity:
        - O(1), as no additional data structures are used apart from variables.

    Author: Vishal Singhaniya
    
*/

#include <iostream>
using namespace std;

// Function to find the smallest missing positive integer
int find_min_positive(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        while (1 <= arr[i] && arr[i] <= size && arr[i] != arr[arr[i] - 1]) {
            swap(arr[i], arr[arr[i] - 1]);
        }
    }

    for (int i = 0; i < size; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return size + 1;
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
    cout << "Enter the size of the array: ";
    cin >> size;

    // Validate array size
    if (size <= 0) {
        cout << "Invalid array size. Size must be greater than 0.\n";
        return 1;
    }

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Output: Print the input array
    cout << "Your entered array: ";
    printArray(arr, size);

    // Output: Find the minimum missing positive integer
    cout << "Minimum positive integer missing from the array: " << find_min_positive(arr, size) << "\n";

    return 0;
}
