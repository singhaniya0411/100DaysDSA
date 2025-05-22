/*
    Title: Clone a Linked List with Next and Random Pointers

    Problem Statement:
        - Given a linked list where each node has a `next` pointer and a `random` pointer
          (which could point to any node or NULL), create a deep copy of the list.

    Approach:
        1. Insert a cloned node between each original node.
        2. Set the random pointers for each cloned node.
        3. Detach the cloned list from the original list.

    Time Complexity:
        - O(n) : where n is the number of nodes in the list.

    Space Complexity:
        - O(1) : no extra space used (in-place cloning without a hash map).

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Definition of node with random pointer
class node {
public:
    int data;
    node* next;
    node* random;

    node(int val) {
        data = val;
        next = NULL;
        random = NULL;
    }
};

// Insert a node at the head
void insertAtHead(node*& head, int val) {
    node* newnode = new node(val);
    newnode->next = head;
    head = newnode;
}

// Clone the linked list with random pointers
node* cloneLinkedList(node* head) {
    if (!head) return NULL;

    // Step 1: Clone nodes and insert them in-between
    node* curr = head;
    while (curr) {
        node* newNode = new node(curr->data);
        newNode->next = curr->next;
        curr->next = newNode;
        curr = newNode->next;
    }

    // Step 2: Assign random pointers for cloned nodes
    curr = head;
    while (curr) {
        if (curr->random)
            curr->next->random = curr->random->next;
        curr = curr->next->next;
    }

    // Step 3: Separate original and cloned lists
    node* cloneHead = head->next;
    node* cloneCurr = cloneHead;
    curr = head;

    while (cloneCurr->next) {
        curr->next = curr->next->next;
        cloneCurr->next = cloneCurr->next->next;
        curr = curr->next;
        cloneCurr = cloneCurr->next;
    }

    curr->next = NULL;
    return cloneHead;
}

// Print the linked list
void printList(node* head) {
    node* temp = head;
    cout << "Linked List Structure:\n";
    cout << "-----------------------\n";
    while (temp) {
        cout << "Node Value : " << temp->data << "\n";
        cout << "Next       : " << (temp->next ? to_string(temp->next->data) : "NULL") << "\n";
        cout << "Random     : " << (temp->random ? to_string(temp->random->data) : "NULL") << "\n";
        cout << "-----------------------\n";
        temp = temp->next;
    }
}

// Driver code to test cloning
int main() {
    node* head = NULL;

    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    // Set random pointers manually
    head->random = head->next->next;       // 1 -> 3
    head->next->random = head;             // 2 -> 1
    head->next->next->random = head->next; // 3 -> 2

    cout << "Original List:\n";
    printList(head);

    node* cloned = cloneLinkedList(head);

    cout << "\nCloned List:\n";
    printList(cloned);

    return 0;
}
