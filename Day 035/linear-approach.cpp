/*
    Title: Find K-th Smallest Element in Two Sorted Arrays (Merge Approach)
    
    Problem Statement:
        - Given two sorted arrays, find the **k-th smallest element** efficiently.
        - The arrays are sorted in non-decreasing order.
    
    Approach:
        1. **Use a merge approach** to simulate the merging of two sorted arrays.
        2. **Maintain two pointers (`x` and `y`)** to track the position in each array.
        3. **Advance the pointer with the smaller element** until reaching the k-th element.
        4. **Return the k-th smallest element**.
    
    Time Complexity: **O(k)** (We iterate at most k times)
    Space Complexity: **O(1)** (No extra space used apart from variables).
    
    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

int findKthSmallest(vector<int> &arr1, vector<int> &arr2, int size1, int size2, int k) {
    int x = 0, y = 0;

    // Merge until we reach the k-th element
    while (--k > 0) {
        if (x < size1 && (y >= size2 || arr1[x] < arr2[y])) {
            x++;  // Move pointer in arr1
        } else {
            y++;  // Move pointer in arr2
        }
    }

    // Return the k-th smallest element
    return (x < size1 && (y >= size2 || arr1[x] < arr2[y])) ? arr1[x] : arr2[y];
}

int main() {
    int size1, size2, k;
    cout << "Enter the size of first and second array: ";
    cin >> size1 >> size2;

    vector<int> arr1(size1), arr2(size2);

    // Taking input for both sorted arrays
    cout << "Enter elements of first sorted array: ";
    for (int &num : arr1) cin >> num;

    cout << "Enter elements of second sorted array: ";
    for (int &num : arr2) cin >> num;

    cout << "Enter the value of k: ";
    cin >> k;

    // Handling invalid k cases
    if (k > 0 && k <= size1 + size2) {
        cout << k << "-th smallest element is: "
             << findKthSmallest(arr1, arr2, size1, size2, k) << endl;
    } else {
        cout << "Invalid value of k!" << endl;
    }
    return 0;
}
