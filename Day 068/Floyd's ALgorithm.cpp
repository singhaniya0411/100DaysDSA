/*
    Title: Detect Cycle in a Singly Linked List (Floyd’s Algorithm)
    
    Problem Statement:
        - Create a singly linked list.
        - Detect whether there is a cycle in the list.
        - Return true if a cycle exists, otherwise false.

    Approach:
        - Use Floyd’s Cycle Detection Algorithm (Tortoise and Hare).
        - Move two pointers (slow and fast) at different speeds.
        - If they meet at any point, a cycle exists.

    Time Complexity:
        - O(n), where n is the number of nodes.

    Space Complexity:
        - O(1), constant space used.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Definition of node
class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert a node at the head
void insertAthead(node*& head, int val) {
    node* newnode = new node(val);
    newnode->next = head;
    head = newnode;
}

// Detect cycle using Floyd’s Cycle Detection Algorithm
bool detectCycle(node*& head) {
    node* slow = head;
    node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return true;  // Cycle detected
        }
    }

    return false;  // No cycle found
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

// Driver code
int main() {
    node* a = NULL;

    // Inserting nodes
    insertAthead(a, 25);
    insertAthead(a, 12);
    insertAthead(a, 10);
    insertAthead(a, 25);
    insertAthead(a, 3);

    // Creating a cycle for testing
    a->next->next->next->next = a->next;  // Last node points to second node

    // Detect and print result
    if (detectCycle(a)) {
        cout << "Cycle Detected in the Linked List.\n";
    } else {
        cout << "No Cycle in the Linked List.\n";
    }

    return 0;
}
