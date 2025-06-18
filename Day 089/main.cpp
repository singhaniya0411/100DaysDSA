/*
    Title: Lowest Common Ancestor (LCA) in a Binary Search Tree

    Problem Statement:
        - Given the root of a Binary Search Tree (BST) and two nodes n1 and n2,
          find their Lowest Common Ancestor (LCA).
        - The LCA of two nodes is the deepest node that has both n1 and n2 as descendants.

    Approach:
    
        - Start from the root and traverse the tree:
            - If both nodes are smaller than current node, move to the left.
            - If both nodes are greater than current node, move to the right.
            - Else, current node is the LCA.

    Time Complexity:
        - O(h), where h is the height of the BST.

    Space Complexity:
        - O(1) iterative approach (no recursion stack).

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

// Lowest Common Ancestor Function
Tree* LCA(Tree* root, Tree* n1, Tree* n2) {
    Tree* curr = root;

    while (curr) {
        if (curr->data > n1->data && curr->data > n2->data) {
            curr = curr->left;
        }
        else if (curr->data < n1->data && curr->data < n2->data) {
            curr = curr->right;
        }
        else {
            return curr;
        }
    }
    return NULL;
}

// Main function
int main() {
    // Creating a Binary Search Tree (BST)
    Tree* root = new Tree(20);
    root->left = new Tree(10);
    root->right = new Tree(30);
    root->left->left = new Tree(5);
    root->left->right = new Tree(15);
    root->right->left = new Tree(25);
    root->right->right = new Tree(35);

    Tree* n1 = root->left->left;   // Node 5
    Tree* n2 = root->right->right;  // Node 15

    Tree* ancestor = LCA(root, n1, n2);

    if (ancestor) {
        cout << "LCA of " << n1->data << " and " << n2->data << " is: " << ancestor->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}
