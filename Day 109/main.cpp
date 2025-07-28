/*
    Title: Longest Subarray with Absolute Difference ≤ X

    Problem Statement:
        - Given an array of integers `arr` and an integer `x`, find the longest subarray 
          such that the difference between the maximum and minimum element in the subarray 
          is at most `x`.
        - Return the elements of the longest subarray.

    Example:
        Input:  arr = [8, 2, 4, 7], x = 4
        Output: [2, 4]

    Approach:
        - Use two deques:
            - `maxDq` to maintain indices of elements in decreasing order (track max).
            - `minDq` to maintain indices of elements in increasing order (track min).
        - Expand the window by moving `end`.
        - If the difference (arr[maxDq.front()] - arr[minDq.front()]) > x, shrink the window by moving `start`.
        - Keep track of the best (longest) window found so far.

    Time Complexity:
        - O(n), as each element is pushed and popped from deque at most once.

    Space Complexity:
        - O(n), for storing the deques and result.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> longestSubarray(vector<int>& arr, int x) {
    deque<int> maxDq, minDq;
    int start = 0, end = 0;
    int ansStart = 0, ansEnd = 0;

    while (end < arr.size()) {
        // Maintain increasing order deque for minimum
        while (!minDq.empty() && arr[minDq.back()] > arr[end]) {
            minDq.pop_back();
        }

        // Maintain decreasing order deque for maximum
        while (!maxDq.empty() && arr[maxDq.back()] < arr[end]) {
            maxDq.pop_back();
        }

        minDq.push_back(end);
        maxDq.push_back(end);

        // Shrink window if condition violated
        while (!maxDq.empty() && !minDq.empty() &&
               arr[maxDq.front()] - arr[minDq.front()] > x) {
            if (start == maxDq.front()) maxDq.pop_front();
            if (start == minDq.front()) minDq.pop_front();
            start++;
        }

        // Update longest subarray
        if (end - start > ansEnd - ansStart) {
            ansStart = start;
            ansEnd = end;
        }

        end++;
    }

    // Prepare the answer subarray
    vector<int> ans;
    for (int i = ansStart; i <= ansEnd; i++) {
        ans.push_back(arr[i]);
    }
    return ans;
}

// Main function to test
int main() {
    vector<int> arr = {8, 2, 4, 7};
    int x = 4;

    vector<int> result = longestSubarray(arr, x);
    cout << "Longest subarray with max-min <= " << x << ": ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}
