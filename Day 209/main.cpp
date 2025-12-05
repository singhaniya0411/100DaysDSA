/*
    Title: Check if a Binary Tree is Symmetric (Iterative Ap

    Problem Statement:
        - You are given the root of a binary tree.
        - A binary tree is symmetric if its left subtree is a mirror image of its right subtree.
        - Determine whether the given binary tree is symmetric.

    Approach (Using Two Stacks):
        1. If root is NULL → symmetric.
        2. Use two stacks:
                s1 → traverse left subtree
                s2 → traverse right subtree
        3. Compare nodes in mirror order:
                - node1->left  vs node2->right
                - node1->right vs node2->left
        4. Any mismatch → return false.
        5. If traversal ends without mismatch → return true.

    Example:
            Input Tree:
                      1
                   /     \
                  2       2
                /  \    /  \
               3    4  4    3

            Output: true

    Time Complexity:
        - O(N)

    Space Complexity:
        - O(H), where H is tree height

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

bool isSymmetric(Node* root) {

    if(root == nullptr){
        return true;
    }
        
    stack<Node*> s1, s2;
    s1.push(root->left);
    s2.push(root->right);
        
    while(!s1.empty() && !s2.empty()){
        Node* node1 = s1.top();
        Node* node2 = s2.top();
        s1.pop();
        s2.pop();
            
        if(node1 == nullptr && node2 == nullptr){
            continue;
        }
            
        if(node1 == nullptr || node2 == nullptr || node1->data != node2->data){
            return false;
        }
            
        s1.push(node1->left);
        s2.push(node2->right);
            
        s1.push(node1->right);
        s2.push(node2->left);
    }
        
    return s1.empty() && s2.empty();
}

int main() {

    /*
        Constructing symmetric tree:
        
                1
              /   \
             2     2
            / \   / \
           3   4 4   3
    */

    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(2);

    root->left->left = new Node(3);
    root->left->right = new Node(4);

    root->right->left = new Node(4);
    root->right->right = new Node(3);

    if(isSymmetric(root)){
        cout << "The tree is symmetric.\n";
    } else {
        cout << "The tree is NOT symmetric.\n";
    }

    return 0;
}


