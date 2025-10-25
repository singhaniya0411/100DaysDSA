/*
    Title: Find Bitonic Point in an Array.....

    Problem Statement:
        - A **bitonic array** first increases and then decreases.
        - The task is to find the **maximum element** (bitonic point) in such an array.

    Approach:
        1. If the array has only one element, return it directly.
        2. Check if the first or last element is the peak:
            - If `arr[0] > arr[1]`, return `arr[0]`.
            - If `arr[n-1] > arr[n-2]`, return `arr[n-1]`.
        3. Use **binary search** between indices `1` and `n-2`:
            - If `arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]`, return `arr[mid]`.
            - If `arr[mid] > arr[mid+1]`, search left (`high = mid - 1`).
            - Else, search right (`low = mid + 1`).
        4. Return the bitonic point found.

    Example:
        Input:
            arr = [1, 2, 3, 7, 9, 800, 11, 7, 3, 2]
        
        Process:
            - The array increases till 800, then decreases.
            - 800 is the peak (bitonic point).
        
        Output:
            ✅ The bitonic point of the array is 800

    Time Complexity:
        - O(log N): Binary search on the array.

    Space Complexity:
        - O(1): Constant extra space.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int bitonicPoint(vector<int> &arr) {
    int n = arr.size();

    if (n == 1 || arr[0] > arr[1]) {
        return arr[0];
    }

    if (arr[n - 2] < arr[n - 1]) {
        return arr[n - 1];
    }

    int low = 1, high = n - 2;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
            return arr[mid];
        } else if (arr[mid] > arr[mid + 1]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return arr[high];
}

int main() {
    vector<int> arr = {1, 2, 3, 7, 9, 800, 11, 7, 3, 2};

    cout << "\nThe bitonic point of the array [ ";
    for (int x : arr) cout << x << " ";
    cout << "] is " << bitonicPoint(arr) << "\n";

    return 0;
}





