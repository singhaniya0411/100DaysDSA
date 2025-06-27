/*
    Title: Fixing Two Swapped Nodes in a Binary Search Tree (BST)

    Problem Statement:
        - Given the root of a BST where exactly two nodes have been swapped by mistake
          fix the tree by swapping them back.
        - Do not change the structure of the tree.

    Approach:
        - Perform inorder traversal of the BST (should give a sorted sequence).
        - Detect where the order is violated.
        - There are two cases:
            1. Non-adjacent nodes are swapped (e.g., 1-4-3-2-5 → 1-[4-3]-[2]-5).
            2. Adjacent nodes are swapped (e.g., 1-2-5-4-6 → 1-2-[5-4]-6).
        - Track:
            - First node where violation occurs
            - Middle node (next to first)
            - Last node (if violation occurs again)
        - Swap the first and last OR first and middle depending on the case.

    Time Complexity:
        - O(n), where n is the number of nodes in the tree.

    Space Complexity:
        - O(h), where h is the height of the tree (due to recursion stack).

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

void inorder(Tree* root, Tree*& first, Tree*& middle, Tree*& last, Tree*& prev) {
    if (!root) return;

    inorder(root->left, first, middle, last, prev);

    if (prev && root->data < prev->data) {
        if (!first) {
            first = prev;
            middle = root;
        } else {
            last = root;
        }
    }

    prev = root;

    inorder(root->right, first, middle, last, prev);
}

void recoverTree(Tree* root) {
    Tree* first = NULL;
    Tree* middle = NULL;
    Tree* last = NULL;
    Tree* prev = NULL;

    inorder(root, first, middle, last, prev);

    if (first && last) {
        swap(first->data, last->data);
    } else if (first && middle) {
        swap(first->data, middle->data);
    }
}

void printInorder(Tree* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
// Main
int main() {
    /*
        Construct the following BST with two nodes swapped:
                  6
                 / \
                10  2
               / \  / \
              1  3 7  12

        Swap 10 and 2 to violate BST
    */
    Tree* root = new Tree(6);
    root->left = new Tree(10);
    root->right = new Tree(2);
    root->left->left = new Tree(1);
    root->left->right = new Tree(3);
    root->right->left = new Tree(7);
    root->right->right = new Tree(12);

    cout << "Before Fixing (Inorder): ";
    printInorder(root);
    cout << endl;

    recoverTree(root);

    cout << "After Fixing (Inorder): ";
    printInorder(root);
    cout << endl;

    return 0;
}
