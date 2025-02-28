/*
    Title: Aggressive Cows - Maximum Minimum Distance Placement (Brute Force Approach)

    Problem Statement:
        - Given 'N' stalls and 'K' cows, place the cows in the stalls such that the 
          **minimum distance** between any two cows is maximized.
        - Uses a **brute-force approach** by checking each possible distance.

    Approach:
        1. **Sorting the Stall Positions**:
           - Ensures cows are placed in increasing order.
        2. **Iterating Through All Possible Distances**:
           - Checks for the largest feasible minimum distance.
        3. **Checking Feasibility (`checkCow` function)**:
           - Places cows greedily and checks if at least `K` cows can be accommodated.

    Time Complexity:
        - **O(N log N) (Sorting) + O(N * maxDist) (Checking Feasibility)** ≈ **O(N^2)**
    
    Space Complexity:
        - **O(1)** (No extra space used)

    Author: Vishal
*/

#include <iostream>
#include <algorithm> // For sorting
using namespace std;

/**
 * @brief Checks if we can place 'K' cows in stalls with at least 'dist' separation.
 * 
 * @param arr Sorted array of stall positions.
 * @param k Number of cows to place.
 * @param dist Minimum required distance.
 * @param size Number of stalls.
 * @return true if cows can be placed, false otherwise.
 */
bool checkCow(int arr[], int k, int dist, int size) {
    int count = 1;     // Place the first cow at the first stall
    int prev = arr[0]; // Track the last placed cow's position

    for (int i = 1; i < size; i++) {
        if (arr[i] - prev >= dist) { // If the distance condition is met
            prev = arr[i];
            count++;

            if (count == k) { // If all cows are placed, return true
                return true;
            }
        }
    }
    return false;
}

/**
 * @brief Finds the largest minimum distance to place 'K' cows in stalls (Brute Force).
 * 
 * @param arr Array of stall positions.
 * @param size Number of stalls.
 * @param k Number of cows.
 * @return The maximum minimum distance possible.
 */
int aggressiveCows(int arr[], int size, int k) {
    sort(arr, arr + size); // Sort stall positions

    int res = 0; // Store the best minimum distance
    int minDist = 1;
    int maxDist = arr[size - 1] - arr[0];

    // Brute-force approach: Check each possible minimum distance
    for (int i = minDist; i <= maxDist; i++) {
        if (checkCow(arr, k, i, size)) { // If cows can be placed with distance 'i'
            res = i;
        }
    }
    return res;
}

int main() {
    int size;
    cout << "Enter the number of stalls: ";
    cin >> size;
    int arr[size];

    // Taking input for stall positions
    cout << "Enter the positions of stalls: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int k;
    cout << "Enter the number of cows: ";
    cin >> k;

    // Finding and displaying the largest minimum distance
    cout << "Largest minimum distance (Brute Force): " << aggressiveCows(arr, size, k) << endl;
    return 0;
}

