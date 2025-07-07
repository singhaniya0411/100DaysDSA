/*
    Title: Next Greater Element to the Right

    Problem Statement:
        - Given an array of integers, find the next greater element for each element in the array.
        - The next greater element for an element x is the first greater element on the right side of x in the array.
        - If no such element exists, store -1 for that position.

    Approach:
        - Traverse the array from right to left.
        - Use a stack to keep track of elements whose next greater is not yet found.
        - Pop elements from the stack while they are less than or equal to the current element.
        - If the stack is not empty, the top of the stack is the next greater element.
        - Push the current element onto the stack for the next iterations.

    Time Complexity:
        - O(n), where n is the number of elements in the array.

    Space Complexity:
        - O(n), for the result array and the stack.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextLargerElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> res(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            res[i] = st.top();
        }
        st.push(arr[i]);
    }

    return res;
}

// Main function to test the logic
int main() {
    vector<int> input = {4, 5, 2, 10, 8};
    vector<int> output = nextLargerElement(input);

    cout << "Next Greater Elements: ";
    for (int val : output) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
