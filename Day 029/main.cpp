/*
    Title: Counting Occurrences of an Element in a Sorted Array (Binary Search Approach)

    Description:
        - This program finds the number of times a given element appears in a sorted array.
        - It uses binary search to efficiently determine the **lower bound** and **upper bound** of the target.
        - The count is given by **(upper bound - lower bound)**.

    Approach:
        1. **Lower Bound (`lowerBound` function)**:
           - Finds the **first occurrence** of the target element in the array.
           - If `arr[mid] >= target`, move `high = mid - 1`, else move `low = mid + 1`.
        2. **Upper Bound (`upperBound` function)**:
           - Finds the **first element greater than** the target.
           - If `arr[mid] > target`, move `high = mid - 1`, else move `low = mid + 1`.
        3. **Count occurrences**:
           - `upperBound - lowerBound` gives the count.

    Time Complexity:
        - **O(log n)** (Binary search in both functions)

    Space Complexity:
        - **O(1)** (Only constant extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Function to find the lower bound (first occurrence) of target
int lowerBound(int arr[], int size, int target)
{
    int low = 0, high = size - 1;
    int result = size; // Default: If target is not found, return size (out of range)

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
        { // Move left if mid is greater or equal to target
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

// Function to find the upper bound (first element greater than target)
int upperBound(int arr[], int size, int target)
{
    int low = 0, high = size - 1;
    int result = size; // Default: If no element is greater, return size (out of range)

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        { // Move left if mid is greater than target
            result = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return result;
}

// Driver function
int main()
{
    int size, target;

    // Input array size
    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    // Input sorted array
    cout << "Enter the elements of the array in sorted order: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Input target element
    cout << "\nEnter the target element: ";
    cin >> target;

    // Calculate occurrences
    int count = upperBound(arr, size, target) - lowerBound(arr, size, target);

    // Output result
    cout << "Occurrences of " << target << " in this array: " << count << endl;

    return 0;
}
