/*
    Title: Minimum Vaccines for Binary Tree

    Problem Statement:
        - Given a binary tree, place the minimum number of "vaccines" on nodes such that
          every node is covered. A vaccine placed at a node covers the node itself,
          its parent, and its immediate children.

    Approach:
        - Use a DFS that returns one of three states for each node:
            0 -> node is not covered (needs vaccine from parent)
            1 -> node is covered (by a child) and has no vaccine
            2 -> node has a vaccine
        - Traverse post-order:
            • If any child returns 0 => place vaccine at current node (res++) and return 2.
            • Else if any child returns 2 => current node is covered -> return 1.
            • Else -> current node is not covered -> return 0.
        - After DFS for root, if root returns 0, increment the vaccine count.

    Time Complexity:
        - O(N), each node visited once

    Space Complexity:
        - O(H) recursion stack where H is tree height

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

// returns state: 0 = not covered, 1 = covered (no vaccine), 2 = has vaccine
int minVaccineUtil(Node* root, int &res) {
    if (!root) return 1; // null nodes considered covered

    int left = minVaccineUtil(root->left, res);
    int right = minVaccineUtil(root->right, res);

    // If any child is not covered -> place vaccine here
    if (left == 0 || right == 0) {
        res++;
        return 2; // has vaccine
    }

    // If any child has vaccine -> this node is covered
    if (left == 2 || right == 2) {
        return 1; // covered, no vaccine here
    }

    // Otherwise this node is not covered (needs parent to vaccinate)
    return 0;
}

int supplyVaccine(Node* root) {
    int res = 0;
    if (minVaccineUtil(root, res) == 0) {
        // root itself is not covered -> place vaccine at root
        res++;
    }
    return res;
}

int main() {
    /*
        Sample tree:
                 1
               /   \
              2     3
             / \     \
            4   5     6

        One optimal vaccine placement:
         - Place vaccine on node 2 (covers 4,5,2,1)
         - Place vaccine on node 6 (covers 6 and 3)
        => total vaccines = 2
    */

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->right = new Node(6);

    int vaccines = supplyVaccine(root);
    cout << "Minimum vaccines required: " << vaccines << "\n";

    // cleanup (optional for short-running programs)
    // (In production free all nodes; omitted here for brevity.)

    return 0;
}





