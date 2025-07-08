/*
    Title: Decode Encoded String

    Problem Statement:
        - Given an encoded string, decode it.
        - The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is repeated exactly k times.
        - You may assume that the input string is always valid and contains only digits, letters, and square brackets.

    Approach:
        - Use two stacks: one for numbers and one for strings.
        - Traverse the string character by character:
            - If it's a digit, build the number (handle multi-digit).
            - If it's '[', push current number and string to stacks.
            - If it's ']', pop number and string, repeat the string and append.
            - If it's a character, append it to the current string.
        - At the end, return the fully decoded string.

    Time Complexity:
        - O(n), where n is the length of the input string.

    Space Complexity:
        - O(n), for using stacks to store intermediate strings and numbers.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <stack>
#include <string>
using namespace std;

string decodeString(string s) {
    stack<string> strStack;
    stack<int> numStack;
    string currStr = "";
    int num = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');  // handles multiple digit numbers
        } else if (ch == '[') {
            numStack.push(num);
            strStack.push(currStr);
            num = 0;
            currStr = "";
        } else if (ch == ']') {
            int repeat = numStack.top(); numStack.pop();
            string temp = "";
            for (int i = 0; i < repeat; i++) {
                temp += currStr;
            }
            currStr = strStack.top() + temp;
            strStack.pop();
        } else {
            currStr += ch;
        }
    }

    return currStr;
}

// Main function to test the code
int main() {
    string input = "3[a2[c]]";
    cout << "Decoded string: " << decodeString(input) << endl;
    return 0;
}
