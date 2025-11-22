/*
    Title: Longest Subarray Where Elements Greater Than k Are in Majority

    Problem Statement:
        - You are given an integer array `arr` and an integer `k`.
        - Consider a subarray valid if the number of elements strictly greater than `k`
          is MORE than the number of elements less than or equal to `k` in that subarray.
        - Your task is to find the LENGTH of the longest such subarray.

    Example:
        Input:
            arr = [1, 2, 3, 4, 5, 3, 2]
            k   = 3

        Classification:
            <=k : [1, 2, 3, -, -, 3, 2]
            > k : [-, -, -, 4, 5, -, -]

        One valid subarray:
            [3, 4, 5, 3] → elements > k = {4,5} (2 elements)
                           elements <= k = {3,3} (2 elements) → NOT majority

            [4, 5, 3, 2] → >k = {4,5} (2), <=k = {3,2} (2) → NOT majority

            [4, 5] → >k = 2, <=k = 0 → valid, length = 2

        Output:
            2

    Core Idea:
        - Convert the array into a "balance sum" array:
            • For each element:
                - If arr[i] > k → treat as +1
                - If arr[i] <= k → treat as -1
        - For any subarray, if the sum > 0, it means:
              count(>k) > count(<=k)  → valid subarray.
        - We need the longest subarray with sum > 0.

    Approach (Prefix Sum + Hash Map):
        1. Maintain a running sum:
                sum += +1 (if arr[i] > k)
                sum += -1 (if arr[i] <= k)
        2. If sum > 0 at index i:
                → subarray [0..i] is valid → update answer as i+1.
        3. Otherwise:
                - We want an earlier prefix with sum = (sum - 1),
                  because:
                    (current_sum - previous_sum) > 0
                    → previous_sum < current_sum
                    → previous_sum = sum - 1 is the smallest needed to ensure > 0 over the range.
                - If we have seen (sum - 1) before at index j:
                      subarray (j+1 .. i) is valid,
                      and its length = i - j.
        4. Use an unordered_map to store the **first occurrence** of each prefix sum.
        5. Return the maximum length found.

    Dry Run:
        arr = [1, 2, 3, 4, 5, 3, 2], k = 3

        Transform:
            1 (<=3) → -1
            2 (<=3) → -1
            3 (<=3) → -1
            4 (>3)  → +1
            5 (>3)  → +1
            3 (<=3) → -1
            2 (<=3) → -1

        Running sum and logic:
            i=0: sum=-1 → store sum=-1 at i=0
            i=1: sum=-2 → store sum=-2 at i=1
            i=2: sum=-3 → store sum=-3 at i=2
            i=3: sum=-2 → already seen, check sum-1=-3 at i=2 → length=3-2=1
            i=4: sum=-1 → check sum-1=-2 at i=1 → length=4-1=3  (longest so far)
            i=5: sum=-2 → check sum-1=-3 at i=2 → length=5-2=3
            i=6: sum=-3 → no better than previous

        Longest valid subarray length = 3.

    Time Complexity:
        - O(n), single pass through the array.

    Space Complexity:
        - O(n), for the hash map storing first occurrence of each prefix sum.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0, ans = 0;
    unordered_map<int,int> mp;

    for (int i = 0; i < n; i++) {
        if (arr[i] <= k) {
            sum--;
        } else {
            sum++;
        }

        if (sum > 0) {
            ans = i + 1;
        } else {
            if (mp.find(sum - 1) != mp.end()) {
                ans = max(ans, i - mp[sum - 1]);
            }
        }

        if (mp.find(sum) == mp.end()) {
            mp[sum] = i; 
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 3, 2};
    int k = 3;

    int res = longestSubarray(arr, k);

    cout << "Length of longest subarray in which elements greater than " 
         << k << " are in majority: " << res << "\n";

    return 0;
}
