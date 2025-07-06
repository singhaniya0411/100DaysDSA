/*
    Title: Evaluate Reverse Polish Notation (Postfix Expression)
.
    Problem Statement:
        - Given a list of tokens representing an arithmetic expression in Reverse Polish Notation (RPN),
          evaluate the expression and return the result.
        - Valid operators are "+", "-", "*", and "/".
        - Each operand may be an integer, and division between two integers should truncate toward zero.

    Approach:
        - Use a stack to process the tokens.
        - If the token is a number, push it to the stack.
        - If the token is an operator, pop two numbers from the stack,
          apply the operation, and push the result back onto the stack.
        - The final result will be the only value left in the stack.

    Time Complexity:
        - O(n), where n is the number of tokens.

    Space Complexity:
        - O(n), for the stack.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int evaluate(vector<string>& arr) {
    stack<int> st;

    for (string token : arr) {
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();

            if (token == "+") st.push(a + b);
            else if (token == "-") st.push(a - b);
            else if (token == "*") st.push(a * b);
            else st.push(a / b); // assumes no division by zero
        } else {
            st.push(stoi(token)); // convert string to int
        }
    }

    return st.top();
}

// Main function to test the evaluation
int main() {
    vector<string> expression1 = {"2", "1", "+", "3", "*"};       // (2 + 1) * 3 = 9
    vector<string> expression2 = {"4", "13", "5", "/", "+"};      // 4 + (13 / 5) = 6
    vector<string> expression3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    // Complex expression: (((10 * (6 / ((9 + 3) * -11))) + 17) + 5)

    cout << "Result of Expression 1: " << evaluate(expression1) << endl;
    cout << "Result of Expression 2: " << evaluate(expression2) << endl;
    cout << "Result of Expression 3: " << evaluate(expression3) << endl;

    return 0;
}
