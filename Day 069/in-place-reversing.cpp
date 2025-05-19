/*
    Title: Reverse Singly Linked List in Groups of K

    Problem Statement:
        - Create a singly linked list.
        - Reverse the list in groups of size k.
        - Return the new head of the modified list.

    Approach:
        - Reverse k nodes at a time using in-place pointer manipulation.
        - Keep track of the current head and tail of each segment.
        - Connect each reversed group to the previously reversed list.

    Time Complexity:
        - O(n), where n is the number of nodes.

    Space Complexity:
        - O(1), as reversal is done in-place.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Definition of node
class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Insert a node at the head
void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

// Reverse linked list in groups of k (in-place)
Node* reverseInGroup(Node* head, int k) {
    if (head == NULL || k <= 1) return head;

    Node* curr = head;
    Node* newHead = NULL;
    Node* tail = NULL;

    while (curr != NULL) {
        Node* groupHead = curr;
        Node* prev = NULL;
        int count = 0;

        // Reverse k nodes
        while (curr != NULL && count < k) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Connect previous group's tail to current reversed group head
        if (newHead == NULL) {
            newHead = prev;
        } else {
            tail->next = prev;
        }

        // Move the tail pointer to the end of the current group
        tail = groupHead;
    }

    return newHead;
}

// Print the linked list
void printList(Node* list) {
    Node* temp = list;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Driver code
int main() {
    Node* head = NULL;

    // Inserting nodes into the list
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    int k = 2;

    // Reversing in groups and printing result
    Node* updatedHead = reverseInGroup(head, k);
    cout << "List after reversing in groups of " << k << ": ";
    printList(updatedHead);

    return 0;
}
