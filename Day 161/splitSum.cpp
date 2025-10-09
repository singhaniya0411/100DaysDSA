/*
    Title: Split Array into Three Equal Sum Parts

    Problem Statement:
        - You are given an integer array 'arr'.
        - The task is to find two indices such that the array can be divided into
          three contiguous parts having equal sum.
        - If such a split is possible, return the two indices where the splits occur.
        - Otherwise, return an empty vector.

    Example:
        Input:
            arr = {1, 2, 3, 0, 3}
        Process:
            Total Sum = 9 → Each part must have sum = 3
            Possible Split: [1,2] | [3,0] | [3]
            Indices of split = [1, 3]
        Output:
            [1, 3]

    Approach:
        1. Compute the total sum of the array.
        2. If total sum is not divisible by 3, no equal split is possible.
        3. Traverse the array and maintain a running sum.
        4. Each time running sum equals (partSum * (count + 1)), store index as split point.
        5. Stop after finding 2 split points (since 3 parts require 2 splits).

    Dry Run:
        arr = {1, 2, 3, 0, 3}
        sum = 9, partSum = 3
        runSum sequence → 1, 3, 6, 6, 9
        At runSum = 3 (i=1) → 1st split
        At runSum = 6 (i=3) → 2nd split
        ✅ Output = [1, 3]

    Time Complexity:
        - O(n), single traversal through the array.

    Space Complexity:
        - O(1), uses only constant extra space.

    Applications:
        - Useful in partition-based optimization problems.
        - Data segmentation in load balancing systems.
        - Splitting financial or statistical datasets into equal groups.

    Author: Vishal Singhaniya
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> findSplit(vector<int>& arr) {
    vector<int> ans;
    int n = arr.size();
    if(n < 3) {
        return ans;
    }
    
    long long totalSum = accumulate(arr.begin(), arr.end(), 0LL);
    if(totalSum % 3 != 0) {
        return ans;
    }
    
    long long targetSum = totalSum / 3;
    long long currentSum = 0;
    
    for(int i = 0; i < n - 1; i++) { // Stop at n-1 to ensure 3 non-empty parts
        currentSum += arr[i];
        
        if(currentSum == targetSum) {
            ans.push_back(i);
            currentSum = 0; // Reset for next part
            
            if(ans.size() == 2) {
                // Verify that the remaining part also sums to targetSum
                long long remainingSum = 0;
                for(int j = i + 1; j < n; j++) {
                    remainingSum += arr[j];
                }
                if(remainingSum == targetSum) {
                    return ans;
                } else {
                    ans.pop_back();
                    continue;
                }
            }
        }
    }
    
    return {};
}

int main() {
    vector<int> arr = {1,2,3,4,2,4,4,5,4,1};
    vector<int> res = findSplit(arr);
    
    if(res.size() == 2) {
        int i = res[0];  // End of first part
        int j = res[1];  // End of second part
        
        cout << "First part: [";
        for(int k = 0; k <= i; k++) {
            cout << arr[k] << (k < i ? " " : "");
        }
        cout << "]\n";
        
        cout << "Second part: [";
        for(int k = i + 1; k <= j; k++) {
            cout << arr[k] << (k < j ? " " : "");
        }
        cout << "]\n";
        
        cout << "Third part: [";
        for(int k = j + 1; k < arr.size(); k++) {
            cout << arr[k] << (k < arr.size() - 1 ? " " : "");
        }
        cout << "]\n";
    } else {
        cout << "No valid split found\n";
    }
    
    return 0;

}







