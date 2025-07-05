/*
    Title: Longest Valid Parentheses Substring.

    Problem Statement:
        - Given a string containing just the characters '(' and ')',
          find the length of the longest valid (well-formed) parentheses substring.

    Approach:
        - Use a stack to store indices.
        - Push -1 initially to handle base cases.
        - For every '(', push its index.
        - For every ')', pop from the stack.
          - If the stack becomes empty, push current index.
          - Else, update the maximum length as difference between current index and top of stack.

    Time Complexity:
        - O(n), where n is the length of the string.

    Space Complexity:
        - O(n), for the stack used.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int maxLength(string& s) {
    stack<int> st;
    int n = s.size();
    st.push(-1);  // base for length calculation
    
    int maxlen = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                maxlen = max(maxlen, i - st.top());
            }
        }
    }
    
    return maxlen;
}

// Main function to test
int main() {
    vector<string> testCases = {
        "(()",          // Output: 2
        ")()())",       // Output: 4
        "(()())",       // Output: 6
        "(((",          // Output: 0
        "",             // Output: 0
        "()(()",        // Output: 2
        "()()()",       // Output: 6
        "())(())"       // Output: 4
    };
    
    for (string& s : testCases) {
        cout << "Input: " << s << " => Max Length: " << maxLength(s) << endl;
    }

    return 0;
}
