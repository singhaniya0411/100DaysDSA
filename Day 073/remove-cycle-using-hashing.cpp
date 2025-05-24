/*
    Title: Remove Cycle from Singly Linked List (using Hashing)


    Problem Statement:
        - Create a singly linked list.
        - Introduce a cycle manually.
        - Detect whether a cycle exists.
        - If a cycle exists, remove the cycle.

    Approach:
        - Currently using hashing to detect and remove the cycle.
        - Traverse the linked list while storing visited nodes in a hash map.
        - If a node is visited again, it is the start of the cycle.
        - Set the previous node's next to NULL to break the cycle.

        (Note: This will later be updated to use Floyd’s Cycle Detection Algorithm.)

    Time Complexity:
        - O(n), where n is the number of nodes.

    Space Complexity:
        - O(n), due to the extra hash map used.

    Author: Vishal Singhaniya
*/


#include <iostream>
#include<unordered_map>
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

// Function to find the starting node of a cycle using Floyd’s Algorithm
void removeCycle(Node* &head) {
    unordered_map<Node*,int> mp;
    // Detect cycle
    
    Node* temp = head;
    Node* p = NULL;
    while(temp!=NULL){
        if(mp.count(temp)){
            if(p!=NULL){
                p->next=NULL;
            }
            break;
        }
        
        mp[temp]=1;
        p=temp;
        temp=temp->next;
    }
}

bool detectCycle(Node* head){
    Node* slow=head;
    Node* fast=head;
    
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true;
        }
    }
    return false;
}

void printList(Node* head){
    Node* temp=head;
    bool flag=detectCycle(head);
    // cout<<flag;
    if(flag){
        cout<<"Cycle is present inside loop , Hence there is an infinte traversal to list.";
    }
    else{
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }   
    }
    
    cout<<"\n";
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

    removeCycle(head);
    if(detectCycle(head)){
        cout<<"Cycle detected.\n";
    }else{
        cout<<"No cycle in this linked list\n";
    }
    
    printList(head);

    return 0;
}
