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



