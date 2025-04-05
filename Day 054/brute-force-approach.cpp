/*
    Title: Count Pairs with Sum Equal to Target (Brute Force Approach)

    Problem Statement:
        - Given an array of integers and a target sum `target`, 
          count the number of unique pairs `(arr[i], arr[j])` such that:
              arr[i] + arr[j] == target  (where i < j)

    Approach:
        - Use **nested loops** to check each possible pair in the array.
        - For every pair `(i, j)` where `i < j`, check if the sum is equal to the target.
        - Increment the `count` for every valid pair.

    Time Complexity:
        - **O(n²)** (Due to the nested loop iterating over all possible pairs)

    Space Complexity:
        - **O(1)** (No extra space used)

    Assumption:
        - The array is not necessarily sorted.
        - Duplicate elements are allowed, and each valid `(i, j)` pair is counted only once.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to count pairs whose sum is exactly equal to the target
int countPair(vector<int> arr, int target) {
    int n = arr.size();
    if (n < 2) {
        cout << "Array must have at least two elements!" << endl;
        return -1;
    }

    int count = 0;

    // Brute-force check for every pair
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    // Sample array
    vector<int> arr = {-2, 1, 2, 3, 4, 5, 8, 9, 11};
    int target = 8;

    // Output the count of pairs with sum equal to target
    cout << "Number of pairs with sum equal to " << target << " is: ";
    cout << countPair(arr, target) << endl;

    return 0;
}
