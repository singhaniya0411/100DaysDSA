/*
    Title: Finding the K-th Missing Positive Number in a Sorted Array

    Description:
        - Given a sorted array of distinct positive integers, find the K-th missing positive integer.
        - The missing numbers start from 1.
        - The array is sorted in increasing order.

    Approach:
        1. Traverse the array and check for missing numbers.
        2. At each index `i`, check if `arr[i] > (i + k)`.
        3. If condition is met, return `i + k` because this is where the k-th missing element falls.
        4. If no missing number is found within the array, return `size + k` (i.e., the k-th missing number is beyond the array elements).

    Time Complexity:
        - **O(N)** (Iterate through the array once)

    Space Complexity:
        - **O(1)** (No extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

int kthMissing(int arr[], int size, int k) {
    for (int i = 0; i < size; i++) {
        // If missing numbers are found before index i
        if (arr[i] > i + k) {
            return i + k;
        }
    }
    // If k-th missing number is beyond the last element
    return size + k;
}

int main() {
    int size, k;

    // Taking input for array size
    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size]; // Declare the array

    // Taking input for array elements
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Taking input for k
    cout << "Enter the value of k: ";
    cin >> k;

    // Finding and displaying the k-th missing number
    cout << k << "-th missing element from the array is: " << kthMissing(arr, size, k) << endl;

    return 0;
}
