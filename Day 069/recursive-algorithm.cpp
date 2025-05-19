/*
    Title: Reverse Singly Linked List in Groups of K

    Problem Statement:
        - Create a singly linked list.
        - Reverse the list in groups of size k.
        - Return the new head of the modified list.
        
    Approach:
        - Recursively reverse k nodes at a time using in-place pointer manipulation.
        - Connect the last node of the reversed group to the result of next reversed group.
    Time Complexity:
        - O(n), where n is the number of nodes.

    Space Complexity:
        - O(n/k) due to recursive stack calls.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Definition of a node
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

// Recursive function to reverse linked list in groups of k
Node* reverseInGroup(Node* head, int k) {
    if (head == NULL || k <= 1) return head;

    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int count = 0;

    // Reverse first k nodes
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // Recurse for the rest of the list
    if (next != NULL) {
        head->next = reverseInGroup(next, k);
    }

    return prev; // new head after reversal
}

// Print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Driver code
int main() {
    Node* head = NULL;

    // Creating list: 1 -> 2 -> 3 -> 4 -> 5
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    int k = 2;

    // Reverse in groups and display result
    Node* updatedHead = reverseInGroup(head, k);
    cout << "List after reversing in groups of " << k << ": ";
    printList(updatedHead);

    return 0;
}
