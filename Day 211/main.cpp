/*
    Title: Balance a Binary Search Tree/

    Problem Statement:
        - Given the root of a (possibly unbalanced) binary search tree (BST),
          transform it into a height-balanced BST containing the same node values.
        - A height-balanced BST is defined as a binary tree in which the depth
          of the two subtrees of every node never differ by more than 1.

    Approach:
        1. Do an inorder traversal of the original BST to collect the node values
           in a sorted vector `nodes`.
        2. Build a balanced BST from the sorted vector by recursively choosing
           the middle element as the root for every subarray:
               - mid = (start + end) / 2
               - left subtree  = buildBalancedBST(nodes, start, mid-1)
               - right subtree = buildBalancedBST(nodes, mid+1, end)
        3. This produces a height-balanced BST with the same values.

    Time Complexity:
        - O(N), to collect inorder + O(N) to construct the balanced tree -> overall O(N).

    Space Complexity:
        - O(N) for the vector storing inorder nodes + O(H) recursion stack (H ~ logN for balanced tree).

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};

void storeInorder(Node* root, vector<int>& inorder) {
    if (root == nullptr) return;
    storeInorder(root->left, inorder);
    inorder.push_back(root->data);
    storeInorder(root->right, inorder);
}

Node* buildBalancedBST(const vector<int>& nodes, int start, int end) {
    if (start > end) return nullptr;
    int mid = start + (end - start) / 2;
    Node* root = new Node(nodes[mid]);
    root->left  = buildBalancedBST(nodes, start, mid - 1);
    root->right = buildBalancedBST(nodes, mid + 1, end);
    return root;
}

Node* balanceBST(Node* root) {
    vector<int> nodes;
    storeInorder(root, nodes);                // nodes is sorted because input is BST
    return buildBalancedBST(nodes, 0, (int)nodes.size() - 1);
}

void printLevelOrder(Node *root) {
    if (root == nullptr) {
        cout << "N ";
        return;
    }

    queue<Node *> qq;
    qq.push(root);
    int nonNull = 1;

    while (!qq.empty() && nonNull > 0) {
        Node *curr = qq.front();
        qq.pop();

        if (curr == nullptr) {
            cout << "N ";
            continue;
        }
         nonNull--;

        cout << (curr->data) << " ";
        qq.push(curr->left);
        qq.push(curr->right);
        if (curr->left)
            nonNull++;
        if (curr->right)
            nonNull++;
    }
}

int main() {
    // Build an unbalanced BST (skewed)
    Node* root = new Node(4);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->left->left = new Node(1);
    root->right = new Node(5);
    root->right->right = new Node(6);
    root->right->right->right = new Node(7);

    cout << "Level order traversal of original (unbalanced) BST: ";

    printLevelOrder(root);
    cout << "\n";
    
    Node* balancedRoot = balanceBST(root);

    cout << "Level order traversal of balanced BST: ";
    printLevelOrder(balancedRoot);
    cout << "\n";

    return 0;
}

















