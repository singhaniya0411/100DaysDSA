/*
    Title: Count Paths in Binary Tree with Given Sum
    
    Problem Statement:
        - Given a binary tree and an integer k,
          count all paths that sum to k.
        - The path does not need to start or end at the root or a leaf,
          but it must go **downward** (parent to child).

    Approach:
        - Use recursion and prefix sum + hash map to track number of ways
          to reach a prefix sum = (current sum - k).
        - Traverse the tree while keeping track of current sum and updating the hash map.


    Time Complexity:
        - O(n), where n is the number of nodes in the tree.

    Space Complexity:
        - O(h) for recursion stack + O(n) for hash map.

    Author: Vishal Singhaniya
*/


#include <iostream>
#include <vector>
#include <unordered_map>
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

// Helper recursive function to count path sums
void countPathSumRec(Tree* root, int k, int& res, unordered_map<int, int>& mp, int currSum) {
    if (root == NULL) return;

    currSum += root->data;

    if (currSum == k) res++;

    if (mp.find(currSum - k) != mp.end()) {
        res += mp[currSum - k];
    }

    mp[currSum]++;

    countPathSumRec(root->left, k, res, mp, currSum);
    countPathSumRec(root->right, k, res, mp, currSum);

    mp[currSum]--; // backtrack
}

// Main function to call
int countPathSum(Tree* root, int k) {
    unordered_map<int, int> mp;
    int res = 0;
    countPathSumRec(root, k, res, mp, 0);
    return res;
}

// Main
int main() {
    // Sample Binary Tree:
    Tree* root = new Tree(10);
    root->left = new Tree(5);
    root->right = new Tree(-3);
    root->left->left = new Tree(3);
    root->left->right = new Tree(2);
    root->right->right = new Tree(11);
    root->left->left->left = new Tree(3);
    root->left->left->right = new Tree(-2);
    root->left->right->right = new Tree(1);

    int target = 8;
    int totalPaths = countPathSum(root, target);

    cout << "Number of paths with sum " << target << ": " << totalPaths << endl;

    return 0;
}
