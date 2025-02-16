/*
    Title: Inversion Count in an Array (O(n log n) Approach)
    
    Description:
        - This program counts the number of **inversions** in an array efficiently.
        - An inversion is when **arr[i] > arr[j]** for **i < j**.
        - This approach uses **Merge Sort** to count inversions while sorting.

    Approach:
        - **Divide and Conquer** using **Merge Sort**.
        - While merging, count the number of elements in the left subarray that 
          are greater than elements in the right subarray.

    Time Complexity:
        - **O(n log n)** (Efficient for large inputs)

    Space Complexity:
        - **O(n)** (Temporary arrays used during merging)

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Merge function that counts the number of inversions while merging
int merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // Size of left subarray
    int n2 = right - mid;      // Size of right subarray

    // Temporary arrays
    int L[n1], R[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left; 
    int count = 0; // Count of inversions

    // Merge the two subarrays while counting inversions
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) { // No inversion
            arr[k++] = L[i++];
        } else { 
            arr[k++] = R[j++];
            count += (n1 - i);  // Count inversions
        }
    }

    // Copy remaining elements of L[]
    while (i < n1) {
        arr[k++] = L[i++];
    }

    // Copy remaining elements of R[]
    while (j < n2) {
        arr[k++] = R[j++];
    }

    return count;
}

// Recursive function to count inversions using Merge Sort
int count_inversion_merge_sort(int arr[], int left, int right) {
    int count = 0;
    
    if (left < right) {
        int mid = (left + right) / 2;

        // Count inversions in left half
        count += count_inversion_merge_sort(arr, left, mid);
        
        // Count inversions in right half
        count += count_inversion_merge_sort(arr, mid + 1, right);

        // Count split inversions while merging
        count += merge(arr, left, mid, right);
    }
    
    return count;
}

// Driver function
int main() {
    int size;
    
    // Taking input for array size
    cout << "Enter the size of array: ";
    cin >> size;
    
    int arr[size];

    // Taking input for array elements
    cout << "Enter the elements of array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // Displaying inversion count
    cout << "Inversion count of this array: " << count_inversion_merge_sort(arr, 0, size - 1);
    
    return 0;
}
