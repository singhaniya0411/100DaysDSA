/*
    Title: Check for Balanced Brackets.

    Problem Statement:
        - Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
          determine if the input string has valid (balanced) brackets.
        - A string is valid if:
            - Open brackets are closed by the same type of brackets.
            - Open brackets are closed in the correct order.

    Approach:
        - Use a stack to track opening brackets.
        - Push opening brackets into the stack.
        - For each closing bracket, check if it matches the top of the stack.
        - If any mismatch or extra closing bracket found → invalid.
        - At the end, stack must be empty.
        
    Time Complexity:
        - O(n), where n is the length of the string.

    Space Complexity:
        - O(n), in the worst case all characters are opening brackets.

    Author: Vishal Singhaniya.
    
*/

#include <iostream>
#include<vector>
#include <stack>
using namespace std;

bool isBalanced(string& k) {
    stack<char> st;
    
    for (char ch : k) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else {
            if (st.empty()) return false;
            if ((ch == ')' && st.top() != '(') ||
                (ch == '}' && st.top() != '{') ||
                (ch == ']' && st.top() != '[')) {
                return false;
            }
            st.pop();
        }
    }
    
    return st.empty();
}

// Main function to test isBalanced
int main() {
    vector<string> testCases = {
        "()",       // true
        "({[]})",   // true
        "([)]",     // false
        "{[()()]}", // true
        "{[(])}",   // false
        "((())",    // false
        ""          // true
    };

    for (string& s : testCases) {
        cout << "Input: " << s << " -> " 
             << (isBalanced(s) ? "Balanced" : "Not Balanced") << endl;
    }

    return 0;
}
