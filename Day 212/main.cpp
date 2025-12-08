/*
    Title: Count Nodes in a BST Within a Given Range [L, H].

    Problem Statement:
        - You are given the root of a Binary Search Tree (BST) and two integers L and H.
        - Your task is to count how many nodes in the BST have values within the range:
                     L ≤ node->data ≤ H
        - The BST property allows us to skip unnecessary subtrees and improve efficiency.

    Approach:
        1. If the current node is NULL → return 0.
        2. If node->data lies within [L, H]:
               - Count this node → 1
               - Recursively count nodes in left and right subtrees.
        3. If node->data < L:
               - Only right subtree may contain values ≥ L.
        4. If node->data > H:
               - Only left subtree may contain values ≤ H.
        5. Return the accumulated count.

    Example:
        Input BST (in-order):
            [5, 7, 10, 15, 20, 25, 30]

        Range:
            L = 7, H = 20

        Valid nodes:
            7, 10, 15, 20

        Output:
            4

    Dry Run:
        Node = 15 → in range → count = 1
        Left subtree (10, 7) → both in range → +2
        Right subtree (20, 25):
            20 in range → +1
            25 > H → skip right subtree
        Final count = 4

    Time Complexity:
        - O(H), where H = height of the BST
        - Worst case (skewed tree): O(N)
        - Best case (balanced tree): O(log N)

    Space Complexity:
        - O(H) recursion depth

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
        data = val;
        left = nullptr;
        right = nullptr;
    }
};


int getCount(Node* root, int l, int h){
    if(root == nullptr){
        return 0;
    }
    
    if(root->data >= l && root->data <=h){
        return 1+ getCount(root->left,l,h) + getCount(root->right,l,h);
    }
    
    else if(root->data > h){
        return getCount(root->left,l,h);
    }
    else{
        return getCount(root->right,l,h);
    }
}

int main(){
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(50);
    root->left->left = new Node(1);
    root->right->left = new Node(40);
    root->right->right = new Node(100);
    
    int l = 5;
    int h = 45;
    
    int countNode = getCount(root, l,h);
    cout<<"Number of node lies in range ("<<l<<" , "<<h<<") : ";
    cout<<countNode<<"\n";
    return 0;

}


