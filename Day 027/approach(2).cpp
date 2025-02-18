/*
    Title: Merge Two Sorted Arrays Without Extra Space (O(n * m) Approach)

    Description:
        - This program merges two sorted arrays `arr1` and `arr2` in **non-decreasing order**.
        - The merging is done **without using extra space**.
        - The first array (`arr1`) has the smallest elements, while the second array (`arr2`) holds the larger elements.

    Approach:
        1. **Iterate** through `arr2` from the last element to the first.
        2. **If an element of `arr2` is smaller** than the largest element in `arr1`, swap it.
        3. **Shift elements of `arr1`** to insert the swapped element in the correct position.
        4. **Repeat the process** to maintain the sorted order.

    Time Complexity:
        - **O(n * m)** (For each element in `arr2`, we perform at most `n` shifts)
    
    Space Complexity:
        - **O(1)** (No extra space used)

    Author: Vishal
*/

#include <iostream>
#include <algorithm>  // For min and max functions
using namespace std;

// Function to merge two sorted arrays in place without extra space
void mergeArray(int arr1[], int size1, int arr2[], int size2) {
    
    // Traverse arr2 from right to left
    for (int i = size2 - 1; i >= 0; i--) {
        // Compare with the largest element of arr1
        if (arr1[size1 - 1] > arr2[i]) {
            int last = arr1[size1 - 1];  // Store the last element of arr1
            int j = size1 - 2;

            // Shift elements of arr1 to make space for arr2[i]
            while (j >= 0 && arr1[j] > arr2[i]) {
                arr1[j + 1] = arr1[j];
                j--;
            }
            
            // Place the element from arr2 at its correct position in arr1
            arr1[j + 1] = arr2[i];

            // Move the largest element of arr1 to arr2
            arr2[i] = last;
        }
    }
}

// Driver function
int main() {
    
    int size1, size2;
    cout << "Enter the size of both arrays: ";
    cin >> size1 >> size2;
    
    int arr1[size1], arr2[size2];
    
    cout << "Enter the elements of the first sorted array: ";
    for (int i = 0; i < size1; i++) {
        cin >> arr1[i];
    }
    
    cout << "Enter the elements of the second sorted array: ";
    for (int i = 0; i < size2; i++) {
        cin >> arr2[i];
    }
    
    // Function call to merge arrays
    mergeArray(arr1, size1, arr2, size2);
    
    // Output the merged arrays
    cout << "Array after merging: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    
    return 0;
}
