/*
    Title: String Rotation Check (Using KMP Algorithm)
    Description:
        - This program checks if one string is a rotation of another string.
        - Uses the **Knuth-Morris-Pratt (KMP) algorithm** for substring search.

    Approach:
        - Concatenate `s1` with itself: `text = s1 + s1`.
        - Use **KMP algorithm** to check if `s2` is a substring of `text`.

    Time Complexity:
        - O(n), where n is the length of `s1`.

    Space Complexity:
        - O(n), due to the LPS array.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array for pattern
void computeLPS_Array(const string &pattern, vector<int> &lps) {
    int len = 0;  // Length of the previous longest prefix suffix
    lps[0] = 0;   // LPS of the first character is always 0
    int i = 1;

    while (i < pattern.length()) {
        if (pattern[i] == pattern[len]) {  // Characters match
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Move to previous LPS value
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to check if s2 is a rotation of s1 using KMP
bool is_rotation(const string &s1, const string &s2) {
    if (s1.length() != s2.length()) return false;  // Lengths must be equal

    string text = s1 + s1;  // Concatenated string
    vector<int> lps(s2.length(), 0);
    computeLPS_Array(s2, lps);

    int i = 0, j = 0;  // i for text, j for s2

    while (i < text.length()) {
        if (s2[j] == text[i]) {  
            i++;
            j++;
        }
        if (j == s2.length()) return true;  // Found a match
        else if (i < text.length() && text[i] != s2[j]) {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return false;
}

int main() {
    string st1, st2;

    // Input strings
    cout << "Enter string1: ";
    getline(cin, st1);
    cout << "Enter string2: ";
    getline(cin, st2);

    // Check for rotation
    if (is_rotation(st1, st2))
        cout << "Yes, string2 is a rotation of string1." << endl;
    else
        cout << "No, string2 is NOT a rotation of string1." << endl;

    return 0;
}
