/*
    Title: Longest Subarray with Equal Number of 0s and 1s (Brute Force Approach)

    Problem Statement:
        - Given a binary array (containing only 0s and 1s),
          find the length of the longest subarray with equal number of 0s and 1s.

    Approach:
        - Replace 0 with -1.
        - For every possible subarray, calculate the sum.
        - If the sum is 0, it means the number of 1s and 0s are equal.
        - Track and update the maximum length.

    Time Complexity:
        - **O(n²)** — Two nested loops.

    Space Complexity:
        - **O(1)** — No extra space used.

    Assumption:
        - The array contains only 0s and 1s.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the longest subarray with equal 0s and 1s
int maxLen(vector<int> arr) {
    int res = 0;

    for (int i = 0; i < arr.size(); i++) {
        int sum = 0;
        for (int j = i; j < arr.size(); j++) {
            sum += (arr[j] == 1) ? 1 : -1;

            if (sum == 0) {
                res = max(res, j - i + 1);
            }
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
