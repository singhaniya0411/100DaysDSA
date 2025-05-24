/*
    Title: Remove Cycle from Singly Linked List (Using Floyd’s Algorithm)

    Problem Statement:
        - Create a singly linked list.
        - Introduce a cycle manually.
        - Detect whether a cycle exists.
        - If a cycle exists, remove the cycle.

    Approach:
        - Use Floyd’s Cycle Detection Algorithm (Tortoise and Hare).
        - Move two pointers at different speeds to detect the cycle.
        - Once detected, move one pointer to head and find the meeting point.
        - Traverse to the node before the cycle starts and set its next to NULL.

    Time Complexity:
        - O(n), where n is the number of nodes.

    Space Complexity:
        - O(1), constant space used.

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

// Remove cycle using Floyd’s algorithm
void removeCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        // Cycle detected
        if (slow == fast) {
            slow = head;

            // If cycle starts from head itself
            if (slow == fast) {
                while (fast->next != slow) {
                    fast = fast->next;
                }
                fast->next = NULL;
                return;
            }

            // General case
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }

            fast->next = NULL;
            return;
        }
    }
}

// Print the linked list safely (stops after 100 nodes to avoid infinite loop)
void printList(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL && count < 100) {
        cout << temp->data << " ";
        temp = temp->next;
        count++;
    }
    if (count == 100) cout << "... (possible cycle)";
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

    // Introduce a cycle: Node 5 points to Node 3
    head->next->next->next->next->next = head->next->next;  // 5 -> 3

    // Remove cycle
    // removeCycle(head);

    // Print after cycle removal
    cout << "Linked list after removing cycle: ";
    printList(head);

    return 0;
}
