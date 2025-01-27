/*
    Title: Binary Addition of Two Strings
    Description:
        This program performs binary addition of two binary strings. It handles edge cases 
        such as leading zeros in the input strings and ensures proper handling of carries during 
        the addition process.

    Approach:
        - Remove leading zeros from both binary strings using a helper function.
        - Traverse both strings from the least significant bit (rightmost) to the most significant bit.
        - Compute the bit sum of corresponding bits from both strings along with the carry.
        - Update the carry and append the calculated bit to the result string.
        - Reverse the result string at the end to get the final binary sum.

    Special Cases:
        - Handles cases where one or both input strings are empty.
        - Handles cases with only zeros in the input strings.

    Input:
        - Two binary strings representing non-negative binary numbers.

    Output:
        - The binary string representing the sum of the two input binary strings.

    Time Complexity:
        - O(max(m, n)), where `m` and `n` are the lengths of the two binary strings.

    Space Complexity:
        - O(max(m, n)), due to the result string.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// Function to remove leading zeros from a binary string
string delete_leading_zeros(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            return s.substr(i, s.length());
        }
    }
    return "0"; // Return "0" if the string is all zeros
}

// Function to perform binary addition of two strings
string binary_addition(string st1, string st2) {
    st1 = delete_leading_zeros(st1);
    st2 = delete_leading_zeros(st2);

    int carry = 0, bitsum = 0;
    string result = "";
    int m = st1.length() - 1;
    int n = st2.length() - 1;

    // Traverse both strings and calculate bit sum
    while (m >= 0 || n >= 0 || carry) {
        int bit1 = (m >= 0) ? st1[m] - '0' : 0;
        int bit2 = (n >= 0) ? st2[n] - '0' : 0;
        bitsum = bit1 + bit2 + carry;
        carry = bitsum / 2;
        result.push_back((bitsum % 2) + '0');
        m--;
        n--;
    }

    // Reverse the result string to get the correct binary sum
    reverse(result.begin(), result.end());

    return result;
}

int main() {
    string st1, st2;
    cout << "Enter first binary string: ";
    getline(cin, st1);
    cout << "Enter second binary string: ";
    getline(cin, st2);

    cout << "Binary addition of " << st1 << " and " << st2 << " : " << binary_addition(st1, st2);
    return 0;
}
