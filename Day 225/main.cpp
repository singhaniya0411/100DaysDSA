/*
    Title: Minimum K Consecutive Bit Flips.

    Problem Statement:
        - You are given a binary array `arr` consisting of 0s and 1s.
        - You are allowed to flip exactly `k` consecutive bits in one operation.
        - A flip means changing 0 → 1 and 1 → 0.
        - Your task is to determine the **minimum number of flips** required
          to make all elements of the array equal to 1.
        - If it is not possible, return `-1`.

    Example:
        Input:
            arr = [0, 1, 0]
            k = 1

        Output:
            2

        Explanation:
            Flip index 0 → [1,1,0]
            Flip index 2 → [1,1,1]

    Approach:
        - Use a **sliding window + greedy approach**.
        - Maintain a variable `flag` to track how many flips affect the current index.
        - Use a queue to track when a flip window expires.
        - If current bit (after considering flips) is `0`, we must flip starting here.
        - If flipping goes out of bounds, return `-1`.

    Steps:
        1. Traverse the array from left to right.
        2. Remove the effect of flips that are out of range.
        3. Apply flip when encountering a `0`.
        4. Count total flips.

    Time Complexity:
        - O(n), each element is processed once.

    Space Complexity:
        - O(k), for the sliding window queue.

    Applications:
        - Bit manipulation problems
        - Greedy optimization problems
        - Window-based transformations

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

int kBitFlips(vector<int>& arr, int k) {
    int n = arr.size();
    int res = 0;
    int flag = 0;
    queue<int> q;

    for(int i = 0; i < n; i++){
        if(i >= k){
            flag ^= q.front();
            q.pop();
        }

        if(flag == 1){
            arr[i] ^= 1;
        }

        if(arr[i] == 0){
            if(i + k > n){
                return -1;
            }
            res++;
            flag ^= 1;
            q.push(1);
        } else {
            q.push(0);
        }
    }
    return res;
}

int main(){
    vector<int> arr = {0, 1, 0};
    int k = 1;

    int result = kBitFlips(arr, k);
    cout << "Minimum number of flips required: " << result << endl;

    return 0;
}

