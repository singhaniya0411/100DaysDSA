/*
    Title: Height of a Binary Tree

    Problem Statement:
        - Given a binary tree, compute its height.
        - Height is defined as the number of edges in the longest path from the root node to a leaf node.
        - For an empty tree, height is considered -1.

    Approach:
        - Use recursion to find the height of the left and right subtrees.
        - The height of the current node is 1 plus the maximum height of its left and right child.

    Time Complexity:
        - O(n), where n is the total number of nodes in the tree (each node is visited once).

    Space Complexity:
        - O(h), where h is the height of the tree due to recursive call stack.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
#include<queue>
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

// Height of Binary tree

int height(Tree* root){
    if(root==NULL){
        return -1;
    }
    int leftheight = height(root->left);
    int rightheight = height(root->right);
    
    return max(leftheight,rightheight) + 1;
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


    // Output the level order traversal
    cout << "Height of the Binary Tree "<<height(root);
    
    return 0;
}
