/*
    Title: Minimum Characters for Palindrome
    Description:
        - This program finds the minimum number of characters 
          that need to be added at the beginning of a string 
          to make it a palindrome.

    Approach:
        - Check if progressively shorter prefixes form a palindrome.
        - If not, keep reducing the prefix and counting required characters.

    Time Complexity:
        - Worst-case: O(n²), where n is the length of the string.

    Space Complexity:
        - O(1), as no extra space is used apart from variables.

    Author: Vishal Singhaniya
*/


#include <iostream>
#include <string>
using namespace std;

// Function to check if a given string is a palindrome
bool palindrome_check(const string& s) {
    int i = 0;
    int j = s.length() - 1;
    
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

// Function to calculate the minimum characters required to make a string a palindrome
int min_char_for_palindrome(string s) {
    int counter = 0;
    int i = s.length();
    
    while (i > 0) {
        if (palindrome_check(s.substr(0, i))) {  // Check the first `i` characters
            return counter;
        }
        counter++;
        i--;  // Decrease instead of increase
    }
    return counter;
}

int main() {
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    
    cout << "Minimum characters to add to make this string a palindrome: "
         << min_char_for_palindrome(s) << endl;

    return 0;
}
