/*
    Title: Find Lower Bound Index using Binary Search.

    Problem Statement:
        - Given a sorted array `arr` and a target value `target`,
          find the **smallest index** such that `arr[index] >= target`.
        - If no such index exists, return the size of the array.

    Approach:
        1. Initialize `low = 0`, `high = n - 1`, and `result = n`.
        2. Perform a binary search:
            - Compute `mid = (low + high) / 2`.
            - If `arr[mid] >= target`, store `mid` in `result`
              and move to the left half (`high = mid - 1`).
            - Otherwise, move to the right half (`low = mid + 1`).
        3. Return `result` as the position of the first element
           greater than or equal to the target.

    Example:
        Input:
            arr = [2, 4, 5, 7, 11, 11, 25]
            target = 11
        
        Process:
            Binary search steps:
                mid = 3 → arr[3] = 7 < 11 → move right
                mid = 5 → arr[5] = 11 ≥ 11 → result = 5, move left
                mid = 4 → arr[4] = 11 ≥ 11 → result = 4, move left
            Final result = 4
        
        Output:
            ✅ The smallest index where arr[index] ≥ 11 is 4

    Time Complexity:
        - O(log N): Binary search over the sorted array.

    Space Complexity:
        - O(1): Constant extra space.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> &arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    int result = arr.size();

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] >= target) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {2, 4, 5, 7, 11, 11, 25};
    int target = 11;

    cout << "The smallest index in the array where all elements are equal or greater than "
         << target << " is " << lowerBound(arr, target) << ".\n";
    
    return 0;
}

