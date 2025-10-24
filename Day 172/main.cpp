/*
    Title: Minimum Increments to Make Array Elements Unique

    Problem Statement:
        - Given an integer array, make all elements unique by performing the minimum number of increment operations.
        - In one operation, you can increment any element by 1.
        - Find the minimum total increments required and the final modified array.

    Approach:
        1. Sort the array in ascending order.
        2. Traverse the array from the second element:
            - If the current element is less than or equal to the previous one, 
              increment it to make it one greater than the previous element.
            - Count the total increments made.
        3. Return the total count and print the updated array.

    Example:
        Input:
            arr = [1, 1, 2, 3, 6, 2]
        
        Process:
            Sorted: [1, 1, 2, 2, 3, 6]
            Steps:
                - arr[1] (1 ≤ 1) → make 2 (+1)
                - arr[2] (2 ≤ 2) → make 3 (+1)
                - arr[3] (2 ≤ 3) → make 4 (+2)
                - arr[4] (3 ≤ 4) → make 5 (+2)
                - arr[5] = 6 (already unique)
            Total increments = 6
            Final array = [1, 2, 3, 4, 5, 6]

        Output:
            ✅ Minimum 6 increments are required.
            ✅ Final array → [1, 2, 3, 4, 5, 6]

    Time Complexity:
        - O(N log N): Sorting dominates the complexity.
    Space Complexity:
        - O(1): In-place modifications.

    Applications:
        - Useful in scheduling, ID assignment, and resource allocation problems
          where uniqueness is required.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int minIncrement(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i - 1] >= arr[i]) {
            cnt += arr[i - 1] - arr[i] + 1;
            arr[i] = arr[i - 1] + 1;
        }
    }
    return cnt;
}

int main() {
    vector<int> arr = {1, 1, 2, 3, 6, 2};
    
    cout << "Array : [ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
    
    int moves = minIncrement(arr);
    
    cout << "\nMinimum " << moves << " increments are required to make all elements unique.\n";
    
    cout << "\nAnd the array will become : [ ";
    for (int x : arr) cout << x << " ";
    cout << "]\n";
    
    return 0;
}






