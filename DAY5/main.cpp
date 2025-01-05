/*
    Title: Find Next Lexicographical Permutation
    Description:
        This program computes the next lexicographical permutation of a given integer sequence.
        If the sequence is the largest permutation, it rearranges the sequence to the smallest
        (ascending order).

        The approach involves:
            1. Identifying the pivot (the rightmost element smaller than its successor).
            2. Swapping the pivot with the smallest element larger than the pivot to its right.
            3. Reversing the sequence to the right of the pivot.

    Input:
        - The size of the sequence (n)
        - Sequence elements (n integers)

    Output:
        - The next lexicographical permutation or the smallest permutation if the input is the largest.

    Author: Vishal Singhaniya

*/

#include <iostream>
using namespace std;

// Function to compute the next lexicographical permutation
void function(int arr[], int size)
{
    int pivot = -1;
    int left, right;

    // Step 1: Find the pivot (rightmost element smaller than its successor)
    for (int i = size - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            pivot = i;
            break;
        }
    }

    // Step 2: If no pivot is found, reverse the entire array (smallest permutation)
    if (pivot == -1)
    {
        left = 0;
        right = size - 1;
        while (left < right)
        {
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
        return;
    }

    // Step 3: Find the smallest element larger than the pivot to its right and swap
    for (int i = size - 1; i > pivot; i--)
    {
        if (arr[i] > arr[pivot])
        {
            swap(arr[i], arr[pivot]);
            break;
        }
    }

    // Step 4: Reverse the elements to the right of the pivot
    left = pivot + 1;
    right = size - 1;
    while (left < right)
    {
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
}

// Utility function to print an array
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
    int size;
    cout << "Enter the size of the sequence: ";
    cin >> size;
    int arr[size];

    cout << "Enter the elements of the sequence: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << "Your entered sequence is: ";
    printArray(arr, size);

    function(arr, size);

    cout << "Next lexicographical permutation is: ";
    printArray(arr, size);

    return 0;
}
