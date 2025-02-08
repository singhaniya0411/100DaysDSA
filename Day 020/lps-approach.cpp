/*
    Title: Minimum Characters for Palindrome
    Description:
        - This program finds the minimum number of characters 
          that need to be added at the beginning of a string 
          to make it a palindrome.

    Approach:
        - Uses the **Longest Prefix Suffix (LPS) Array** from the KMP algorithm.
        - Construct a new string as `s + "$" + reverse(s)`.
        - Compute the LPS array for this string.
        - The minimum characters to add is calculated as `(Original Length - Last LPS value)`.

    Time Complexity:
        - O(n), where n is the length of the string (efficient LPS computation).

    Space Complexity:
        - O(n), due to the LPS array.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // Required for reverse()
using namespace std;

// Function to compute the LPS (Longest Prefix Suffix) array
void compute_lps_array(const string &s, vector<int> &lps) {
    int len = 0;  // Length of previous longest prefix suffix
    lps[0] = 0;   // First character always has LPS value 0

    int i = 1;
    while (i < s.length()) {
        if (s[i] == s[len]) {  // Match found
            len++;
            lps[i] = len;
            i++;
        } else {  // Mismatch case
            if (len > 0) {
                len = lps[len - 1];  // Reduce len to check previous prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to find the minimum characters needed to make a string palindrome
int min_char_for_palindrome(const string &s) {
    string reversed_s = s;
    reverse(reversed_s.begin(), reversed_s.end());
    string combined = s + "$" + reversed_s;  // Concatenated string with a separator

    vector<int> lps(combined.length(), 0); // LPS array
    compute_lps_array(combined, lps);

    // Minimum characters to add = (Original length - Last LPS value)
    return s.length() - lps.back();
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);

    cout << "Minimum characters to add for palindrome: " << min_char_for_palindrome(s) << endl;
    return 0;
}
