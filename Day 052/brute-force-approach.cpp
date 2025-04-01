/*
    Title: Count Pairs with Sum Less Than Target (Brute Force Approach)

    Problem Statement:
        - Given a **sorted** array of integers and a target sum `target`, 
          find the number of pairs `(arr[i], arr[j])` such that:
              arr[i] + arr[j] < target  (where i < j)

    Approach:
        - Use **nested loops** to check each pair in the array.
        - If the sum of `arr[i] + arr[j]` is less than `target`, increment the count.

    Time Complexity:
        - **O(n²)** (Due to the nested loop iterating over all pairs)

    Space Complexity:
        - **O(1)** (No extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to count pairs whose sum is less than the target (Brute Force)
int sumLessThanTarget(vector<int> arr, int target) {
    int count = 0;
    int n = arr.size();

    // Iterate over all pairs (i, j) where i < j
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the sum of the pair is less than the target
            if (arr[i] + arr[j] < target) {
                count++;
            }
        }
    }
    return count;
}

int main() {
    // Sample sorted array
    vector<int> arr = {-2, 1, 2, 3, 4, 5, 8, 9, 11};
    
    int target = 8;

    // Print the count of pairs whose sum is less than the target
    cout << "Pairs with sum less than " << target << ": " << sumLessThanTarget(arr, target) << endl;
    
    return 0;
}
