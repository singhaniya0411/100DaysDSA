/*
    Title: Maximum Score from Jumping with K Distance

    Problem Statement:
        - You are given an integer array `arr` where each element represents a score.
        - You start at index 0 and want to reach the last index.
        - From index `i`, you can jump to any index `j` such that:
              i < j ≤ i + k
        - Each time you land on an index, you collect its value.
        - Your task is to find the **maximum total score** obtainable when reaching the end.

    Example:
        Input:
            arr = [1, -1, -2, 4, -7, 3]
            k = 2

        Output:
            7

        Explanation:
            Path taken:
            1 → -1 → 4 → 3
            Total score = 1 + (-1) + 4 + 3 = 7

    Approach:
        - Use **Dynamic Programming + Deque (Monotonic Queue)**.
        - Let `dp[i]` be the maximum score obtainable starting from index `i`.
        - Transition:
            dp[i] = arr[i] + max(dp[j]) for all j ∈ [i+1, i+k]
        - To optimize this:
            - Maintain a deque that stores indices in decreasing order of `dp` values.
            - The front of the deque always holds the best next jump.
        - Traverse from right to left.

    Steps:
        1. Initialize dp[n-1] = arr[n-1].
        2. Maintain a deque to track max dp in range.
        3. Remove indices that are out of range (i + k).
        4. Update dp[i] using the front of the deque.
        5. Maintain decreasing order in deque.

    Time Complexity:
        - O(n), each element is pushed and popped once.

    Space Complexity:
        - O(n), for dp array and deque.

    Applications:
        - Game score optimization
        - Dynamic programming with sliding window optimization
        - Jump-based path optimization problems

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

int getScore(vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> dp(n, INT_MIN);

    dp[n - 1] = arr[n - 1];
    deque<int> dq;
    dq.push_back(n - 1);

    for (int i = n - 2; i >= 0; i--) {
        while (!dq.empty() && dq.front() > i + k) {
            dq.pop_front();
        }

        dp[i] = arr[i] + dp[dq.front()];

        while (!dq.empty() && dp[i] >= dp[dq.back()]) {
            dq.pop_back();
        }

        dq.push_back(i);
    }

    return dp[0];
}

int main() {
    vector<int> arr = {1, -1, -2, 4, -7, 3};
    int k = 2;

    cout << "Maximum score obtainable: " << getScore(arr, k) << endl;
    return 0;
}


