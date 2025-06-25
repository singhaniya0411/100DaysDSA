/*
    Title: Validate if a Binary Tree is a Binary Search Tree (BST).

    Problem Statement:
        - Given a binary tree, determine whether it is a valid Binary Search Tree (BST).
        - A BST is defined as a binary tree in which:
            - The left subtree of a node contains only nodes with values less than the node's value.
            - The right subtree of a node contains only nodes with values greater than the node's value.
            - Both the left and right subtrees must also be BSTs.

    Approach:
        - Perform an inorder traversal of the tree and store values in a vector.
        - In a valid BST, the inorder traversal should produce a strictly increasing sequence.
        - Check if the vector is sorted in strictly increasing order.

    Time Complexity:
        - O(n), where n is the number of nodes in the tree.

    Space Complexity:
        - O(h) for recursion stack + O(n) for storing inorder traversal.

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

// Inorder Traversal
void inorder(Tree* root, vector<int>& res) {
    if (root == NULL) return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}

// Check if vector is strictly increasing
bool checkSortedArray(const vector<int>& res) {
    for (int i = 0; i < res.size() - 1; i++) {
        if (res[i] >= res[i + 1]) {
            return false;
        }
    }
    return true;
}

// Main BST validation function
bool isValidBST(Tree* root) {
    vector<int> result;
    inorder(root, result);
    return checkSortedArray(result);
}

// Main
int main() {
    // Sample Binary Tree (NOT a valid BST):
    Tree* root = new Tree(10);
    root->left = new Tree(5);
    root->right = new Tree(-3); // violates BST property
    root->left->left = new Tree(3);
    root->left->right = new Tree(2);
    root->right->right = new Tree(11);
    root->left->left->left = new Tree(3);
    root->left->left->right = new Tree(-2);
    root->left->right->right = new Tree(1);

    if (isValidBST(root)) {
        cout << "The given binary tree is a valid BST." << endl;
    } else {
        cout << "The given binary tree is NOT a valid BST." << endl;
    }

    return 0;
}
