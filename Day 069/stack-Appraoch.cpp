/*
    Title: Reverse Singly Linked List in Groups of K

    Problem Statement:
        - Create a singly linked list.
        - Reverse the list in groups of size k.
        - Return the new head of the modified list.

    Approach:
        - Use a stack to reverse k nodes at a time.
        - For each group, push the node data into the stack.
        - Pop from the stack to form the reversed segment and append to the result list.

    Time Complexity:
        - O(n), where n is the number of nodes.

    Space Complexity:
        - O(k), for storing elements in the stack for each group.
    Author: Vishal Singhaniya
*/

#include <iostream>
#include <stack>
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
void insertAtHead(node*& head, int val) {
    node* newNode = new node(val);
    newNode->next = head;
    head = newNode;
}

// Reverse linked list in groups of k using a stack
node* reverseInGroup(node* head, int k) {
    if (head == NULL || k <= 1) {
        return head;
    }

    stack<int> st;
    node* temp = head;
    node* result = NULL;
    node* move = NULL;

    while (temp != NULL) {
        int i = 0;
        node* start = temp;

        // Push k elements into stack
        while (start != NULL && i < k) {
            st.push(start->data);
            start = start->next;
            i++;
        }

        // Pop from stack and create new reversed segment
        while (!st.empty()) {
            node* newNode = new node(st.top());
            st.pop();

            if (result == NULL) {
                result = newNode;
                move = result;
            } else {
                move->next = newNode;
                move = move->next;
            }
        }

        temp = start;
    }

    return result;
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

    // Inserting nodes into the list
    insertAtHead(a, 5);
    insertAtHead(a, 4);
    insertAtHead(a, 3);
    insertAtHead(a, 2);
    insertAtHead(a, 1);
    
    int k =3;

    // Reversing in groups of 2 and printing result
    node* b = reverseInGroup(a, k);
    
    cout<<"List in reversing order by group of "<<k<<" : ";
    printList(b);

    return 0;
}
