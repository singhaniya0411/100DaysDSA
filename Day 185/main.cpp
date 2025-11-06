/*
    Title: Count Subarrays with At Most K Distinct Integers.

    Problem Statement:
        - Given an integer array `arr` and an integer `k`,
          find the number of subarrays that contain at most K distinct integers.

    Approach (Sliding Window + Frequency Map):
        1. Use a sliding window defined by pointers `left` and `right`.
        2. Maintain a frequency map (unordered_map) of elements inside the window.
        3. Expand the `right` pointer to include new elements.
            - Decrease `k` when a new distinct element is added (freq == 1).
        4. If `k` becomes negative, shrink the window from the left
           until we again have at most K distinct elements.
        5. For every valid window (where `k >= 0`),
           all subarrays ending at `right` contribute `(right - left + 1)` to the result.

    Example:
        Input:
            arr = [1, 2, 1, 2, 3], k = 2
        
        Output:
            Total subarrays = 12

    Time Complexity:
        - O(n): Each element is visited at most twice (once by right, once by left)

    Space Complexity:
        - O(n): For the frequency map

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

int countAtMostK(vector<int> &arr, int k) {
    int n = arr.size();
    int res = 0;
    
    int left = 0, right = 0;
    unordered_map<int, int> freq;
    
    while (right < n) {
        freq[arr[right]]++;
        
        // A new distinct element reduces available distinct count
        if (freq[arr[right]] == 1)
            k--;
        
        // If more than k distinct, shrink window
        while (k < 0) {
            freq[arr[left]]--;
            if (freq[arr[left]] == 0)
                k++;
            left++;
        }
        
        // Add count of all valid subarrays ending at right
        res += (right - left + 1);
        right++;
    }
    
    return res;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;
    
    cout << "Count of subarrays with at most " << k 
         << " distinct elements: " << countAtMostK(arr, k) << endl;
    return 0;
}








