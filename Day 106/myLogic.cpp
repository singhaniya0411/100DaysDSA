/*
    Title: Largest Rectangle in Histogram (Brute Force Approach)

    Problem Statement:
        - Given an array representing the heights of bars in a histogram, 
          find the area of the largest rectangle that can be formed within the histogram.

    Example:
        Input:  [1, 2, 3, 4, 5, 6, 7, 8, 8]
        Output: 36
        Explanation:
            - The rectangle formed by heights [3,4,5,6,7,8] gives area 6 * 6 = 36.

    Approach:
        - For each bar, expand left and right to find the maximum width where the current bar 
          can be the smallest bar (height).
        - Calculate area for each bar as height * width, and track the maximum.

    Time Complexity:
        - O(n²), where n is the number of bars (due to nested scanning).

    Space Complexity:
        - O(1), no extra data structures used.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

int getMaxArea(vector<int> arr) {
    int n = arr.size();
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int l = i;
        int r = i;

        // Expand left
        while (l > 0 && arr[l - 1] >= arr[i]) {
            l--;
        }

        // Expand right
        while (r < n - 1 && arr[r + 1] >= arr[i]) {
            r++;
        }

        // Calculate area
        ans = max(ans, arr[i] * (r - l + 1));
    }

    return ans;
}

// Main function to test the logic
int main() {
    vector<int> input = {1, 2, 3, 4, 5, 6, 7, 8, 8};
    int output = getMaxArea(input);

    cout << "Largest Rectangle Area: " << output << endl;
    return 0;
}
