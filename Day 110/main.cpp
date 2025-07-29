/*
    Title: Longest Increasing Subsequence (LIS) - Length

    Problem Statement:
        - Given an array of integers `arr` of size `n`, find the length of the 
          longest increasing subsequence (LIS).

    Example:
        Input:  arr = [10, 9, 2, 5, 3, 7, 101, 18]
        Output: 4  (The LIS is [2, 3, 7, 101])

    Approach:
        - Use a dynamic array `ans` that stores the smallest possible tail of all 
          increasing subsequences of a given length.
        - For each element in `arr`:
            - Use binary search (lower_bound) to find its position in `ans`.
            - Replace the element if found or append it otherwise.
        - The length of `ans` will be the LIS length.

    Time Complexity:
        - O(n log n), due to binary search for each element.

    Space Complexity:
        - O(n), for storing the subsequence tails.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestSubsequence(int n, int arr[]) {
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int ind = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
        if (ind == ans.size()) {
            ans.push_back(arr[i]);
        } else {
            ans[ind] = arr[i];
        }
    }
    return ans.size();
}

// Main function to test
int main() {
    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = longestSubsequence(n, arr);
    cout << "Length of LIS: " << result << endl;

    return 0;
}
