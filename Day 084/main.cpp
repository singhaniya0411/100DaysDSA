/*
    Title: K-th Smallest Element in Binary 

    Problem Statement:
        - Given the root of a Binary Search Tree (BST) and an integer k,
          return the k-th smallest element in the BST.
        - BST is defined as a binary tree in which for each node:
            - left subtree contains nodes with values less than the node's value.
            - right subtree contains nodes with values greater than the node's value.

    Approach:
        - Perform an inorder traversal (which gives sorted order in BST).
        - Keep a counter while traversing.
        - Return the value of the k-th visited node.

    Time Complexity:
        - O(n) in worst case, where n is number of nodes (if unbalanced).

    Space Complexity:
        - O(h), where h is the height of the tree (recursive stack).

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

// Helper function to find k-th smallest element
int kthSmallestRec(Tree* root, int k, vector<int>& count) {
    if (root == NULL) return -1;

    int left = kthSmallestRec(root->left, k, count);
    if (left != -1) return left;

    count[0]++;
    if (count[0] == k) return root->data;

    return kthSmallestRec(root->right, k, count);
}

// Wrapper function
int kthSmallest(Tree* root, int k) {
    vector<int> count = {0};  // count[0] keeps track of number of visited nodes
    return kthSmallestRec(root, k, count);
}

// Inorder traversal for reference
void inorder(Tree* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    // Create a valid BST
    Tree* root = new Tree(5);
    root->left = new Tree(3);
    root->right = new Tree(7);
    root->left->left = new Tree(2);
    root->left->right = new Tree(4);
    root->right->left = new Tree(6);
    root->right->right = new Tree(8);

    cout << "Inorder Traversal (Sorted): ";
    inorder(root);
    cout << endl;

    int k = 3;
    int result = kthSmallest(root, k);
    cout << "The " << k << "-th smallest element is: " << result << endl;

    return 0;
}
