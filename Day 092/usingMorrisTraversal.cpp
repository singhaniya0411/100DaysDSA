/*
    Title: Validate if a Binary Tree is a Binary Search Tree (BST) using Morris Traversal

    Problem Statement:
        - Given a binary tree, determine whether it is a valid Binary Search Tree (BST).
        - A BST is defined as a binary tree in which:
            - The left subtree of a node contains only nodes with values less than the node's value.
            - The right subtree of a node contains only nodes with values greater than the node's value.
            - Both the left and right subtrees must also be BSTs.
            
            
    Approach:
        - Use Morris Inorder Traversal (O(1) space).
        - During traversal, check if current node's value is greater than the previous visited node's value.

    Time Complexity:
        - O(n), where n is the number of nodes in the tree.

    Space Complexity:
        - O(1), Morris traversal uses constant space (no recursion, no stack)

    Author: Vishal Singhaniya
*/

#include <iostream>
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

// Helper function to find inorder predecessor
Tree* findPredecessor(Tree* root) {
    Tree* curr = root->left;
    while (curr->right && curr->right != root) {
        curr = curr->right;
    }
    return curr;
}

// BST validation using Morris Inorder Traversal
bool isValidBST(Tree* root) {
    Tree* curr = root;
    Tree* prev = NULL;

    while (curr) {
        if (curr->left) {
            Tree* predecessor = findPredecessor(curr);

            if (predecessor->right == NULL) {
                predecessor->right = curr;
                curr = curr->left;
            } else {
                predecessor->right = NULL;

                if (prev && curr->data <= prev->data) return false;
                prev = curr;

                curr = curr->right;
            }
        } else {
            if (prev && curr->data <= prev->data) return false;
            prev = curr;
            curr = curr->right;
        }
    }

    return true;
}

// Main
int main() {
    // Create a sample tree
    Tree* root = new Tree(10);
    root->left = new Tree(5);
    root->right = new Tree(15);
    root->left->left = new Tree(3);
    root->left->right = new Tree(7);
    root->right->left = new Tree(12);
    root->right->right = new Tree(18);

    if (isValidBST(root)) {
        cout << "The given binary tree is a valid BST." << endl;
    } else {
        cout << "The given binary tree is NOT a valid BST." << endl;
    }

    return 0;
}
