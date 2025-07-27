/*
    Title: Maximum of All Subarrays of Size K (Optimized O(n) Solution)

    Problem Statement:
        - Given an array of integers and an integer K, find the maximum element 
          for every contiguous subarray of size K.

    Example:
        Input:  arr = [1, 3, 1, 2, 0, 5], K = 3
        Output: [3, 3, 2, 5]

    Approach:
        - Use a deque to store indices of array elements.
        - The deque will maintain elements in decreasing order of values.
        - For each window:
            - Remove indices that are out of this window.
            - Remove elements smaller than the current element from the deque's back.
            - The element at the front of the deque is the largest for the current window.

    Time Complexity:
        - O(n), where n is the size of the array.

    Space Complexity:
        - O(k), for storing indices in the deque.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxOfSubarray(vector<int>& arr, int k) {
    vector<int> res;
    deque<int> dq;

    for (int i = 0; i < arr.size(); i++) {
        // Remove elements out of current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        // Remove smaller elements from the back
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // Add current element index
        dq.push_back(i);

        // The front of the deque is the largest for the current window
        if (i >= k - 1) {
            res.push_back(arr[dq.front()]);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {1, 3, 1, 2, 0, 5};
    int k = 3;

    vector<int> result = maxOfSubarray(arr, k);

    cout << "Maximum of all subarrays of size " << k << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
