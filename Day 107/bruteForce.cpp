/*
    Title: Maximum of Minimums for Every Window Size (Without Stack).

    Problem Statement:
        - For every window size from 1 to n in an array,
          find the maximum among all minimum values of subarrays of that window size.

    Example:
        Input:  [10, 20, 25, 15, 90, 50, 70, 60]
        Output: [90, 50, 50, 20, 20, 10, 10, 10]

    Approach:
        - For each element, find its Previous Smaller Element (PSE) and Next Smaller Element (NSE)
          by scanning left and right (O(n²) approach, no stack).
        - For each element, calculate window length = NSE[i] - PSE[i] - 1.
        - Fill the result array with max of minimums for each window size.
        - Propagate values from right to left to fill missing entries.

    Time Complexity:
        - O(n²), since for each element we scan left and right to find PSE and NSE.

    Space Complexity:
        - O(n), for PSE, NSE, and result arrays.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();
    
    vector<int> PSE(n, -1);  // Previous Smaller Element
    vector<int> NSE(n, n);   // Next Smaller Element

    // Find PSE for each element
    for (int i = 0; i < n; i++) {
        int l = i - 1;
        while (l >= 0 && arr[l] >= arr[i]) {
            l--;
        }
        PSE[i] = l;
    }

    // Find NSE for each element
    for (int i = 0; i < n; i++) {
        int r = i + 1;
        while (r < n && arr[r] >= arr[i]) {
            r++;
        }
        NSE[i] = r;
    }

    vector<int> res(n, -1);

    // Fill result array
    for (int i = 0; i < n; i++) {
        int length = NSE[i] - PSE[i] - 1;
        res[length - 1] = max(res[length - 1], arr[i]);
    }

    // Fill missing values
    for (int i = n - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }

    return res;
}

// Main
int main() {
    vector<int> arr = {10, 20, 25, 15, 90, 50, 70, 60};
    
    vector<int> res = maxOfMins(arr);
    cout << "Maximum of minimums for every window size:\n";
    for (int val : res) {
        cout << val << "  ";
    }
    cout << endl;
    
    return 0;
}
