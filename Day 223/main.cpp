/*
    Title: Next Greater Element in Circular Array.

    Problem Statement:
        - Given a circular array of integers, find the next greater element 
          for each element in the array.
        - The next greater element of a number is the first greater number 
          to its right while traversing circularly.
        - If no such element exists, return -1 for that position.

    Example:
        Input:
            arr = {5, 7, 1, 2, 6}

        Output:
            7 -1 2 6 7

        Explanation:
            - Next greater of 5 → 7
            - Next greater of 7 → none → -1
            - Next greater of 1 → 2
            - Next greater of 2 → 6
            - Next greater of 6 → 7 (circular traversal)

    Approach:
        1. Use a stack to maintain potential next greater elements.
        2. Traverse the array from right to left twice (2*n iterations)
           to simulate circular behavior.
        3. Pop elements from the stack that are smaller or equal.
        4. If within original range (i < n), store result.
        5. Push current element into the stack.

    Time Complexity:
        - O(N), since each element is pushed and popped once.

    Space Complexity:
        - O(N), for stack and result array.

    Applications:
        - Stock span problems
        - Circular array processing
        - Monotonic stack problems

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int> &arr){
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;

    for(int i = 2*n - 1; i >= 0; i--){
        while(!st.empty() && st.top() <= arr[i % n]){
            st.pop();
        }

        if(i < n && !st.empty()){
            res[i] = st.top();
        }

        st.push(arr[i % n]);
    }
    return res;
}

int main(){
    vector<int> arr = {5, 7, 1, 2, 6};
    vector<int> res = nextGreater(arr);

    cout << "Next greater elements are: ";
    for(int x : res){
        cout << x << " ";
    }
    cout << endl;

    return 0;
}











