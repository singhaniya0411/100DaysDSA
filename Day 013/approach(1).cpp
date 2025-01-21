/*
    Title: Find the Minimum Missing Positive Integer
    Description:
        This program identifies the smallest positive integer that is missing from an array.
        The program accounts for both positive and negative numbers, as well as duplicates,
        to accurately compute the result.

    Approach:
        - Sort the array in ascending order.
        - Use a variable `res` initialized to 1 to represent the smallest missing positive integer.
        - Traverse the array:
            - If the current element matches `res`, increment `res`.
            - If the current element exceeds `res`, stop the search as the missing integer is found.
        - Return `res` as the missing positive integer.

    Input:
        - Size of the array (integer).
        - Array elements (integers).

    Output:
        - Smallest positive integer missing from the array.

    Time Complexity:
        - O(n log n): Due to the sorting step.
        - O(n): For traversing the sorted array.
        - Overall: O(n log n).

    Space Complexity:
        - O(1): No extra data structures used apart from variables.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm>
using namespace std;

// Function to find the smallest missing positive integer
int find_min_positive(int arr[], int size)
{
    // Sort the array
    sort(arr, arr + size);
    int res = 1; // Initialize the smallest positive integer

    for (int i = 0; i < size; i++)
    {
        // Check if the current element matches `res`
        if (arr[i] == res)
        {
            res++;
        }
        // Stop if the current element is greater than `res`
        else if (arr[i] > res)
        {
            break;
        }
    }
    return res;
}

// Function to print the array elements
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        if (i == size - 1)
        {
            cout << "\n";
        }
        else
        {
            cout << "  ";
        }
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;

    // Validate array size
    if (size <= 0)
    {
        cout << "Invalid array size. Size must be greater than 0.\n";
        return 1;
    }

    int arr[size];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Output: Print the input array
    cout << "Your entered array: ";
    printArray(arr, size);

    // Output: Find the minimum missing positive integer
    cout << "Minimum positive integer missing from the array: " << find_min_positive(arr, size) << "\n";

    return 0;
}
