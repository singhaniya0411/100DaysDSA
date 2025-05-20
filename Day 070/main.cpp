/*
    Title: Sum of Two Numbers Represented by Linked Lists


    Problem Statement:
        - You are given two non-empty linked lists representing two non-negative integers.
        - The digits are stored in forward order (most significant digit first).
        - Each node contains a single digit.
        - Add the two numbers and return the sum as a linked list in the same format.

    Constraints:
        - The input lists may have different lengths.
        - Leading zeros should be removed before computation.
        - The result should also be returned in forward order.

    Approach:
        - Remove leading zeros from both lists.
        - Reverse both lists to make addition easier (least significant digit first).
        - Traverse both lists, adding digits and managing carry.
        - Reverse the result list to restore forward order.

    Time Complexity:
        - O(n + m), where n and m are the lengths of the two input lists.

    Space Complexity:
        - O(1), no extra space except for result list.

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

// Reverse a linked list
node* reverseList(node* head) {
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// Remove leading zeros
node* removeLeadZero(node*& head) {
    while (head != NULL && head->data == 0) {
        head = head->next;
    }
    return head;
}

// Return length of linked list
int lengthList(node* head) {
    int count = 0;
    node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Sum two linked lists
node* sumList(node* head1, node* head2) {
    node* list1 = removeLeadZero(head1);
    node* list2 = removeLeadZero(head2);

    int size1 = lengthList(list1);
    int size2 = lengthList(list2);

    if (size1 < size2) {
        return sumList(list2, list1);  // Ensure list1 is longer
    }

    list1 = reverseList(list1);
    list2 = reverseList(list2);

    node* res = list1;
    int carry = 0;

    while (list2 != NULL || carry != 0) {
        list1->data += carry;

        if (list2 != NULL) {
            list1->data += list2->data;
            list2 = list2->next;
        }

        carry = list1->data / 10;
        list1->data = list1->data % 10;

        if (list1->next == NULL && carry != 0) {
            list1->next = new node(0);
        }

        list1 = list1->next;
    }

    return reverseList(res);
}

// Print the linked list
void printList(node* list) {
    node* temp = list;
    while (temp != NULL) {
        cout << temp->data;
        if (temp->next != NULL) cout << " -> ";
        temp = temp->next;
    }
    cout << "\n";
}

// Driver code
int main() {
    node* a = NULL;
    node* b = NULL;

    // Number 1: 3 -> 4 -> 2 represents 342
    insertAthead(a, 2);
    insertAthead(a, 4);
    insertAthead(a, 3);

    // Number 2: 4 -> 6 -> 5 represents 465
    insertAthead(b, 5);
    insertAthead(b, 6);
    insertAthead(b, 4);

    cout << "First Number : ";
    printList(a);
    cout << "Second Number: ";
    printList(b);

    node* result = sumList(a, b);

    cout << "Sum          : ";
    printList(result);

    return 0;
}
