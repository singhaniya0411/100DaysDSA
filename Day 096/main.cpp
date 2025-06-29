/*
    Title: Merge Two Sorted Linked Lists
    
    Problem Statement:
        - Given the heads of two sorted singly linked lists, merge them into one sorted linked list.
        - The merged linked list should be made by splicing together the nodes of the given lists.

    Approach:
        - Use a dummy node to ease the merging process.
        - Compare the data of the current nodes in both lists.
        - Append the smaller node to the merged list and advance the corresponding pointer.
        - Continue until one list is exhausted, then attach the remaining nodes of the other list.

    Time Complexity:
        - O(n + m), where n and m are the lengths of the two input linked lists.

    Space Complexity:
        - O(1), since the merge is done in-place without using extra memory (besides the dummy node).

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Linked List Node Definition
class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

// Merge two sorted linked lists
node* mergeSortedList(node* head1, node* head2) {
    node* dummy = new node(-1);
    node* curr = dummy;

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    // Attach remaining nodes
    if (head1) curr->next = head1;
    if (head2) curr->next = head2;

    return dummy->next;
}

// Print linked list
void print(node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Main function
int main() {
    node* h1 = new node(1);
    h1->next = new node(3);
    h1->next->next = new node(6);
    h1->next->next->next = new node(7);

    node* h2 = new node(2);
    h2->next = new node(4);
    h2->next->next = new node(5);

    cout << "List 1: ";
    print(h1);
    cout << "List 2: ";
    print(h2);

    node* merged = mergeSortedList(h1, h2);
    cout << "Merged List: ";
    print(merged);

    return 0;
}
