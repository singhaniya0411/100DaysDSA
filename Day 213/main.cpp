/*
    Title: Distribute Candies in a Binary Tree

    Problem Statement:
        - You are given a binary tree where each node contains an integer value.
        - Each value represents the number of candies at that node.
        - Every node must end up with exactly **one candy**.
        - In one move, you may transfer a candy to/from an adjacent node (parent or child).
        - The task is to compute the **minimum number of moves** required so that
          every node has exactly one candy.

    Approach:
        1. Use a post-order DFS traversal to process children before the parent.
        2. For each node:
             - Calculate how many candies its left subtree needs/has extra → `l`
             - Do the same for the right subtree → `r`
        3. Total moves are increased by `abs(l) + abs(r)` because:
             - Positive value → subtree has extra candies to give.
             - Negative value → subtree needs candies.
        4. Return the "net balance" to the parent:
               balance = root->data + l + r - 1
           This represents:
               +ve → extra candies
               -ve → required candies
        5. The accumulated `ans` becomes the final count of moves.

    Example:
        Tree:
                   5
                 /   \
                0     0
               /       \
              0         0

        Output:
            8 moves (for balancing all nodes to 1 candy each)

    Dry Run:
        - Each leaf with 0 → needs 1 candy → returns -1
        - Internal children accumulate deficits
        - Root with 5 distributes extra candies downward
        - Total moves = |l| + |r| at each node

    Time Complexity:
        - O(N), where N = number of nodes (each visited once).

    Space Complexity:
        - O(H), where H = tree height (recursion stack).

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;
  
  Node(int val){
      data=val;
      left=right=nullptr;
  }
  
};

int distCandyUtil(Node* root, int &ans){
    if(root==nullptr){
        return 0;
    }
    
    int l = distCandyUtil(root->left,ans);
    int r = distCandyUtil(root->right,ans);
    
    ans+= abs(l) + abs(r);
    
    return root->data + l+r-1;
}

int distCandy(Node* root){
    int ans = 0;
    distCandyUtil(root,ans);
    return ans;
}

int main(){
    Node* root = new Node(5);
    root->left = new Node(0);
    root->right = new Node(0);
    root->left->left = new Node(0);
    root->right->right = new Node(0);
    
    int steps = distCandy(root);
    cout<<"Step to distribute candies to all nodes : "<<steps<<"\n";
    return 0;
}
