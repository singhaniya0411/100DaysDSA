/*
    Title: Brute Force String Searching Algorithm
    Description:
        - This program searches for a pattern in a given text using 
          the brute force approach.

    Approach:
        - Iterate through all possible starting positions in the text.
        - Compare the substring with the pattern character by character.
        - Count and display the number of comparisons.
        - Print all occurrences of the pattern.

    Edge Cases:
        - If the pattern length is greater than the text length, exit early.

    Time Complexity:
        - Worst-case: O(m * n), where m is the length of the text, and n is the pattern length.

    Space Complexity:
        - O(1), as it uses only a few integer variables.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <string>
using namespace std;

void brute_force_searching(const string& text, const string& pattern) {
    int m = text.length();
    int n = pattern.length();
    int comparisons = 0;

    if (n > m) {
        cout << "Pattern length is greater than text length. No matching possible.\n";
        return;
    }

    cout << "Pattern found at index: ";
    bool found = false;

    for (size_t i = 0; i <= m - n; i++) {
        size_t j = 0;

        while (j < n && text[i + j] == pattern[j]) {
            j++;
            comparisons++;
        }

        if (j < n) {
            comparisons++;
        }

        if (j == n) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "No occurrences found.";
    }

    cout << "\nTotal Comparisons: " << comparisons << endl;
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern for searching: ";
    getline(cin, pattern);

    brute_force_searching(text, pattern);
    return 0;
}
