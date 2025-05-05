/*
    Title: Merge Two Sorted Singly Linked Lists
    
    Problem Statement:
        - Create two sorted singly linked lists.
        - Implement functionality to merge them into one sorted list.
        - Print the final merged list.
        
    Approach:
        - Use a dummy node to simplify the merge process.
        - Traverse both lists using two pointers.
        - Compare node values and append the smaller one to the new list.
        - Attach the remaining elements after one list ends.

    Time Complexity:
        - O(n + m), where n and m are the lengths of the two lists.

    Space Complexity:
        - O(1), no extra space used apart from pointers.

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

// Merge two sorted lists
node* mergeList(node* head1, node* head2) {
    node dummy(-1);             // Dummy node to start the merged list
    node* tail = &dummy;        // Tail pointer for merged list

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    // Append remaining elements
    if (head1 != NULL) {
        tail->next = head1;
    }
    if (head2 != NULL) {
        tail->next = head2;
    }

    return dummy.next;  // Return head of merged list
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
    node* a = NULL;
    insertAthead(a, 25);
    insertAthead(a, 12);
    insertAthead(a, 10);
    insertAthead(a, 7);
    insertAthead(a, 3);

    node* b = NULL;
    insertAthead(b, 11);
    insertAthead(b, 6);
    insertAthead(b, 2);

    cout << "List A: ";
    printList(a);

    cout << "List B: ";
    printList(b);

    node* merged = mergeList(a, b);
    
    cout << "Merged List: ";
    printList(merged);

    return 0;
}
