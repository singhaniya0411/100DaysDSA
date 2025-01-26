/*
    Title: 
        String to Integer (myAtoi)
    Description:
        This program converts a given string to an integer, handling various edge cases
        such as leading spaces, optional sign symbols ('+' or '-'), and non-numeric characters.
        It follows the rules similar to the `atoi` function in C.

    Approach:
        - Skip leading whitespace characters.
        - Identify the sign of the number (default is positive).
        - Parse consecutive digits, constructing the integer result.
        - Handle integer overflow by returning INT_MAX or INT_MIN as appropriate.
        - Return the final signed integer.

    Special Cases:
        - Handles leading spaces, optional sign symbols, and invalid input gracefully.
        - Prevents overflow by checking the result against INT_MAX and INT_MIN during computation.

    Input:
        - A string containing the representation of a number.

    Output:
        - The integer value derived from the string.

    Time Complexity:
        - O(n), where `n` is the length of the input string.

    Space Complexity:
        - O(1), as no additional data structures are used apart from variables.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <string>
#include <climits>
using namespace std;

// Function to convert string to integer
int myAtoi(string st) {
    int sign = 1; // Default sign is positive
    long long result = 0; // Use long long to handle intermediate overflow
    int idx = 0;

    // Skip leading whitespace
    while (idx < st.length() && st[idx] == ' ') {
        idx++;
    }

    // Determine the sign
    if (idx < st.length() && (st[idx] == '+' || st[idx] == '-')) {
        if (st[idx] == '-') {
            sign = -1;
        }
        idx++;
    }

    // Parse digits and construct the result
    while (idx < st.length() && st[idx] >= '0' && st[idx] <= '9') {
        result = 10 * result + (st[idx] - '0');

        // Check for overflow
        if (result > INT_MAX) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        idx++;
    }

    // Return the signed result
    return static_cast<int>(sign * result);
}

int main() {
    string st;
    cout << "Enter a string: ";
    getline(cin, st);
    cout << "Conversion of string to int: " << myAtoi(st) << endl;

    return 0;
}
