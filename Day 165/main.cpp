/*
    Title: Sentence Palindrome Checker

    Problem Statement:
        - Given a sentence (string) that may contain letters, digits, spaces, and special symbols.
        - Check whether the sentence is a palindrome or not.
        - Ignore non-alphanumeric characters (e.g., spaces, punctuation, symbols).
        - Comparison should be case-insensitive.

    Approach:
        1. Use two pointers: `i` (start) and `j` (end).
        2. Skip all characters that are not alphanumeric.
        3. Compare lowercase versions of characters at `i` and `j`.
        4. If all valid characters match, the sentence is a palindrome.
        5. Otherwise, return false.

    Example:
        Input:
            s = "ABC $. def01ASDF".
        
        Process:
            - Filtered alphanumeric: "ABCdef01ASDF"
            - Lowercase comparison → "abcdef01asdf" ≠ "fdsa10fedcba"
            → Not a palindrome.

        Output:
            Sentence is not palindrome

    Time Complexity:
        - O(N), where N = length of the string.

    Space Complexity:
        - O(1), no extra space used.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

bool isPalSen(string &s){
    int i = 0;
    int j = s.size()-1;
    
    while(i<=j){
        if(!isalnum(s[i])){
            i++;
        }
        else if(!isalnum(s[j])){
            j--;
        }
        else if(tolower(s[i])==tolower(s[j])){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    string s = "ABC $. def01ASDF";
    
    if(isPalSen(s)){
        cout<<"Sentence is palindrome\n";
    }
    else{
        cout<<"Sentence is not palidrome\n";
    }
    return 0;
}
