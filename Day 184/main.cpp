/*
    Title: Closest Triplet Sum to Target.

    Problem Statement:
        - Given an array `arr` and an integer `target`,
          find the sum of three integers in the array such that
          the sum is closest to the given target.
        - If multiple sums are equally close, return the maximum among them.

    Approach:
        1. Sort the array to use the two-pointer technique efficiently.
        2. Fix one element (arr[i]) and use two pointers:
            - `l` (left) starting from i+1
            - `r` (right) starting from n-1
        3. Compute current sum = arr[i] + arr[l] + arr[r].
        4. If the absolute difference |currSum - target| is smaller than the minimum difference so far,
           update `minDiff` and `res`.
        5. If the difference is equal but `currSum` is larger, update `res` to the maximum value.
        6. Move the pointers:
            - If currSum < target → increment l
            - Else → decrement r
        7. Continue until all triplets are checked.

    Example:
        Input:
            arr = [1, -5, 12, -3, 8]
            target = 14

        After sorting:
            arr = [-5, -3, 1, 8, 12]

        Checking triplets:
            (-5, 8, 12) → sum = 15 → |15 - 14| = 1 → Closest so far.

        Output:
            The closest sum to target 14 is 15

    Time Complexity:
        - O(n²): Outer loop O(n), inner two-pointer traversal O(n)
        - Sorting adds O(n log n)

    Space Complexity:
        - O(1): Only constant extra space used.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int closestSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    
    int n = arr.size();
    int minDiff = INT_MAX;
    int res = 0;
    
    for (int i = 0; i < n - 2; i++) {
        int l = i + 1;
        int r = n - 1;
        
        while (l < r) {
            int currSum = arr[i] + arr[l] + arr[r];
            int diff = abs(currSum - target);
            
            if (diff < minDiff) {
                minDiff = diff;
                res = currSum;
            } 
            else if (diff == minDiff) {
                res = max(res, currSum);
            }
            
            if (currSum < target)
                l++;
            else
                r--;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, -5, 12, -3, 8};
    int target = 14;
    
    int sum = closestSum(arr, target);
    
    cout << "The closest sum to target " << target << " is " << sum << endl;
    return 0;
}











