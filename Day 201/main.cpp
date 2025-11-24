/*
    Title: Find the Intersection Point of Two Linked Lists

    Problem Statement:
        - You are given the heads of two singly linked lists.
        - The lists may or may not intersect at some point.
        - If they intersect, return the node where they merge.
        - If they do not intersect, return NULL.

    Approach (Two Pointer Technique):
        1. Initialize two pointers:
            - ptr1 → head1
            - ptr2 → head2
        2. Traverse both lists simultaneously.
        3. When ptr1 reaches the end, move it to head2.
           When ptr2 reaches the end, move it to head1.
        4. If the lists intersect, the pointers will meet
           at the intersection node after at most (L1 + L2) steps.
        5. If they don’t intersect, both pointers will become NULL.

    Example:
        List1:  1 → 2 → 3
                          ↘
                           7 → 8 → 9
                          ↗
        List2:  4 → 5 → 6

        Intersection at Node: 7

    Dry Run:
        ptr1 starts at head1 (1)
        ptr2 starts at head2 (4)

        After first pass:
        - ptr1 jumps to head2
        - ptr2 jumps to head1

        On second pass:
        - Both meet at node 7 ✅

    Time Complexity:
        O(N + M)
        Where N and M are lengths of both linked lists.

    Space Complexity:
        O(1)  (Only pointers used, no extra memory)

    Author: Vishal Singhaniya.
*/


#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

Node* getIntersection(Node* head1, Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    
    if(ptr1 == nullptr || ptr2 == nullptr){
        return nullptr;
    }
    
    while(ptr1 != ptr2){
        ptr1 = (ptr1 == nullptr) ? head2 : ptr1->next;
        ptr2 = (ptr2 == nullptr) ? head1 : ptr2->next;
    }
    
    return ptr1;   // intersection node OR nullptr
}

int main(){

    // Create common part
    Node* common = new Node(7);
    common->next = new Node(8);
    common->next->next = new Node(9);

    // List 1: 1->2->3->7->8->9
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;

    // List 2: 4->5->6->7->8->9
    Node* head2 = new Node(4);
    head2->next = new Node(5);
    head2->next = new Node(6);
    head2->next->next = common;

    Node* res = getIntersection(head1, head2);

    if(res != nullptr){
        cout << "The intersection point of these two linked lists is: " << res->data << endl;
    }
    else{
        cout << "The lists do not intersect.\n";
    }

    return 0;
}

