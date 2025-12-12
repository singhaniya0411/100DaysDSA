/*
    Title: Top K Frequent Elements

    Problem Statement:
        - Given an integer array `arr` and an integer `k`, return the `k` most frequent elements.
        - If multiple elements have the same frequency, return the larger elements first (tie-breaker).

    Example:
        Input:  arr = [1,1,1,2,2,3,3,4], k = 3
        Frequencies: 1->3, 2->2, 3->2, 4->1
        Output: [1, 3, 2]   (3 and 2 have same freq; 3 > 2 so 3 appears before 2)

    Approach:
        1. Count frequencies using an unordered_map<int,int>.
        2. Use bucket-sort by frequency:
            - Create vector<vector<int>> buckets where index = frequency.
            - Place each number in bucket[freq[num]].
        3. Iterate buckets from high frequency to low:
            - Sort each bucket in descending order (to satisfy tie-breaker: larger number first).
            - Append elements to result until we have k elements.
        4. Return the result vector of size k (or fewer if k > unique elements).

    Time Complexity:
        - O(n + U log U) where n = arr.size(), U = number of unique elements.
          (Counting is O(n); sorting elements inside buckets in total costs up to O(U log U).)

    Space Complexity:
        - O(n) for frequency map + buckets.

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> topKFreq(vector<int> &arr, int k) {
    unordered_map<int, int> freq;
    for (int num : arr) freq[num]++;

    int maxFreq = 0;
    for (auto &p : freq) maxFreq = max(maxFreq, p.second);

    vector<vector<int>> buckets(maxFreq + 1);
    for (auto &p : freq) buckets[p.second].push_back(p.first);

    vector<int> res;
    res.reserve(k);

    for (int f = maxFreq; f >= 1 && (int)res.size() < k; --f) {
        if (buckets[f].empty()) continue;
        // tie-breaker: larger elements first
        sort(buckets[f].begin(), buckets[f].end(), greater<int>());
        for (int num : buckets[f]) {
            res.push_back(num);
            if ((int)res.size() == k) break;
        }
    }

    return res;
}

int main() {
    vector<int> arr = {1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,5};
    int k = 4;

    vector<int> ans = topKFreq(arr, k);

    cout << "Top " << k << " frequent elements: ";
    for (int x : ans) cout << x << " ";
    cout << "\n";

    return 0;
}
