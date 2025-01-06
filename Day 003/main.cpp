/*
    Title: Reverse an Array
    Description:
        This program reverses the elements of an integer array in place using a two-pointer approach.
        It demonstrates the reversal by printing the original and reversed arrays.

    Input:
        - The size of the array (n)
        - Array elements (n integers)

    Output:
        - The original array
        - The reversed array

    Author: Vishal Singhaniya

*/

#include <iostream>
using namespace std;

// Function to swap two integers by reference
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Function to reverse an array in place
void reverse_array(int arr[], int n)
{
    if (n < 2)
    {
        return; // No need to reverse if the array has less than 2 elements
    }
    int start = 0, end = n - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

int main()
{
    int size;
    cout << "Enter the size of an array: ";
    cin >> size;
    int A[size];

    cout << "Enter the elements of the array: \n";
    for (int i = 0; i < size; i++)
    {
        cin >> A[i];
    }

    cout << "The original array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }

    reverse_array(A, size);

    cout << "\n\nThe reversed array is: ";
    for (int i = 0; i < size; i++)
    {
        cout << A[i] << " ";
    }

    return 0;
}
