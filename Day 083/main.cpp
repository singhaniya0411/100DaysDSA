/*
    Title: Invert 

    Problem Statement:
        - Given the root of a binary tree, invert the tree.
        - Inversion means swapping the left and right children of all nodes in the tree.
        - For example, left and right subtrees should be recursively mirrored.

    Approach:
        - Use recursion to traverse the tree.
        - At each node, first recursively invert the left and right subtrees.
        - Then, swap the left and right child pointers.

    Time Complexity:
        - O(n), where n is the number of nodes in the binary tree (each node is visited once).

    Space Complexity:
        - O(h), where h is the height of the binary tree (due to the recursion stack).

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

// Function to invert the binary tree (mirror it)
Tree* invert(Tree* root) {
    if (root == NULL) {
        return NULL;
    }

    invert(root->left);
    invert(root->right);

    // Swap left and right
    Tree* temp = root->left;
    root->left = root->right;
    root->right = temp;

    return root;
}

// Helper function to print Inorder traversal (for verification)
void inorder(Tree* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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

    cout << "Inorder before inversion: ";
    inorder(root);
    cout << endl;

    invert(root);

    cout << "Inorder after inversion: ";
    inorder(root);
    cout << endl;

    return 0;
}
