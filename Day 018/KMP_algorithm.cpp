/*
    Title: KMP Pattern Searching Algorithm
    Description:
        - This program searches for a pattern in a given text using 
          the Knuth-Morris-Pratt (KMP) string matching algorithm.
        - The KMP algorithm preprocesses the pattern to create an LPS (Longest Prefix Suffix) array 
          to optimize the searching process.

    Approach:
        1. Preprocess the pattern to create an LPS array.
        2. Iterate through the text while comparing the pattern with the text.
        3. When a mismatch occurs, use the LPS array to avoid unnecessary comparisons.
        4. If the pattern is found, store the starting index and continue searching.

    Edge Cases:
        - If the pattern length is greater than the text length, no occurrences will be found.

    Time Complexity:
        - Worst-case: O(m + n), where m is the length of the text, and n is the length of the pattern.
        - The time complexity is linear due to the preprocessing of the pattern and the linear scan of the text.

    Space Complexity:
        - O(n), where n is the length of the pattern, due to the storage of the LPS array.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array for the pattern
void computeLPS_Array(string pattern, vector<int>& lps) {
    int n = pattern.length();
    int len = 0;
    lps[0] = 0;  // First LPS value is always 0
    int i = 1;

    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Move to previous LPS index
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP algorithm to search the pattern in the text
void KMP_algorithm(string text, string pattern) {
    int m = text.length();   // Length of text
    int n = pattern.length();  // Length of pattern

    if (n > m) {
        cout << "Pattern is longer than text. No occurrence found.\n";
        return;
    }

    vector<int> lps(n, 0);
    computeLPS_Array(pattern, lps);

    vector<int> res;  // Vector to store the results (matching indices)
    int i = 0, j = 0;  // i for text, j for pattern

    // Search for the pattern in the text
    while (i < m) {
        if (text[i] == pattern[j]) {
            i++;
            j++;

            // If we have found a match
            if (j == n) {
                res.push_back(i - j);
                j = lps[j - 1];  // Update j using the LPS array
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];  // Move to previous LPS index
            } else {
                i++;
            }
        }
    }

    // Output the results
    if (res.empty()) {
        cout << "No occurrence found.\n";
    } else {
        for (int index : res) {
            cout << "Found at index: " << index << "\n";
        }
    }
}

int main() {
    string text, pattern;

    // Input text and pattern
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Enter pattern: ";
    getline(cin, pattern);

    // Call the KMP algorithm
    KMP_algorithm(text, pattern);

    return 0;
}
