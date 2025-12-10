/*
    Title: Vertical Order Traversal of a Binary Tree

    Problem Statement:
        - Given the root of a binary tree, return its vertical order traversal.
        - Nodes are grouped based on their horizontal distance (HD) from the root:
              HD(root) = 0
              Left child  → HD - 1
              Right child → HD + 1
        - The traversal must be level-order (BFS) so that nodes appearing earlier 
          in the tree appear earlier in their vertical group.

    Approach:
        1. Use BFS with a queue storing {node, horizontalDistance}.
        2. Maintain a map<int, vector<int>> to store values grouped by HD.
        3. Track the minimum and maximum HD encountered.
        4. For each popped node:
               - Append its value to lst[HD].
               - Push left child with HD - 1.
               - Push right child with HD + 1.
        5. After BFS completes, build the result from HD = mn → mx.

    Example:
            Tree:
                     1
                   /   \
                  2     3
                 / \   / \
                4   5 6   7

        Output:
            [
              {4},
              {2},
              {1, 5, 6},
              {3},
              {7}
            ]

    Dry Run:
        Queue sequence → (1,0), (2,-1), (3,1), (4,-2), (5,0), (6,0), (7,2)
        Result built HD-wise from -2 to +2.

    Time Complexity:
        - O(N), each node visited once.

    Space Complexity:
        - O(N) for queue + map storage.

    Applications:
        - Tree column visualization
        - Graph layout systems
        - Hierarchical clustering

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

vector<vector<int>> verticalOrder(Node *root) {
    if (!root) return {};

    unordered_map<int, vector<int>> lst;
    queue<pair<Node*, int>> q;

    q.push({root, 0});
    int mn = 0, mx = 0;

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* node = p.first;
        int hd = p.second;

        mn = min(mn, hd);
        mx = max(mx, hd);

        lst[hd].push_back(node->data);

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    vector<vector<int>> res;
    for (int i = mn; i <= mx; i++) {
        res.push_back(lst[i]);
    }

    return res;
}

int main() {
    /*
            Constructed Binary Tree:
                     1
                   /   \
                  2     3
                 / \   / \
                4   5 6   7
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<vector<int>> result = verticalOrder(root);

    cout << "Vertical Order Traversal:\n";
    for (auto &col : result) {
        cout << "[ ";
        for (int val : col)
            cout << val << " ";
        cout << "]\n";
    }

    return 0;
}








