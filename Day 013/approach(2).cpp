/*
    Title: Find the Minimum Missing Positive Integer
    Description:
        This program identifies the smallest positive integer that is missing from an array.
        The solution ensures linear complexity by using a boolean array to track the presence
        of positive integers up to the size of the array.

    Approach:
        - Use a `visited` boolean array initialized to `false` to track the presence of integers.
        - Mark `visited[arr[i]-1]` as `true` for elements that are positive and within the array size.
        - Traverse the `visited` array to find the first unmarked position, which corresponds to the missing integer.
        - If all positions are marked, return `size + 1`.

    Input:
        - Size of the array (integer).
        - Array elements (integers).

    Output:
        - The smallest positive integer missing from the array.

    Time Complexity:
        - O(n): Traversing the array and checking the `visited` array.

    Space Complexity:
        - O(n): For the additional `visited` array.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Function to find the smallest missing positive integer
int find_min_positive(int arr[], int size) {
    // Create a visited array to track presence of positive integers
    bool visited[size] = {false};

    // Mark elements present in the array
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] <= size) {
            visited[arr[i] - 1] = true;
        }
    }

    // Find the first unvisited index
    for (int i = 0; i < size; i++) {
        if (!visited[i]) {
            return i + 1;
        }
    }

    // If all positions are visited, return the next integer
    return size + 1;
}

// Function to print the array elements
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
