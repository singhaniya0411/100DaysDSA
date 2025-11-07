/*
    Title: Minimum Removals to Reduce Array Sum to K (From Ends)

    Problem Statement:
        Given an array `arr` and an integer `k`, 
        find the minimum number of elements to remove from either end of the array
        so that the sum of the remaining elements equals `k`.
        If it’s not possible, return -1.

    Approach (Sliding Window):
        1. Calculate totalSum of the array.
        2. Let target = totalSum - k.  
           We need to find the longest subarray with sum = target.
        3. Use two pointers (`left`, `right`) to maintain a sliding window.
        4. Expand `right`, and adjust `left` whenever the sum exceeds `target`.
        5. Whenever `currSum == target`, update `maxLen`.
        6. Finally, if `maxLen` exists, answer = n - maxLen, else -1.

    Time Complexity: O(n) – Each element is visited at most twice (left and right pointer)

    Space Complexity: O(1)

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

int minRemoval(vector<int> &arr, int k) {
    int total = accumulate(arr.begin(), arr.end(), 0);
    int n = arr.size();

    int target = total - k;
    if (target == 0) return n; // need to keep all elements
    
    int left = 0, currSum = 0, maxLen = -1;
    
    for (int right = 0; right < n; right++) {
        currSum += arr[right];

        while (left < right && currSum > target) {
            currSum -= arr[left];
            left++;
        }

        if (currSum == target)
            maxLen = max(maxLen, right - left + 1);
    }

    return (maxLen == -1) ? -1 : n - maxLen;
}

int main() {
    vector<int> arr = {3, 2, 4, 1, 6, 2, 5};
    int k = 18;

    int res = minRemoval(arr, k);

    if (res == -1)
        cout << "Not possible to reduce array sum to " << k << "." << endl;
    else
        cout << "Minimum number of removals from array ends to reach sum "
             << k << " is: " << res << endl;

    return 0;
}
