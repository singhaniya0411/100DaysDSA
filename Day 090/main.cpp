/*
    Title: Check if there exists a Pair with Given Sum in a Binary Search Tree
    
    Problem Statement:
        - Given a Binary Search Tree and a target value,
          check whether there exists a pair of nodes whose sum equals the target.
          
    Approach:
        - Perform inorder traversal to get a sorted array of node values.
        - Use two-pointer technique on the sorted array to check for the target sum.

    Time Complexity:
        - O(n), where n is the number of nodes in the BST (due to traversal + 2-pointer scan).

    Space Complexity:
        - O(n), for storing the inorder traversal result.

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

// Inorder traversal to fill sorted values
void inorder(Tree* root, vector<int> &res) {
    if (root == NULL) return;
    inorder(root->left, res);
    res.push_back(root->data);
    inorder(root->right, res);
}

// Check if pair with given sum exists using two-pointer approach
bool pairSum(Tree* root, int target) {
    vector<int> traversal;
    inorder(root, traversal);

    int l = 0;
    int r = traversal.size() - 1;

    while (l < r) {
        int sum = traversal[l] + traversal[r];
        if (sum == target) return true;
        else if (sum < target) l++;
        else r--;
    }
    return false;
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

    int target = 40;

    if (pairSum(root, target)) {
        cout << "A pair with sum " << target << " exists in the BST." << endl;
    } else {
        cout << "No such pair with sum " << target << " found in the BST." << endl;
    }

    return 0;
}
