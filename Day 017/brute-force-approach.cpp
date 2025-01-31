/*
    Title: First Non-Repeating Character (Brute Force)
    Description:
        This program finds the first non-repeating character in a given string
        using a brute-force approach.

    Approach:
        - Use two nested loops:
          - The **outer loop** picks each character.
          - The **inner loop** checks if the character appears again in the string.
        - If a character is found **only once**, return it.
        - If no unique character is found, return `'$'`.

    Special Cases:
        - Handles cases where all characters repeat.
        - Works for both uppercase and lowercase characters.

    Input:
        - A string.

    Output:
        - The first non-repeating character, or `'$'` if none exists.

    Time Complexity:
        - O(n²), where `n` is the length of the string.

    Space Complexity:
        - O(1), as no extra space is used apart from variables.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <string>
using namespace std;

char first_non_repeat(string s) {
    int n = s.length();

    for (int i = 0; i < n; i++) {
        bool isUnique = true;

        for (int j = 0; j < n; j++) {
            if (i != j && s[i] == s[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            return s[i];
        }
    }

    return '$'; // No unique character found
}

int main() {
    string st1;
    cout << "Enter the string: ";
    getline(cin, st1);

    char result = first_non_repeat(st1);
    if (result == '$') {
        cout << "No non-repeating character found." << endl;
        return -1;
    } else {
        cout << "First non-repeating character is: " << result << endl;
    }

    return 0;
}
