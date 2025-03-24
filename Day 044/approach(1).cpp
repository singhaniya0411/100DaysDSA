/*
    Title: Find Triplets with Sum Zero using Brute Force

    Problem Statement:
        - Given an array of integers, find all unique triplets whose sum equals zero.
        
    Approach:
        - Use a **brute force** method with three nested loops.
        - Iterate through all possible triplets in the array.
        - Check if the sum of any three numbers is zero.
        - Print the valid triplets.
        
    Returns:
    
        - Prints all unique triplets that satisfy the condition.

    Time Complexity:
        - **O(n³)** (Three nested loops for checking all triplets)

    Space Complexity:
        - **O(1)** (Constant extra space usage)

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Function to find and print all unique triplets in the array that sum up to zero
void findTriplets(int arr[], int n) {
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] + arr[j] + arr[k] == 0) {
                    cout << arr[i] << " , " << arr[j] << " , " << arr[k] << "\n";
                }
            }
        }
    }
}

int main() {
    int n = 6;
    int arr[n] = {4, 1, 7, -8, -5, 9};
    
    findTriplets(arr, n);
    
    return 0;
}
