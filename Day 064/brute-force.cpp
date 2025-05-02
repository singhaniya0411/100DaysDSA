/*
    Title: Product of Array Except Self (Brute Force Approach)

    Problem Statement:
    
        - Given an array `arr`, return an array `res` such that:
          res[i] = product of all elements in arr except arr[i].
        - Do not use division.
        - Assume all elements are integers and array size ≥ 2.
    Approach:
        - For each index i, multiply all elements except arr[i].
        
    Time Complexity: O(n²)
    Space Complexity: O(n) for result array.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to compute product except self (brute-force)
void productExceptSelf(vector<int> arr) {
    int n = arr.size();
    vector<int> res(n, 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                res[i] *= arr[j];
            }
        }
    }

    // Output result
    for (auto i : res) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {10, 5, 3, 6, 2};
    productExceptSelf(arr);
    return 0;
}
