/*
    Title: Flatten a Linked List

    Problem Statement:
        - You are given a linked list where each node has:
            1) a `next` pointer (to the right)
            2) a `bottom` pointer (downwards)
        - Each vertical (bottom) linked list is already sorted.
        - The task is to flatten the entire structure into a single sorted list
          using only the `bottom` pointer (and ignore `next` in the final list).

    Node Structure:
        struct Node {
            int data;
            Node* next;
            Node* bottom;
        };

    Approach (Min Heap / Priority Queue):
        1. Use a min heap (priority_queue with custom comparator) to always get
           the smallest available node.
        2. Push all head nodes of each vertical list (connected through `next`)
           into the priority queue.
        3. Repeat until the heap is empty:
            - Pop the smallest node (minNode).
            - Add it to the result list using the `bottom` pointer.
            - If minNode->bottom exists, push that bottom node into the heap.
            - Set minNode->bottom = nullptr to avoid old links.
        4. The `head` of the final flattened list is returned.

    Example:
        Input List:
            5 -> 10 -> 19 -> 28
            |    |     |     |
            7    20    22    35
            |          |     |
            8          50    40
            |
            30

        Output:
            5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22
                -> 28 -> 30 -> 35 -> 40 -> 50 (using bottom pointers only)

    Dry Run (Brief):
        - Insert 5, 10, 19, 28 into min heap.
        - Pop 5 → push 7
        - Pop 7 → push 8
        - Pop 8 → push 30
        - Pop 10 → push 20
        - Continue until heap is empty...
        - Final list is sorted in increasing order.

    Time Complexity:
        - Let total number of nodes be N.
        - Each node is inserted and removed from the heap once.
        - Heap operations cost O(log K),
          where K is the number of vertical lists (initial top nodes).
        - Overall Time Complexity: O(N log K)

    Space Complexity:
        - O(K) for the priority queue (in worst case)
        - No extra linked list is created (in-place linking)

    Author: Vishal Singhaniya
*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

struct mycomp {
    bool operator()(Node* a, Node* b){
        return a->data > b->data;   // Min heap
    }
};

Node *flatten(Node *root) {
    priority_queue<Node*, vector<Node*>, mycomp> pq;

    Node* head = NULL;
    Node* tail = NULL;

    // Push all top-level nodes into pq
    while(root != NULL){
        pq.push(root);
        root = root->next;
    }

    while(!pq.empty()){
        Node* minNode = pq.top();
        pq.pop();

        if(head == NULL){
            head = minNode;
            tail = minNode;
        } else {
            tail->bottom = minNode;
            tail = tail->bottom;
        }

        if(minNode->bottom){
            pq.push(minNode->bottom);
            minNode->bottom = NULL;
        }
    }

    return head;
}

// Function to print bottom-linked list
void printList(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main(){
    /*
    Making this 2D list:

    5 -> 10 -> 19 -> 28
    |     |     |     |
    7     20    22    35
    |           |     |
    8           50    40
    |                 |
    30                45
    */

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(35);
    head->next->next->next->bottom->bottom = new Node(40);
    head->next->next->next->bottom->bottom->bottom = new Node(45);

    cout << "Flattened list: ";
    Node* flat = flatten(head);
    printList(flat);

    return 0;
}







