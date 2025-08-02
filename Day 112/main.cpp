/*
    Title: Longest Palindromic Substring.

    Problem Statement:
        - Given a string `s`, find the longest substring which is a palindrome.
        - A palindrome is a sequence that reads the same forward and backward.

    Example:
        Input:  s = "babad"
        Output: "bab" (or "aba", both are valid)

    Approach:
        - Use Dynamic Programming.
        - Create a 2D DP table `dp[i][j]` where dp[i][j] = true means substring s[i..j] is a palindrome.
        - Initialize all substrings of length 1 as palindromes.
        - Check substrings of length 2.
        - For substrings of length ≥ 3, use the relation:
            s[i] == s[j] && dp[i+1][j-1] → dp[i][j] = true
        - Track the start index and maximum length of the longest palindromic substring.

    Time Complexity:
        - O(n^2), where n is the length of the string.

    Space Complexity:
        - O(n^2), for the DP table.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if (n == 0) return "";

    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0;
    int maxLen = 1;

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Check substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            maxLen = 2;
        }
    }

    // Check substrings of length 3 or more
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                if (l > maxLen) {
                    start = i;
                    maxLen = l;
                }
            }
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string input = "babad";
    cout << "Longest Palindromic Substring: " << longestPalindrome(input) << endl;
    return 0;
}










