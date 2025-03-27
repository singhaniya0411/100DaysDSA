/*
    Title: Find Longest Consecutive Subsequence (Sorting Approach)

    Problem Statement:
        - Given an array of integers, find the length of the longest consecutive subsequence.

    Approach:
        - Sort the array.
        - Traverse through the sorted array and count the longest consecutive sequence.
        - Skip duplicate elements and reset count when the sequence breaks.

    Time Complexity:
        - **O(n log n)** (due to sorting)

    Space Complexity:
        - **O(1)** (constant extra space used)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Function to find the length of the longest consecutive subsequence
int longestSubsequence(vector<int>& a) {
    if (a.empty()) return 0; // Edge case: Empty array
    
    sort(a.begin(), a.end()); // Sorting the array
    
    int longest = 1, count = 1;

    // Traverse through sorted array
    for (int i = 1; i < a.size(); i++) {
        if (a[i] == a[i - 1]) { 
            continue; // Ignore duplicates
        } 
        else if (a[i] == a[i - 1] + 1) {
            count++; // Increment count if consecutive
        } 
        else {
            longest = max(longest, count); // Update longest
            count = 1; // Reset count for new sequence
        }
    }
    return max(longest, count); // Final check
}

int main() {
    vector<int> a = {15, 13, 12, 14, 11, 10, 9};
    
    cout << "Longest consecutive subsequence length: " << longestSubsequence(a) << endl;

    return 0;
}
