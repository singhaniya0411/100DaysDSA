/*
    Title: First Non-Repeating Character (Brute Force)
    Description:
        This program finds the first non-repeating character in a given string
        using a brute-force approach.

    Approach:
        - Use an array to store the frequency of characters.
        - First loop: Count occurrences of each character.
        - Second loop: Find the first character with a frequency of 1.
        - If no unique character is found, return `'$'`.

    Special Cases:
        - Handles cases where all characters repeat.
        - Works for both uppercase and lowercase characters.

    Input:
        - A string.

    Output:
        - The first non-repeating character, or `'$'` if none exists.

    Time Complexity:
        - O(n), where `n` is the length of the string.

    Space Complexity:
        - O(1), as only an array of fixed size (26) is used.

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<string>
using namespace std;

char first_non_repeat(string s){
    int arr[26] = {0}; // Array to store character frequency
    
    // Count frequency of each character
    for(int i = 0; i < s.length(); i++){
        arr[s[i] - 'a']++;
    }
    
    // Find the first non-repeating character
    for(int i = 0; i < s.length(); i++){
        if(arr[s[i] - 'a'] == 1){
            return s[i];
        }
    }
    return '$';
}

int main(){
    string s;
    cout << "Enter the string: ";
    getline(cin, s);
    
    char result = first_non_repeat(s);
    if(result == '$'){
        cout << "No non-repeating character found.";
    } else {
        cout << "First non-repeating character in the entered string is: " << result;
    }
    return 0;
}
