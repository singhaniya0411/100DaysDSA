/*
    Title: Rotate a Singly Linked List by k Position.

    Problem Statement:
        - Create a singly linked list.
        - Implement functionality to rotate the list to the right by k places.
        - Print the list before and after rotation.
        
    Approach:
        - Count the number of nodes.
        - Use modular arithmetic to avoid full rotations.
        - Find new tail, update links accordingly.

    Time Complexity:
        - O(n), where n is the number of nodes.
    Space Complexity:
        - O(1), no extra space used.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert at head
void insertAthead(node*& head, int val) {
    node* newnode = new node(val);
    newnode->next = head;
    head = newnode;
}

// Count number of nodes
int countNodes(node* head) {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Rotate list to the right by k nodes
void rotateLinkedList(node*& head, int k) {
    if (!head || !head->next || k == 0)
        return;

    int n = countNodes(head);
    k = k % n;
    if (k == 0) return;

    node* temp = head;
    for (int i = 0; i < n - k; i++) {
        temp = temp->next;
    }

    node* newHead = temp->next;
    temp->next = NULL;

    node* tail = newHead;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = head;
    head = newHead;
}

// Print the linked list
void printList(node* list) {
    node* temp = list;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    node* l = NULL;

    insertAthead(l, 1);
    insertAthead(l, 7);
    insertAthead(l, 2);
    insertAthead(l, 3);
    insertAthead(l, 4);

    cout << "Original list: ";
    printList(l);

    int k = 8;
    rotateLinkedList(l, k);

    cout << "List after rotating by " << k << " positions: ";
    printList(l);

    return 0;
}
