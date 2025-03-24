/*
    Title: Find Unique Triplets with Sum Zero using Hashing
    Problem Statement:
        - Given an array of integers, find all unique triplets whose sum equals zero.

    Approach:
        - Use **hashing** to efficiently find pairs that sum to a required value.
        - Iterate through the array and use an **unordered_set** to check complements.
        - Store results in a **set of vectors** to ensure uniqueness.
    
    Returns:
        - Prints all unique triplets that satisfy the condition.

    Time Complexity:
        - **O(n²)** (Using hashing to reduce unnecessary iterations)

    Space Complexity:
        - **O(n)** (For storing visited elements)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
using namespace std;

// Function to find and print all unique triplets that sum to zero
void findTriplets(int arr[], int n) {
    set<vector<int>> resSet;  // Stores unique triplets

    for (int i = 0; i < n - 1; i++) {
        unordered_set<int> seen;  // Stores elements for the current iteration
        
        for (int j = i + 1; j < n; j++) {
            int complement = -(arr[i] + arr[j]);
            
            if (seen.count(complement)) {
                vector<int> triplet = {arr[i], arr[j], complement};
                sort(triplet.begin(), triplet.end());  // Sort to maintain uniqueness
                resSet.insert(triplet);
            }
            
            seen.insert(arr[j]);
        }
    }

    // Printing unique triplets
    for (const auto& triplet : resSet) {
        cout << triplet[0] << " , " << triplet[1] << " , " << triplet[2] << "\n";
    }
}

int main() {
    int n = 7;
    int arr[n] = {4, 1, 7, -8, -5, 9,-4};
    
    findTriplets(arr, n);
    
    return 0;
}
