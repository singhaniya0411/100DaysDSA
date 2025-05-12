/*
    Title: Detect Cycle in a Singly Linked List


    Problem Statement:
        - Create a singly linked list.
        - Detect whether there is a cycle in the list.
        - Return true if a cycle exists, otherwise false.
        
    Approach:
        - Use a hash map (unordered_map) to store visited nodes.
        - Traverse the list and check if a node has already been visited.
        - If yes, a cycle exists. If traversal ends, no cycle.
        
    Time Complexity:
        - O(n), where n is the number of nodes.

    Space Complexity:
        - O(n), for storing visited nodes.

    Author: Vishal Singhaniya.
*/

#include <iostream>
#include <unordered_map>
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

// Detect cycle using a hash map
bool detectCycle(node* &head) {
    node* temp = head;
    unordered_map<node*, bool> mp;

    while (temp != NULL) {
        if (mp.count(temp)) {
            return true;  // Cycle detected
        }
        mp[temp] = true;   // Mark node as visited
        temp = temp->next;
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

    // Creating a cycle for testing (optional)
    a->next->next->next->next = a->next;

    // Detect and print result
    if (detectCycle(a)) {
        cout << "Cycle Detected in the Linked List.\n";
    } else {
        cout << "No Cycle in the Linked List.\n";
    }

    return 0;
}
