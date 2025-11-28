/*
    Title: Target Sum Combinations (Unbounded Combination Sum using Backtracking)

    Problem Statement:
        - You are given an array of positive integers `arr` and a target sum `target`.
        - Each element in `arr` can be used **any number of times** (including zero).
        - The task is to find all unique combinations of elements from `arr` whose sum is exactly equal to `target`.
        - The order of elements inside a combination does not matter, and combinations are printed based on the recursion order.

    Example:
        Input:
            arr    = [1, 2, 3, 4]
            target = 8

        Possible valid combinations (order may vary):
            [1, 1, 1, 1, 1, 1, 1, 1]
            [1, 1, 1, 1, 1, 1, 2]
            [1, 1, 2, 4]
            [2, 2, 2, 2]
            [2, 2, 4]
            [4, 4]
            [1, 3, 4]
            [2, 3, 3]
            ...

        Output Format:
            Possible Combination :
            [ 1 1 2 4 ]
            [ 2 2 4 ]
            [ 4 4 ]
            ... (etc, depending on recursion order)

    Approach (Recursion + Backtracking):
        1. Use a helper function `makeCombination(arr, sum, curr, res, i)` where:
            - `sum`  → remaining sum to be formed.
            - `curr` → current combination being built.
            - `res`  → list of all valid combinations.
            - `i`    → current index in `arr`.

        2. Base Cases:
            - If sum == 0:
                • Current combination `curr` is valid → push it into `res` and return.
            - If sum < 0 or i >= arr.size():
                • No valid combination from this path → backtrack (return).

        3. Recursive Choices at index `i`:
            - **Include** `arr[i]`:
                • Push `arr[i]` into `curr`.
                • Recurse with updated sum → `sum - arr[i]` and same index `i` (because elements can be reused).
            - **Exclude** `arr[i]`:
                • Pop `arr[i]` from `curr` (backtracking).
                • Move to the next index → `i + 1`.

        4. The main function `targetSumCombination(arr, target)`:
            - Initializes an empty `curr` and `res`.
            - Calls the recursive helper starting from index 0.
            - Returns `res` containing all valid combinations.

    Dry Run (Brief):
        arr = [1, 2, 3, 4], target = 4

        - Start with i = 0, sum = 4, curr = []
        - Include 1 → sum = 3, curr = [1]
            - Include 1 → sum = 2, curr = [1, 1]
                - Include 1 → sum = 1, curr = [1, 1, 1]
                    - Include 1 → sum = 0 → store [1,1,1,1]
                - Exclude 1 → move to 2 → try 2, 3, 4...
        - Exclude 1 → move to 2, repeat...
        - Eventually get combinations like [2,2], [1,3], [4].

    Time Complexity:
        - Exponential in nature: O(2^n) in the worst case,
          because we explore include/exclude paths and reuse elements.

    Space Complexity:
        - O(target) for recursion depth in worst case (if we keep adding 1s).
        - Extra space for `curr` and `res` to store all valid combinations.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

void makeCombination(vector<int> &arr, int sum, vector<int>& curr,
                     vector<vector<int>>& res, int i) {
    
    if (sum == 0) {
        res.push_back(curr);
        return;
    }
    
    if (sum < 0 || i >= (int)arr.size()) {
        return;
    }
    
    // Include current element (can be reused)
    curr.push_back(arr[i]);
    makeCombination(arr, sum - arr[i], curr, res, i);
    
    // Exclude current element and move to next
    curr.pop_back();
    makeCombination(arr, sum, curr, res, i + 1);
}

vector<vector<int>> targetSumCombination(vector<int>& arr, int target) {
    vector<int> curr;
    vector<vector<int>> res;
    makeCombination(arr, target, curr, res, 0);
    return res;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    int target = 8;
    
    vector<vector<int>> res = targetSumCombination(arr, target);
    
    if (res.size() == 0) {
        cout << "No combination possible\n";
    } else {
        cout << "Possible Combinations:\n";
        for (auto curr : res) {
            cout << "[ ";
            for (auto elem : curr) {
                cout << elem << " ";
            }
            cout << "]\n";
        }
    }
    return 0;
}
