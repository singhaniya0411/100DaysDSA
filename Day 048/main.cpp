/*
    Title: Group Anagrams Using Hashing

    Problem Statement:
        - Given an array of strings, group the anagrams together.

    Optimized Approach:
        - Use an **unordered_map<string, vector<string>>**:
            - Sort each string alphabetically to create a unique key.
            - Store the original string in a vector mapped to this sorted key.
        - Extract all grouped anagrams from the map into a result vector.

    Time Complexity:
        - **O(n * m log m)** (where n = number of strings, m = average string length)
        - Sorting each string takes **O(m log m)**, and inserting into a map is **O(1)**.

    Space Complexity:
        - **O(n * m)** (For storing strings in the hash map)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Function to group anagrams together
vector<vector<string>> groupAnagram(vector<string>& arr) {
    unordered_map<string, vector<string>> mp;

    for (string s : arr) {
        string sorted_s = s;
        sort(sorted_s.begin(), sorted_s.end()); // Sort characters in the string
        mp[sorted_s].push_back(s); // Group anagrams under the same key
    }

    vector<vector<string>> res;
    for (auto& p : mp) {
        res.push_back(p.second);
    }
    
    return res;
}

// Function to print grouped anagrams
void printAnagram(const vector<vector<string>>& groups) {
    for (const auto& group : groups) {
        cout << "[ ";
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }
}

int main() {
    vector<string> words = {"cat", "dog", "god", "tac", "act", "ten", "net"};

    vector<vector<string>> groupedAnagrams = groupAnagram(words);
    cout << "Grouped Anagrams: \n";
    printAnagram(groupedAnagrams);

    return 0;
}
