/*
    Title: Combination Sum II — Unique Combinations

    Problem Statement:
        - Given a collection of candidate numbers `arr` (may contain duplicates) and a target number `target`,
          find all unique combinations in `arr` where the candidate numbers sum to `target`.
        - Each element in `arr` may be used at most once in a combination.
        - The solution set must not contain duplicate combinations (combinations differing only by order are considered the same).

    Example:
        Input:
            arr    = [10,1,2,7,6,1,5]
            target = 8
        Output (order of combinations may vary):
            [1,1,6]
            [1,2,5]
            [1,7]
            [2,6]

    Approach:
        - Sort the array first so duplicates are adjacent and we can skip them easily.
        - Use backtracking to build combinations:
            • At recursion index `idx`, iterate i from `idx` to end:
                - If `i > idx` and `arr[i] == arr[i-1]`, skip `arr[i]` to avoid duplicate combinations.
                - Choose `arr[i]`, recurse with updated remaining sum `sum - arr[i]` and next index `i+1` (since each element can be used once).
                - Backtrack by popping the last chosen element.
        - If remaining sum becomes 0, the current combination is valid — add it to results.

    Dry Run (brief):
        arr = [1,1,2,5,6,7,10], target = 8 (sorted)
        - idx=0: pick 1 (i=0) → recurse target=7
            - idx=1: skip duplicate 1 (i=1) if already handled by previous branch, pick 2 → recurse target=5 ...
        - Continue until all valid unique combinations found.

    Time Complexity:
        - Exponential in worst case (backtracking): O(2^n) roughly, depends on pruning and duplicates.

    Space Complexity:
        - O(target) recursion depth in worst case (or O(n) for recursion stack) + space for storing results.

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

void makeCombination(vector<int>& arr, int sum, vector<int>& curr, vector<vector<int>>& res, int idx) {
    if (sum == 0) {
        res.push_back(curr);
        return;
    }
    if (sum < 0 || idx >= (int)arr.size()) {
        return;
    }

    for (int i = idx; i < (int)arr.size(); ++i) {
        // skip duplicates at the same recursion level
        if (i > idx && arr[i] == arr[i - 1]) continue;

        // if current element is greater than remaining sum, further elements (sorted) will also be too big
        if (arr[i] > sum) break;

        curr.push_back(arr[i]);
        makeCombination(arr, sum - arr[i], curr, res, i + 1); // i+1 since each element can be used at most once
        curr.pop_back();
    }
}

vector<vector<int>> uniqueCombinations(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    vector<int> curr;
    vector<vector<int>> res;
    makeCombination(arr, target, curr, res, 0);
    return res;
}

int main() {
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    vector<vector<int>> res = uniqueCombinations(arr, target);

    if (res.empty()) {
        cout << "No unique combination possible\n";
    } else {
        cout << "Unique combinations that sum to " << target << ":\n";
        for (auto &comb : res) {
            cout << "[ ";
            for (int x : comb) cout << x << " ";
            cout << "]\n";
        }
    }
    return 0;
}












