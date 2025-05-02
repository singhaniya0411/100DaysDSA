/*
    Title: Product of Array Except Self (Brute Force + Zero Handling)

    Problem Statement:
        - Given an array `arr`, return an array `res` such that:
          res[i] = product of all elements in arr except arr[i].
        - Do not use division.
        - Handle cases with zero(s).
        - Assume all elements are integers and array size ≥ 2.

    Approach:
        - Count number of zeros.
        - If no zeros: use total product / arr[i].
        - If one zero: only the index with zero gets product; others are 0.
        - If more than one zero: all elements are 0.
        - Time Complexity: O(n)
        - Space Complexity: O(n)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to compute product except self (with zero handling)
void productExceptSelf(vector<int> arr) {
    int n = arr.size();
    vector<int> res(n, 0);  // initialize with 0

    int zeroz = 0;
    int index = -1;
    int product = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            zeroz++;
            index = i; // store index of zero
        } else {
            product *= arr[i];
        }
    }

    if (zeroz == 0) {
        for (int i = 0; i < n; i++) {
            res[i] = product / arr[i];
        }
    } else if (zeroz == 1) {
        res[index] = product;
    }
    // if zeroz > 1, res already filled with 0

    for (auto i : res) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> arr = {10, 5, 3, 6, 2};  // You can test with 0s too
    productExceptSelf(arr);
    return 0;
}
