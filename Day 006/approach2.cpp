/*
    Title:Find Majority Elements in an Array
    Description:
        This program finds all the majority elements in an array.
        A majority element is an element that appears more than n/3 times
        in the array, where n is the size of the array. The implementation
        uses the Boyer-Moore Voting Algorithm, which runs in O(n) time
        and uses O(1) additional space .

    Input:
        - Size of the array (n)
        - Array elements (n integers)

    Output:
        - The majority elements in the array (if any)
        - If no majority element exists, the output will be empty

    Author: Vishal Singhaniya
*/
#include <iostream>
using namespace std;

// Function to find and print majority elements
void find_majority(int arr[], int size)
{
    int ele1 = -1, ele2 = -1;   // Potential majority elements
    int count1 = 0, count2 = 0; // Counts for potential elements

    // First pass: Identify potential majority elements
    for (int i = 0; i < size; i++)
    {
        if (count1 == 0 && arr[i] != ele2)
        {
            ele1 = arr[i];
            count1++;
        }
        else if (count2 == 0 && arr[i] != ele1)
        {
            ele2 = arr[i];
            count2++;
        }
        else if (arr[i] == ele1)
        {
            count1++;
        }
        else if (arr[i] == ele2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    // Reset counts for validation
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == ele1)
        {
            count1++;
        }
        else if (arr[i] == ele2)
        {
            count2++;
        }
    }

    // Output the majority elements
    if (count1 > size / 3)
    {
        cout << ele1 << " ";
    }
    if (count2 > size / 3)
    {
        cout << ele2;
    }
}

// Helper function to print the elements of an array
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i];
        cout << ((i == size - 1) ? "\n" : " , ");
    }
    cout << "\n\n";
}

int main()
{
    int size;

    // Input: Size of the array
    cout << "Enter the size of array: ";
    cin >> size;

    // Input: Array elements
    int arr[size];
    cout << "Enter the elements of array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    // Output: Array elements
    cout << "Array: ";
    printArray(arr, size);

    // Output: Majority elements
    cout << "The majority elements in array: ";
    find_majority(arr, size);
    cout << "\n";

    return 0;
}
