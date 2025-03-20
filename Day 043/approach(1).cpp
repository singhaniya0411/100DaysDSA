/*
    Title: Count Pairs with a Given Sum (Brute Force Approach)

    Problem Statement:
        - Given an array of integers, count the number of pairs (i, j) where arr[i] + arr[j] equals a target sum.

    Approach:
        - Use two nested loops to check all possible pairs.
        - If the sum of a pair equals the target, increment the counter.
        - Return the total count of such pairs.

    Returns:
        - The number of pairs that satisfy the condition.

    Time Complexity:
        - **O(n²)** (Since we use two nested loops)

    Space Complexity:
        - **O(1)** (No extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Function to count the number of pairs with a given sum
int countPairsWithSum(int arr[], int n, int target) {
    int pairCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                pairCount++;
            }
        }
    }
    return pairCount;
}

int main() {
    int n = 7;
    int arr[n] = {3, 2, -1, 0, -4, 6, 4};
    
    int target = 2;
    cout << "Number of pairs in the array that sum up to " << target << ": " 
         << countPairsWithSum(arr, n, target) << endl;
    
    return 0;
}
