/*
    Title: Maximum of Minimums for Every Window Size.

    Problem Statement:
        - Given an array `arr[]` of size `n`, for every window size `k` (1 ≤ k ≤ n),
          find the maximum of the minimum elements of all subarrays of size k.

    Example:
        Input:  [10, 20, 25, 15, 90, 50, 70, 60]
        Output: [90, 50, 50, 20, 20, 10, 10, 10]
        Explanation:
            - For window size 1: max of minimums = max(10,20,25,15,90,50,70,60) = 90
            - For window size 2: max of minimums of all pairs = 50
            - and so on.

    Approach:
        - Use stack to find Previous Smaller Element (PSE) and Next Smaller Element (NSE) for every element.
        - The "length" of the window in which an element is minimum is: (NSE[i] - PSE[i] - 1).
        - Fill results for each possible length.
        - Traverse results from right to left to fill gaps with the maximum value.

    Time Complexity:
        - O(n), as each element is pushed/popped once from the stack.

    Space Complexity:
        - O(n) for PSE, NSE, and result arrays.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();

    vector<int> PSE(n), NSE(n);
    stack<int> st;

    // Previous Smaller Element (to the left)
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        PSE[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Next Smaller Element (to the right)
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i])
            st.pop();
        NSE[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    vector<int> res(n, 0);

    // Fill result for each length
    for (int i = 0; i < n; i++) {
        int length = NSE[i] - PSE[i] - 1;
        res[length - 1] = max(res[length - 1], arr[i]);
    }

    // Fill the remaining values from right to left
    for (int i = n - 2; i >= 0; i--) {
        res[i] = max(res[i], res[i + 1]);
    }

    return res;
}

int main() {
    vector<int> arr = {10, 20, 25, 15, 90, 50, 70, 60};
    vector<int> res = maxOfMins(arr);

    cout << "Maximum of minimums for every window size:\n";
    for (int val : res) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
