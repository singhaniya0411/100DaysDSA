/*
    Title: Longest Subarray with Equal Number of 0s and 1s (Optimized Approach)

    Problem Statement:
        - Given a binary array (containing only 0s and 1s),
          find the length of the longest subarray with equal number of 0s and 1s.

    Optimized Approach:
        - Convert 0s to -1s.
        - Use prefix sum to track cumulative values.
        - If a prefix sum repeats or becomes 0, the subarray in between has equal 0s and 1s.
        - Use a hashmap to store the first occurrence of each prefix sum.

    Time Complexity:
        - **O(n)** — Single traversal of array.

    Space Complexity:
        - **O(n)** — Hashmap to store prefix sums.

    Assumption:
        - The array contains only 0s and 1s.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to find the longest subarray with equal 0s and 1s
int maxLen(vector<int> arr) {
    unordered_map<int, int> mp;
    int preSum = 0;
    int res = 0;

    for (int i = 0; i < arr.size(); i++) {
        preSum += (arr[i] == 1) ? 1 : -1;

        if (preSum == 0) {
            res = i + 1;
        } else if (mp.count(preSum)) {
            res = max(res, i - mp[preSum]);
        } else {
            mp[preSum] = i;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {1, 0, 1, 1, 1, 0, 0};

    int longestLength = maxLen(arr);

    cout << "Length of longest subarray with equal 0s and 1s is: " << longestLength << endl;

    return 0;
}
