/*
    Title: Serialize and Deserialize a Binary Tree

    Problem Statement:
        - Serialize a binary tree into a linear format using preorder traversal.
        - Deserialize the linear format back into the original binary tree.
        - Use `-1` to represent NULL nodes in the serialization.

    Approach:
        - Serialize using recursive preorder traversal.
        - Deserialize recursively by tracking index using a reference.

    Time Complexity:
        - O(n), where n is the number of nodes in the tree.

    Space Complexity:
        - O(n) for storing the serialized array (and recursion stack during deserialization).

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

// Serialize - Preorder Traversal with -1 as NULL marker
void preorder(Tree* root, vector<int>& arr) {
    if (root == NULL) {
        arr.push_back(-1);
        return;
    }
    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

vector<int> serialize(Tree* root) {
    vector<int> arr;
    preorder(root, arr);
    return arr;
}

// Deserialize Helper Function
Tree* constructBT(const vector<int>& arr, int& index) {
    if (index >= arr.size() || arr[index] == -1) {
        index++;
        return NULL;
    }

    Tree* root = new Tree(arr[index++]);
    root->left = constructBT(arr, index);
    root->right = constructBT(arr, index);
    return root;
}

Tree* deSerialize(const vector<int>& arr) {
    int index = 0;
    return constructBT(arr, index);
}



// Main
int main() {
    // Create a sample tree
    Tree* root = new Tree(10);
    root->left = new Tree(5);
    root->right = new Tree(15);
    root->left->left = new Tree(3);
    root->left->right = new Tree(7);
    root->right->left = new Tree(12);
    root->right->right = new Tree(18);

    // Serialize
    vector<int> serialized = serialize(root);
    cout << "Serialized Tree (Preorder): ";
    for (int val : serialized) cout << val << " ";
    cout << endl;

    // Deserialize
    Tree* newRoot = deSerialize(serialized);

    return 0;
}
