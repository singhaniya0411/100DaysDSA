/* 
    Title: Edit Distance (Levenshtein Distance) - Minimum Operations

    Problem Statement:
        - Given two strings `s1` and `s2`, find the minimum number of operations 
          required to convert `s1` into `s2`.
        - Allowed operations:
            1. Insert a character
            2. Delete a character
            3. Replace a character

    Example:
        Input:  s1 = "abcde", s2 = "bcfeg"
        Output: 3  (One possible sequence: abcde → bcde → bcfe → bcfeg)

    Approach:
        - Use bottom-up dynamic programming.
        - Define `dp[i][j]` as the minimum edit distance between:
              - first `i` characters of s1
              - first `j` characters of s2
        - Base cases:
            - dp[i][0] = i  (delete all i characters)
            - dp[0][j] = j  (insert all j characters)
        - Recurrence:
            - If s1[i-1] == s2[j-1], dp[i][j] = dp[i-1][j-1]
            - Else, dp[i][j] = 1 + min(
                  dp[i][j-1],    // Insert
                  dp[i-1][j],    // Delete
                  dp[i-1][j-1]   // Replace
              )

    Time Complexity:
        - O(m * n), where m and n are the lengths of the strings.

    Space Complexity:
        - O(m * n), for the DP table.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int editDistance(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; i++) {
        dp[i][0] = i; // Deleting all characters from s1
    }
    for (int j = 0; j <= n; j++) {
        dp[0][j] = j; // Inserting all characters into s1
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Characters match
            } else {
                dp[i][j] = 1 + min({dp[i][j - 1],    // Insert
                                    dp[i - 1][j],    // Delete
                                    dp[i - 1][j - 1] // Replace
                                   });
            }
        }
    }

    return dp[m][n];
}

int main() {
    string s1 = "abcde";
    string s2 = "bcfeg";

    cout << "No. of steps to convert string s1 to string s2: "
         << editDistance(s1, s2) << endl;

    return 0;
}
