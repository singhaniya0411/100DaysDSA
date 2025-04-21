/*
    Title: Trapping Rain Water (Two Pointers Approach)
    
    
    Problem Statement:
        - Given an array representing the elevation map where the width of each bar is 1,
          compute how much water it can trap after raining.

    Approach:
        - Use two pointers starting from both ends of the array.
        - Maintain the maximum heights seen so far from both left and right.
        - At each step, move the pointer from the side with the smaller current max height,
          and accumulate trapped water if the current height is less than the max.

    Time Complexity:
        - **O(n)** — Each element is visited at most once.

    Space Complexity:
        - **O(1)** — Constant space used.

    Assumption:
        - Elevation map contains only non-negative integers.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Function to calculate maximum water trapped
int maxWater(int arr[], int size) {
    if (size < 3) return 0; // Less than 3 bars can't trap any water

    int left = 1;
    int right = size - 2;

    int lMax = arr[0];
    int rMax = arr[size - 1];

    int res = 0;

    while (left <= right) {
        if (rMax < lMax) {
            res += max(0, rMax - arr[right]);
            rMax = max(rMax, arr[right]);
            right--;
        } else {
            res += max(0, lMax - arr[left]);
            lMax = max(lMax, arr[left]);
            left++;
        }
    }

    return res;
}

int main() {
    int arr[] = {3,0,1,0,4,0,2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum water trapped: " << maxWater(arr, size) << endl;

    return 0;
}
