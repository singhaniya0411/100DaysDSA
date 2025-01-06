/*
    Title: Rotate an Array using Reversal Algorithm
    Description:
        This program rotates the elements of an integer array to the right by a given number of positions.
        It uses the reversal algorithm for efficient in-place rotation, ensuring O(n) time complexity and O(1) space complexity.
        The rotation involves three key steps:
            1. Reverse the entire array.
            2. Reverse the first part of the array.
            3. Reverse the second part of the array.

    Input:
        - The size of the array (n)
        - Array elements (n integers)
        - The number of rotations (r)

    Output:
        - The original array
        - The rotated array

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Function to rotate the array using the reversal algorithm
void rotate_array(int arr[], int size, int r)
{
    if (size < 2)
    {
        return; // No need to rotate if the array has less than 2 elements
    }
    // Adjust r to avoid unnecessary rotations
    r = r % size;

    // Reverse the entire array
    int start = 0, end = size - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    // Reverse the first part of the array
    start = 0;
    end = size - 1 - r;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }

    // Reverse the second part of the array
    start = size - r;
    end = size - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Utility function to print the array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int size, r;

    cout << "Enter the size of the array: ";
    cin >> size;
    int arr[size];

    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "The original array is: ";
    printArray(arr, size);

    cout << "Enter the number of rotations: ";
    cin >> r;

    rotate_array(arr, size, r);

    cout << "\nThe rotated array is: ";
    printArray(arr, size);

    return 0;
}
