/*
    Title: Check if a Binary Tree is Height Balanced (Optimized Approac

    Problem Statement:
        - You are given the root of a binary tree.
        - A binary tree is considered *height-balanced* if:
                For every node, the absolute difference between the height 
                of its left and right subtree is NOT more than 1.
        - Determine whether the given binary tree is height-balanced.

    Approach:
        1. Use a recursive helper function `isBalancedRec()`:
            - Returns height of subtree if balanced.
            - Returns -1 if subtree is NOT balanced.
        2. For each node:
            - Compute left height and right height.
            - If either subtree is unbalanced or height difference > 1 → return -1.
            - Otherwise return 1 + max(left height, right height).
        3. `isBalanced()` returns true if recursive result is NOT -1.

    Example:
            Constructed Tree:
                        10
                      /    \
                    20      30
                  /    \
                40      60

        - All height differences are within 1.
        - Output → "The tree is balanced"

    Dry Run:
        - Check subtree rooted at 40 → height = 1
        - Check subtree rooted at 60 → height = 1
        - Node 20 → left=1, right=1 → height=2
        - Node 30 → height=1
        - Node 10 → left=2, right=1 → balanced → height=3

    Time Complexity:
        - O(N), where N = number of nodes.

    Space Complexity:
        - O(H), where H = height of the tree (due to recursion stack).

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    
    Node(int x){
        val = x;
        left = right = nullptr;
    }
};


int isBalancedRec(Node* root){
    if(root == nullptr){
        return 0;
    }
    
    int lHeight = isBalancedRec(root->left);
    int rHeight = isBalancedRec(root->right);
    
    if(lHeight==-1 || rHeight == -1 ||  abs(lHeight-rHeight)>1){
        return -1;
    }
    return max(lHeight , rHeight) + 1;
}

bool isBalanced(Node* root){
    return isBalancedRec(root)>0;
}


int main(){
    
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    cout << (isBalanced(root) ? "The tree is balanced\n" : "The tree is not balanced\n");
    
    
    return 0;
}
