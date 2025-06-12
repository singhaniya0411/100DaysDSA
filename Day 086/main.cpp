/*
    Title: Building Tree from Preorder and Inorder Traversal, and Printing Postorder Traversal


    Problem Statement:
        - Given two arrays representing the preorder and inorder traversal of a binary tree,
          build the binary tree and print its postorder traversal.

    Approach:
        - Use recursion to build the tree.
        - The first element in preorder is the root.
        - Use a map to quickly locate the root in inorder traversal and split it into left and right subtrees.

    Time Complexity:
        - O(n), where n is the number of nodes in the tree.

    Space Complexity:
        - O(h), where h is the height of the tree (due to recursion stack).

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<vector>
#include<unordered_map>
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

// Recursive function to build the tree
Tree* buildTreeRec(int l, int h, const vector<int>& preorder, unordered_map<int, int>& mp, vector<int>& index) {
    if (l > h) return NULL;

    int value = preorder[index[0]];
    Tree* root = new Tree(value);
    index[0]++;

    int inIndex = mp[value];
    root->left = buildTreeRec(l, inIndex - 1, preorder, mp, index);
    root->right = buildTreeRec(inIndex + 1, h, preorder, mp, index);

    return root;
}

// Wrapper function
Tree* buildTree(const vector<int>& inorder, const vector<int>& preorder) {
    unordered_map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++) {
        mp[inorder[i]] = i;
    }
    vector<int> index = {0};
    return buildTreeRec(0, inorder.size() - 1, preorder, mp, index);
}

// Postorder Traversal
void postorder(Tree* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main() {
    vector<int> inorder   = {4, 2, 5, 1, 6, 3, 7};
    vector<int> preorder  = {1, 2, 4, 5, 3, 6, 7};

    Tree* root = buildTree(inorder, preorder);

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
