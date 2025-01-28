/*
    Title: 
        Check Anagram of Two Strings
    Description:
        This program checks whether two given strings are anagrams of each other.
        Two strings are considered anagrams if they contain the same characters 
        with the same frequency, but in any order.

    Approach:
        - First, compare the lengths of the two strings. If they differ, return false.
        - Use an integer array of size 26 (representing the English alphabet) 
          to count character occurrences in the first string and decrement for 
          occurrences in the second string.
        - Traverse the array to check if all counts are zero, confirming the strings are anagrams.

    Special Cases:
        - Handles cases where strings contain non-alphabetic characters gracefully 
          (limited to lowercase letters for simplicity).
        - Case-sensitive comparison (assumes input strings are in lowercase).

    Input:
        - Two strings to be checked for anagram status.

    Output:
        - A message indicating whether the strings are anagrams of each other.

    Time Complexity:
        - O(n), where `n` is the length of the strings.

    Space Complexity:
        - O(1), as the array used for counting is fixed in size.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <string>
using namespace std;

// Function to check if two strings are anagrams
bool check_anagram(string st1, string st2) {
    if (st1.length() != st2.length()) {
        return false;
    }

    int arr[26] = {0};

    // Count character occurrences in the first string
    for (int i = 0; i < st1.length(); i++) {
        arr[st1[i] - 'a']++;
    }

    // Decrement counts based on the second string
    for (int i = 0; i < st2.length(); i++) {
        arr[st2[i] - 'a']--;
    }

    // Check if all counts are zero
    for (int i = 0; i < 26; i++) {
        if (arr[i] != 0) {
            return false;
        }
    }

    return true;
}

int main() {
    string st1, st2;
    cout << "Enter first string: ";
    getline(cin, st1);
    cout << "Enter second string: ";
    getline(cin, st2);

    if (check_anagram(st1, st2)) {
        cout << "Yes! " << st1 << " and " << st2 << " are anagrams of each other.";
    } else {
        cout << "No! The entered strings are not anagrams of each other.";
    }
    return 0;
}
