/*
    Title: Check if a Singly Linked List is a Palindrome

    Problem Statement:
        - You are given the head of a singly linked list.
        - Determine whether the linked list is a palindrome.
        - A list is a palindrome if the sequence of node values reads the same
          forward and backward.

    Example:
        Input:
            1 → 2 → 3 → 3 → 2 → 1
        Output:
            true  (The linked list is a palindrome)

        Input:
            1 → 2 → 3 → 4
        Output:
            false (Not a palindrome)

    Approach (Fast–Slow Pointer + Reverse Second Half):
        1. Edge cases:
            - If the list is empty or has only one node, it's a palindrome.

        2. Find the middle of the list:
            - Use two pointers:
                • slow  → moves 1 step at a time.
                • fast  → moves 2 steps at a time.
            - When fast reaches the end, slow will be at the middle.

        3. Reverse the second half:
            - Reverse the list starting from slow->next.
            - Now you have:
                First half:  head → ... → slow
                Second half: reversed list starting from head2

        4. Compare the two halves:
            - Traverse both halves node by node.
            - If all corresponding values match, it's a palindrome.
            - If any mismatch occurs, return false.

        5. (Optional) Restore the list:
            - Reverse the second half again and attach back
              if you want to keep the original list unchanged.
              (Not done here, since we only care about checking.)

    Dry Run:
        List: 1 → 2 → 3 → 3 → 2 → 1

        - slow at 3 (first middle), fast reaches end.
        - Reverse from slow->next:
            Second half becomes: 1 → 2 → 3
        - Compare:
            1 == 1
            2 == 2
            3 == 3 → all match → palindrome ✅

    Time Complexity:
        - O(n): 
            • O(n) to find the middle,
            • O(n) to reverse the second half,
            • O(n) to compare halves.

    Space Complexity:
        - O(1): 
            • Only a few extra pointers are used.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;
    
    while(curr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    
    return prev;
}

bool isIdentical(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    
    while(temp1 && temp2){
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    // If lengths differ, not palindrome, but for our split they will match in length
    return true;
}

bool isPlaindrome(Node* head){
    if(!head || !head->next){
        return true;
    }
    
    // Find middle using slow and fast pointers
    Node* slow = head;
    Node* fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse second half
    Node* head2 = reverse(slow->next);
    slow->next = nullptr;   // split the list
    
    // Compare both halves
    bool res = isIdentical(head, head2);
    return res;
}

int main(){
    // List: 1 -> 2 -> 3 -> 3 -> 2 -> 1

    Node* common = new Node(3);
    common->next = new Node(2);
    common->next->next = new Node(1);
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = common;
    
    if(isPlaindrome(head1)){
        cout << "The linked list is palindrome\n";
    }
    else{
        cout << "The linked list is not palindrome\n";
    }
    
    return 0;
}








