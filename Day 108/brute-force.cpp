/*
    Title: Maximum of All Subarrays of Size K.

    Problem Statement:
        - Given an array of integers and an integer K, find the maximum element 
          for every contiguous subarray of size K.

    Example:
        Input:  arr = [1, 3, 1, 2, 0, 5], K = 3
        Output: [3, 3, 2, 5]
        Explanation:
            - Subarrays of size 3 are [1,3,1], [3,1,2], [1,2,0], [2,0,5].
            - Maximum elements are 3, 3, 2, 5 respectively.

    Approach:
        - Iterate over each window of size K in the array.
        - For each window, find the maximum element by checking all elements in the window.

    Time Complexity:
        - O(n * k), where n is the size of the array.
          (For each of the n-k+1 windows, we scan k elements.)

    Space Complexity:
        - O(1), excluding the space used for the result vector.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> maxOfSubarrays(vector<int>& arr, int k) {
    vector<int> res;
    
    for (int i = 0; i <= arr.size() - k; i++) {
        int maxElem = arr[i];
        for (int j = 1; j < k; j++) {
            maxElem = max(maxElem, arr[i + j]);
        }
        res.push_back(maxElem);
    }
    return res;
}

int main() {
    vector<int> arr = {1, 3, 1, 2, 0, 5};
    int k = 3;

    vector<int> result = maxOfSubarrays(arr, k);

    cout << "Maximum of all subarrays of size " << k << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
