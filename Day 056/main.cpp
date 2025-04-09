/*
    Title: Find Subarray with Given Sum (Sliding Window)

    Problem Statement:
        - Given an array of positive integers and a target sum,
          return the start and end indices of a subarray that sums exactly to the target.
        - Use 1-based indexing for the output indices.
        
    Approach:
        - Use the sliding window technique to maintain a running sum.
        - If the sum exceeds the target, shrink the window from the left.
        - If the sum matches the target, return the start and end indices.

    Time Complexity:
        - **O(n)** — Each element is added and removed at most once.

    Space Complexity:
        - **O(1)** extra space (just a few variables)

    Assumption:
        - Only positive integers are in the array.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Find subarray with a given sum (sliding window technique)
vector<int> subArraySum(vector<int> arr, int target) {
    int n = arr.size();
    vector<int> res;
    int s = 0, curr = 0;

    for (int e = 0; e < n; e++) {
        curr += arr[e];
        while (curr > target && s <= e) {
            curr -= arr[s++];
        }
        if (curr == target) {
            res.push_back(s + 1); // 1-based indexing
            res.push_back(e + 1);
            return res;
        }
    }

    return {-1, -1}; // No subarray found
}

int main() {
    vector<int> arr = {1, 4, 4, 4, 5, 3, 3, 8, 9, 11};
    int target = 14;

    vector<int> result = subArraySum(arr, target);
    if (result[0] != -1) {
        cout << "Subarray with sum " << target << " found from index ";
        cout << result[0] << " to " << result[1] << endl;
    } else {
        cout << "No subarray with sum " << target << " found." << endl;
    }

    return 0;
}
