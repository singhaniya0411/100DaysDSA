/*
    Title: Maximum Path Sum in Binary Tree

    Problem Statement:
        - Given the root of a binary tree, find the maximum path sum.
        - A path is defined as any sequence of nodes from some starting node to any node 
          in the tree along the parent-child connections.
        - The path must contain at least one node and does not need to go through the root.

    Approach:
        - Use post-order DFS recursion.
        - For each node, calculate the maximum gain from left and right subtrees.
        - Update the global maximum if the path through current node is greater than the current max.

    Time Complexity:
        - O(n), where n is the number of nodes in the tree.

    Space Complexity:
        - O(h), where h is the height of the tree (due to recursion stack).

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<vector>
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

// Recursive helper function
int findMaxSumRec(Tree* root, vector<int>& res) {
    if (root == NULL) return 0;

    int l = max(0, findMaxSumRec(root->left, res));   // Ignore negative paths
    int r = max(0, findMaxSumRec(root->right, res));

    // Update maximum path sum including current node
    res[0] = max(res[0], l + r + root->data);

    // Return max gain if continuing the path through this node
    return max(l, r) + root->data;
}

// Wrapper function
int findMaxSum(Tree* root) {
    if (root == NULL) return 0;
    vector<int> res = {root->data}; // Initialize with root data to handle all-negative trees
    findMaxSumRec(root, res);
    return res[0];
}

// Inorder traversal for reference
void inorder(Tree* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Create a binary tree (not necessarily BST)
    Tree* root = new Tree(5);
    root->left = new Tree(3);
    root->right = new Tree(7);
    root->left->left = new Tree(7);
    root->left->right = new Tree(4);
    root->right->left = new Tree(6);
    root->right->right = new Tree(8);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    int maxPathSum = findMaxSum(root);
    cout << "Maximum Path Sum in Binary Tree: " << maxPathSum << endl;

    return 0;
}
