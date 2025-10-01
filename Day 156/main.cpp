/*
    Title: Maximum XOR with Constraints (Using Trie)

    Problem Statement:
        - You are given an array of non-negative integers (arr).
        - You are also given a set of queries, where each query has two integers (x, m).
        - For each query:
            Find the maximum XOR value of 'x' with any element from 'arr' such that 
            the chosen element <= m.
        - If no such element exists, return -1 for that query.

    Approach (Binary Trie with Minimum Value Tracking):
        1. Build a Binary Trie (bitwise Trie) of all numbers in 'arr'.
        2. Each Trie node stores:
            - Two children (for bit 0 and bit 1).
            - The minimum value of all numbers in its subtree.
        3. For each query (x, m):
            - Traverse the Trie from MSB → LSB.
            - Prefer the opposite bit (to maximize XOR), but only if the 
              subtree has a value <= m.
            - Otherwise, go to the available bit path.
        4. Return the maximum XOR value found.

        Input:
            arr = {0, 1, 2, 3, 4}
            queries = {{3, 1}, {1, 3}, {5, 6}}
            
        Output:
            {3, 3, 7}

    Time Complexity:
        - Insert all numbers: O(N * log M), where M = max element.
        - Each query: O(log M).
        - Total: O((N + Q) * log M).

    Space Complexity:
        - O(N * log M) for the Trie structure.

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2]; // bit 0 and bit 1
    int min_val;           // store minimum value in subtree

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
        min_val = INT_MAX;
    }
};

TrieNode* root;

// Insert a number into Trie
void insert(int num) {
    TrieNode* node = root;
    node->min_val = min(node->min_val, num);

    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node->children[bit] == nullptr) {
            node->children[bit] = new TrieNode();
        }
        node = node->children[bit];
        node->min_val = min(node->min_val, num);
    }
}

// Find maximum XOR of x with numbers <= m
int findMaxXor(int x, int m) {
    TrieNode* node = root;
    if (node->min_val > m) return -1;

    int max_xor = 0;

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[2];
    int min_val;

    TrieNode() {
        children[0] = nullptr;
        children[1] = nullptr;
        min_val = INT_MAX;
    }
};

TrieNode* root;

void insert(int num) {
    TrieNode* node = root;
    node->min_val = min(node->min_val, num);

    for (int i = 31; i >= 0; i--) {
        int bit = (num >> i) & 1;
        if (node->children[bit] == nullptr) {
            node->children[bit] = new TrieNode();
        }
        node = node->children[bit];
        node->min_val = min(node->min_val, num);
    }
}

int finMaxXor(int x, int m) {
    TrieNode* node = root;
    if (node->min_val > m) {
        return -1;
    }

    int max_xor = 0;
    for (int i = 31; i >= 0; i--) {
        int bit = (x >> i) & 1;
        int desired_bit = 1 - bit;

        if (node->children[desired_bit] != nullptr &&
            node->children[desired_bit]->min_val <= m) {
            max_xor |= (1 << i);
            node = node->children[desired_bit];
        } else {
            node = node->children[bit];
        }
    }
    return max_xor;
}

vector<int> maxXor(vector<int> &arr, vector<vector<int>>& queries) {
    root = new TrieNode();
    for (int num : arr) {
        insert(num);
    }

    vector<int> result;
    for (auto &query : queries) {
        int x = query[0];
        int m = query[1];
        result.push_back(finMaxXor(x, m));
    }
    return result;
}

int main() {
    vector<int> arr = {0, 1, 2, 3, 4};
    vector<vector<int>> queries = {{3, 1}, {1, 3}, {5, 6}};

    vector<int> ans = maxXor(arr, queries);

    cout << "Maximum XOR results based on queries: ";  // ✅ fixed semicolon
    for (auto res : ans) {
        cout << res << "  ";
    }
    cout << endl;

    return 0;
}














