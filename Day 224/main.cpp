/*
    Title: Sum of Maximum Elements of All Subarrays.

    Problem Statement:
        - Given an integer array `arr`, find the sum of maximum elements
          of all possible subarrays.
        - For every subarray, identify its maximum element and add it to the total sum.

    Example:
        Input:
            arr = [3, 1, 2, 4]

        Subarrays and their maximums:
            [3] → 3
            [3,1] → 3
            [3,1,2] → 3
            [3,1,2,4] → 4
            [1] → 1
            [1,2] → 2
            [1,2,4] → 4
            [2] → 2
            [2,4] → 4
            [4] → 4

        Output:
            Sum = 30

    Approach:
        - Use a **monotonic decreasing stack** to compute:
            • `left[i]`  → number of subarrays ending at `i` where `arr[i]` is the maximum  
            • `right[i]` → number of subarrays starting at `i` where `arr[i]` is the maximum
        - Contribution of each element:
              arr[i] × left[i] × right[i]
        - Sum contributions of all elements.

    Steps:
        1. Traverse from left to right to calculate `left[]`.
        2. Traverse from right to left to calculate `right[]`.
        3. Multiply contribution for each index and accumulate result.

    Time Complexity:
        - O(n), each element is pushed and popped once

    Space Complexity:
        - O(n), for stacks and auxiliary arrays

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int sumOfMax(vector<int> &arr) {
    int n = arr.size();
    int res = 0;
    
    vector<int> left(n), right(n);
    stack<int> st;

    // Count elements to the left
    for(int i = 0; i < n; i++){
        while(!st.empty() && arr[st.top()] < arr[i]){
            st.pop();
        }
        left[i] = st.empty() ? (i + 1) : (i - st.top());
        st.push(i);
    }

    while(!st.empty()) st.pop();

    // Count elements to the right
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && arr[st.top()] <= arr[i]){
            st.pop();
        }
        right[i] = st.empty() ? (n - i) : (st.top() - i);
        st.push(i);
    }

    // Calculate total sum
    for(int i = 0; i < n; i++){
        res += arr[i] * left[i] * right[i];
    }

    return res;
}

int main(){
    vector<int> arr = {3, 1, 2, 4};
    cout << "Sum of maximum elements of all subarrays: " << sumOfMax(arr) << endl;
    return 0;
}










