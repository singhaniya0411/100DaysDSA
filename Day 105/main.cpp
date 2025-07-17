/*
    Title: Special Stack with getMin() in O(1).

    Problem Statement:
        - Design a special stack that supports all the standard stack operations (push, pop, peek, isEmpty)
          and an additional operation getMin() which returns the minimum element in the stack.
        - All operations must be done in constant time O(1) and with O(1) extra space (excluding the stack itself).

    Approach:
        - Use an encoding technique during push:
            - If the pushed element is smaller than current min, encode it using: encoded = 2*x - minEle
            - Update minEle to the new element.
        - During pop:
            - If the popped value is less than minEle, decode the previous min using: minEle = 2*minEle - encoded
        - For peek, if top is less than minEle, return minEle (because it's encoded).

    Time Complexity:
        - O(1) for push, pop, peek, and getMin operations.

    Space Complexity:
        - O(1) extra space used for tracking minEle.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> st;
int minEle = -1;

// Push operation with min encoding
void push(int x) {
    if (st.empty()) {
        st.push_back(x);
        minEle = x;
    } else {
        if (x < minEle) {
            st.push_back(2 * x - minEle);
            minEle = x;
        } else {
            st.push_back(x);
        }
    }
}

// Pop operation
int pop() {
    if (st.empty()) return -1;

    int top = st.back();
    st.pop_back();

    if (top < minEle) {
        int original = minEle;
        minEle = 2 * minEle - top;
        return original;
    } else {
        return top;
    }
}

// Peek operation
int peek() {
    if (st.empty()) return -1;

    int top = st.back();
    if (top < minEle) {
        return minEle;
    } else {
        return top;
    }
}

// Get minimum element
int getMinEle() {
    if (st.empty()) return -1;
    return minEle;
}

// Main function to handle input
int main() {
    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            push(x);
        } else if (type == 2) {
            int popped = pop();
            if (popped == -1) cout << "Stack is empty\n";
            else cout << "Popped: " << popped << endl;
        } else if (type == 3) {
            int top = peek();
            if (top == -1) cout << "Stack is empty\n";
            else cout << "Top: " << top << endl;
        } else if (type == 4) {
            int minVal = getMinEle();
            if (minVal == -1) cout << "Stack is empty\n";
            else cout << "Minimum: " << minVal << endl;
        } else {
            cout << "Invalid query\n";
        }
    }

    return 0;
}
