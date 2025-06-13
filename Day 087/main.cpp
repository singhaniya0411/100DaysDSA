/*
    Title: Morris Inorder Traversal of Binary Tree
    

    Problem Statement:
        - Traverse a binary tree in inorder without using recursion or stack.

    Approach:
        - Use Morris Traversal:
            1. If the current node has no left child → print it and move to right.
            2. Else:
                a. Find the inorder predecessor (rightmost node in left subtree).
                b. If predecessor's right is NULL → make it point to current (thread), move left.
                c. If predecessor’s right is current → break the thread, print current, move right.

    Time Complexity:
        - O(n), where n is number of nodes.

    Space Complexity:
        - O(1), no extra space used (excluding result vector).

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

// Find rightmost node in left subtree (inorder predecessor)
Tree* findPredecessor(Tree* root) {
    Tree* curr = root->left;
    while (curr->right && curr->right != root) {
        curr = curr->right;
    }
    return curr;
}

// Morris Inorder Traversal
vector<int> morrisTraversal(Tree* root) {
    vector<int> res;
    Tree* curr = root;

    while (curr) {
        if (curr->left == NULL) {
            res.push_back(curr->data);
            curr = curr->right;
        } else {
            Tree* pred = findPredecessor(curr);

            if (pred->right == NULL) {
                pred->right = curr;  // Create thread
                curr = curr->left;
            } else {
                pred->right = NULL;  // Remove thread
                res.push_back(curr->data);
                curr = curr->right;
            }
        }
    }

    return res;
}

int main() {
    // Manual binary tree
    Tree* root = new Tree(1);
    root->left = new Tree(2);
    root->right = new Tree(3);
    root->left->left = new Tree(4);
    root->left->right = new Tree(5);
    root->right->left = new Tree(6);
    root->right->right = new Tree(7);

    // Morris traversal
    vector<int> inorderResult = morrisTraversal(root);

    cout << "Morris Inorder Traversal: ";
    for (int val : inorderResult) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
