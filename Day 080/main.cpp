/*
    Title: Level Order Traversal of a Binary Tree

    Problem Statement:
        - Given a binary tree, print its nodes level by level (top to bottom, left to right).
        - Each level's nodes should be grouped together in a separate list.

    Approach:
        - Use a queue to perform Breadth-First Search (BFS).
        - For each level, store all nodes in a temporary vector.
        - Traverse children of all nodes at the current level and enqueue them for the next level.

    Time Complexity:
        - O(n) :  where n is the total number of nodes in the tree.

    Space Complexity:
        - O(n) :  for the queue used in BFS and the result storage.

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Define the Tree node class
class Tree {
public:
    int data;
    Tree* left;
    Tree* right;

    Tree(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Level-order traversal using queue
vector<vector<int>> levelOrder(Tree* root) {
    vector<vector<int>> res;
    if (!root) return res;

    queue<Tree*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> currLevel;

        for (int i = 0; i < size; ++i) {
            Tree* node = q.front();
            q.pop();

            currLevel.push_back(node->data);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        res.push_back(currLevel);
    }

    return res;
}

int main() {
    // Create a test binary tree
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    vector<vector<int>> result = levelOrder(root);

    // Output the level order traversal
    cout << "Level Order Traversal:\n";
    for (auto level : result) {
        cout << "[ ";
        for (int val : level) {
            cout << val << " ";
        }
        cout << "]\n";
    }

    return 0;
}
