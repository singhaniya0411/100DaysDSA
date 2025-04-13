/*
    Title: Longest Substring Without Repeating Characters


    Problem Statement:
        - Given a string, return the length of the longest substring 
          without repeating characters.

    Approach:
        - Use the sliding window technique.
        - Maintain a vector to store the last index of each character.
        - Update the start of the window if a duplicate is found.

    Time Complexity:
        - **O(n)** — Each character is processed once.

    Space Complexity:
        - **O(1)** — Fixed size (26 for lowercase English letters)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestUniqueSubstring(string s) {
    int n = s.size();
    int res = 0;
    
    vector<int> lastIndex(26, -1);  // for lowercase letters only
    int start = 0;
    
    for (int end = 0; end < n; end++) {
        int idx = s[end] - 'a'; // equivalent to Python's ord(s[end]) - ord('a')
        
        if (lastIndex[idx] >= start) {
            start = lastIndex[idx] + 1;
        }
        
        lastIndex[idx] = end;
        res = max(res, end - start + 1);
    }
    
    return res;
}

int main() {
    string st = "geeksforgeeks";
    
    cout << "Length of longest Unique substring : " << longestUniqueSubstring(st) << endl;

    return 0;
}
