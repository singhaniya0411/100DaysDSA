/*
    Title: Largest Rectangle in Histogram/

    Problem Statement:
        - Given an array of integers representing the heights of bars in a histogram, 
          find the area of the largest rectangle that can be formed within the histogram.

    Example:
        Input:  [4, 5, 2, 10, 8]
        Output: 16  (rectangle with height 4 and width 4 from indices 0 to 3)

    Approach:
        - For each bar, we need to find the nearest smaller bar to the left and the nearest smaller bar to the right.
        - This gives the range over which the current bar can extend as the smallest bar.
        - Use two passes with a stack to compute:
            - `res1[i]`: Index of the next smaller element to the right for bar i.
            - `res2[i]`: Index of the next smaller element to the left for bar i.
        - Area for each bar = height[i] * (res1[i] - res2[i] - 1).
        - Return the maximum area among all bars.

    Time Complexity:
        - O(n), where n is the number of bars (single pass for each stack computation).

    Space Complexity:
        - O(n), for storing left and right smaller indices.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getMaxArea(vector<int> arr) {
    int n = arr.size();
    vector<int> res1(n, 0); // Nearest smaller to right
    vector<int> res2(n, 0); // Nearest smaller to left
    
    stack<int> st;

    // Next smaller element to the right
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        res1[i] = st.empty() ? n : st.top();
        st.push(i);
    }

    while (!st.empty()) st.pop();

    // Next smaller element to the left
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }
        res2[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, arr[i] * (res1[i] - res2[i] - 1));
    }

    return ans;
}

// Main function to test the logic
int main() {
    vector<int> input = {4, 5, 2, 10, 8};
    int output = getMaxArea(input);

    cout << "Largest Rectangle Area: " << output << endl;
    return 0;
}
