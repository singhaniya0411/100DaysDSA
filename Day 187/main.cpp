/*
    Title: Pair Sum in a Rotated Sorted Array

    Problem Statement:
        Given a sorted and rotated array, and an integer `target`, determine whether there exists a pair (arr[i], arr[j]) 
        such that: arr[i] + arr[j] == target

    Example:
        arr = [12, 15, 2, 5, 7, 9, 11]
        target = 23
        Output: True → (12 + 11 = 23)

    Approach (Two Pointer on Rotated Array):
        1. First find the **pivot** — the index `i` where arr[i] > arr[i+1].
           - This separates the largest and smallest elements.
           - Example: in [12, 15, 2, 5, 7, 9, 11], pivot = 1 (15 > 2)
        2. Set two pointers:
           - `r = pivot` → largest element
           - `l = (pivot + 1) % n` → smallest element
        3. Use the two-pointer approach in circular fashion:
           - If arr[l] + arr[r] == target → found
           - If sum < target → move l forward (l = (l + 1) % n)
           - If sum > target → move r backward (r = (r - 1 + n) % n)
           - Stop when l == r.

    Dry Run:
        arr = [12, 15, 2, 5, 7, 9, 11], target = 23
        Pivot = 1 (15 > 2)
        l = 2 (arr[l] = 2), r = 1 (arr[r] = 15)
        Iterations:
            (2,15) → sum=17 < 23 → move l to 3
            (5,15) → sum=20 < 23 → move l to 4
            (7,15) → sum=22 < 23 → move l to 5
            (9,15) → sum=24 > 23 → move r to 0
            (9,12) → sum=21 < 23 → move l to 6
            (11,12) → sum=23 ✅ FOUND

    Time Complexity: O(n)
    Space Complexity: O(1)

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

bool pairInSortedArray(vector<int>& arr, int target) {
    int n = arr.size();
    int i;

    // Step 1: Find pivot where rotation happened
    for (i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) break;
    }

    int r = i;           // index of largest element
    int l = (i + 1) % n; // index of smallest element

    // Step 2: Use circular two-pointer technique
    while (l != r) {
        int sum = arr[l] + arr[r];

        if (sum == target) return true;

        if (sum > target)
            r = (r - 1 + n) % n;
        else
            l = (l + 1) % n;
    }

    return false;
}

int main() {
    vector<int> arr = {12, 15, 2, 5, 7, 9, 11};
    int target = 23;

    cout << "\nArray : ";
    for (int num : arr) cout << num << " ";

    cout << "\nTarget : " << target;

    if (pairInSortedArray(arr, target))
        cout << "\nPair sum with target " << target << " can be achieved from this array.\n";
    else
        cout << "\nTarget sum is not possible.\n";

    return 0;
}





