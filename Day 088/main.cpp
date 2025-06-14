/*
    Title: Boundary Traversal of Binary Tree

    Problem Statement:
        - Given a binary tree, perform a boundary traversal in anti-clockwise direction.
        - The boundary includes:
            1. The root (if not a leaf),
            2. The left boundary (excluding leaves),
            3. All the leaf nodes (from left to right),
            4. The right boundary (excluding leaves, printed bottom-up).

    Approach:
        - Add root (if not a leaf).
        - Traverse the left boundary without including leaf nodes.
        - Traverse all leaf nodes (both left and right subtrees).
        - Traverse the right boundary in reverse order (excluding leaf nodes).
    Time Complexity:
        - O(n), where n is the number of nodes in the tree.

    Space Complexity:
        - O(h), where h is the height of the tree (for recursion on leaves).

    Author: Vishal Singhaniya
*/


#include <iostream>
#include <vector>
using namespace std;

// Tree Node Definition
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

// Check if node is leaf
bool isleaf(Tree* root) {
    return (root->left == NULL && root->right == NULL);
}

// Collect left boundary (excluding leaf nodes)
void collectBoundaryLeft(Tree* root, vector<int>& res) {
    while (root) {
        if (!isleaf(root)) res.push_back(root->data);
        if (root->left) root = root->left;
        else root = root->right;
    }
}

// Collect right boundary in reverse order (excluding leaf nodes)
void collectBoundaryRight(Tree* root, vector<int>& res) {
    vector<int> temp;
    while (root) {
        if (!isleaf(root)) temp.push_back(root->data);
        if (root->right) root = root->right;
        else root = root->left;
    }
    // Append in reverse order
    for (int i = temp.size() - 1; i >= 0; --i) {
        res.push_back(temp[i]);
    }
}

// Collect all leaf nodes
void collectLeaves(Tree* root, vector<int>& res) {
    if (root == NULL) return;
    if (isleaf(root)) {
        res.push_back(root->data);
    } else {
        collectLeaves(root->left, res);
        collectLeaves(root->right, res);
    }
}

// Boundary Traversal
vector<int> boundaryTraversal(Tree* root) {
    vector<int> res;
    if (root == NULL) return res;

    if (!isleaf(root)) res.push_back(root->data);

    collectBoundaryLeft(root->left, res);
    collectLeaves(root, res);
    collectBoundaryRight(root->right, res);

    return res;
}

// Main function
int main() {
    // Sample binary tree:
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    vector<int> result = boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
