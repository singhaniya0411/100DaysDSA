/*
    Title: Quadruple Sum in an Array.

    Problem Statement:
        Given an array of integers and a target value,
        find all unique quadruples (a, b, c, d) such that:
                a + b + c + d = target

    Example:
        Input:
            arr = [10, 2, 3, 4, 5, 7, 8, 9]
            target = 23
        Output:
            {2, 3, 8, 10}
            {2, 4, 7, 10}
            {2, 5, 7, 9}
            {3, 4, 7, 9}

    Approach:
        1. Sort the array to handle duplicates easily.
        2. Fix the first two elements using two nested loops (i, j).
        3. Use the **two-pointer technique** on the remaining part of the array:
            - k = j + 1 (next index)
            - l = n - 1 (last index)
        4. Calculate the sum = arr[i] + arr[j] + arr[k] + arr[l]
            - If sum == target → store this quadruple.
            - If sum < target → increase k (to increase sum).
            - If sum > target → decrease l (to reduce sum).
        5. Skip duplicates to ensure unique combinations.
        6. Return all possible unique quadruples.

    Dry Run:
        arr = [10, 2, 3, 4, 5, 7, 8], target = 23
        Sorted arr = [2, 3, 4, 5, 7, 8, 10]
        
        i=0 (2), j=1 (3)
            k=2 (4), l=6 (10) → sum=19 < 23 → k++
            k=3 (5), l=6 (10) → sum=20 < 23 → k++
            k=4 (7), l=6 (10) → sum=22 < 23 → k++
            k=5 (8), l=6 (10) → sum=23 ✅ Found {2,3,8,10}
        Next combinations...
        Final Result = { {2,3,8,10}, {2,4,7,10}, {3,4,7,9} (if 9 existed) }

    Time Complexity: O(n³)
    Space Complexity: O(1) (excluding output vector)

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> quadrapleSum(vector<int> &arr, int target) {
    vector<vector<int>> res;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            int k = j + 1, l = n - 1;

            while (k < l) {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];

                if (sum == target) {
                    res.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    while (k < l && arr[k] == arr[k - 1]) k++;
                    while (k < l && arr[l] == arr[l + 1]) l--;
                } 
                else if (sum < target) {
                    k++;
                } 
                else {
                    l--;
                }
            }
        }
    }

    if (res.empty())
        return {{0}};
    else
        return res;
}

int main() {
    vector<int> arr = {10, 2, 3, 4, 5, 7, 8, 9};
    int target = 23;

    cout << "\nArray : ";
    for (int val : arr) cout << val << " ";

    vector<vector<int>> res = quadrapleSum(arr, target);

    if (res[0][0] == 0) {
        cout << "\nNot possible to get target sum as " << target << "\n";
    } 
    else {
        cout << "\nPossible quadruples to get the target sum " << target << " are:\n";
        for (vector<int> x : res) {
            cout << "{ ";
            for (int val : x) cout << val << " ";
            cout << "}\n";
        }
    }

    return 0;
}

