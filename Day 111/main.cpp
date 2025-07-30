/*
    Title: Count Palindromic Substrings of Length ≥ 2.

    Problem Statement:
        - Given a string `s`, count the number of palindromic substrings of length 
          greater than or equal to 2.
        - A substring is palindromic if it reads the same forward and backward.

    Example:
        Input:  s = "abba"
        Output: 2  (The palindromic substrings are "bb" and "abba")

    Approach:
        - Use dynamic programming with a 2D DP table `dp[i][j]` where:
            - dp[i][j] = true if the substring s[i..j] is a palindrome.
        - Initialize substrings of length 2 separately.
        - For substrings of length ≥ 3, check s[i] == s[j] and dp[i+1][j-1] == true.
        - Count all dp[i][j] = true where (j - i + 1) ≥ 2.

    Time Complexity:
        - O(n^2), where n is the length of the string.

    Space Complexity:
        - O(n^2), for the DP table.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int countPalindromeSubstrings(string s) {
    int n = s.size();
    int ans = 0;

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // Substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            ans++;
        }
    }

    // Substrings of length ≥ 3
    for (int len = 3; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                ans++;
            }
        }
    }

    return ans;
}

// Main function to test the logic
int main() {
    string input = "abba";
    int result = countPalindromeSubstrings(input);

    cout << "Count of Palindromic Substrings (length ≥ 2): " << result << endl;
    return 0;
}
