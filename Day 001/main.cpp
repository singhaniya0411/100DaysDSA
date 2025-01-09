/*
    Title: Find Second Largest Element in an Array
    Description:
        This program finds the second largest element in an array of integers. 
        It iterates through the array, keeping track of the largest and second 
        largest elements. If the array has fewer than two elements, it returns -1.

    Input:
        - Size of the array (n)
        - Array of integers (n elements)

    Output:
        - The second largest element in the array, or -1 if not applicable.

    Author: Vishal
    Date: [Insert Date Here]
*/

#include <iostream>
#include <climits>
using namespace std;

// Function to find the second largest element in the array
int second_largest(int arr[], int n) {
    if (n < 2) { // If the array has fewer than two elements
        return -1;
    }

    int largest = INT_MIN; // Initialize largest element
    int second_largest_element = INT_MIN; // Initialize second largest element

    for (int i = 0; i < n; i++) {
        if (arr[i] > largest) { 
            // Update second largest before updating the largest
            second_largest_element = largest;
            largest = arr[i];
        } else if (arr[i] > second_largest_element && arr[i] != largest) {
            // Update second largest if current element is not equal to the largest
            second_largest_element = arr[i];
        }
    }

    // If second largest is not updated, return -1
    return second_largest_element == INT_MIN ? -1 : second_largest_element;
}



