/*
    Title: Merge K Sorted Linked Lists (Divide and Conquer)

    Problem Statement:
        - You are given K singly linked lists, each of which is sorted in non-decreasing order.
        - The task is to merge all K linked lists into a single sorted linked list and
          return its head.

    Approach (Divide and Conquer + Two-List Merge):
        1. Helper Function: mergeTwo(head1, head2)
            - Merge two sorted linked lists into one sorted list using the standard
              two-pointer approach.
            - Use a dummy node and a current pointer to build the merged list.
            - At each step, attach the smaller of the two nodes (head1 or head2)
              to the merged list.
            - When one list ends, append the remaining nodes of the other list.

        2. Recursive Function: mergeListsRecur(i, j, arr)
            - arr is a vector<Node*> containing the heads of the K sorted lists.
            - If i == j → only one list in this range, return arr[i].
            - Find mid = (i + j) / 2.
            - Recursively merge:
                • left half:  mergeListsRecur(i, mid, arr)
                • right half: mergeListsRecur(mid + 1, j, arr)
            - Merge the two resulting lists using mergeTwo() and return the head.

        3. Main Function: mergeKLists(arr)
            - If K == 0 → return nullptr (no lists).
            - Otherwise, call mergeListsRecur(0, K - 1, arr) and return the result.

    Example:
        Input:
            K = 3
            List 1: 1 → 4 → 5
            List 2: 1 → 3 → 4
            List 3: 2 → 6

        Process:
            - First, merge List 1 and List 2:
                Result A: 1 → 1 → 3 → 4 → 4 → 5
            - Then merge Result A with List 3:
                Final: 1 → 1 → 2 → 3 → 4 → 4 → 5 → 6

        Output:
            Head of merged sorted list:
            1 → 1 → 2 → 3 → 4 → 4 → 5 → 6

    Dry Run (High Level):
        - arr = [L1, L2, L3, L4]
        - mergeListsRecur(0, 3):
            • mid = 1
            • left  = mergeListsRecur(0, 1) → merge L1 & L2
            • right = mergeListsRecur(2, 3) → merge L3 & L4
            • final = mergeTwo(left, right)
        - This reduces the number of lists roughly by half each level.

    Time Complexity:
        - Each mergeTwo of two lists with total N nodes costs O(N).
        - We are effectively merging K lists using divide and conquer:
            → Overall: O(N log K),
              where N is total number of nodes across all lists.

    Space Complexity:
        - O(1) extra space for merging (ignoring recursion stack).
        - O(log K) recursion depth for mergeListsRecur (stack space).

    Author: Vishal Singhaniya
*/



#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

Node* mergeTwo(Node* head1, Node* head2){
    Node* dummy = new Node(-1);
    Node* curr = dummy;
    
    while(head1!=nullptr && head2 != nullptr){
        if(head1->data <= head2->data){
            curr->next = head1;
            head1 = head1->next;
        }
        else{
            curr->next = head2;
            head2 = head2->next;
        }
        
        curr = curr->next;
    }
    
    if(head1!=nullptr){
        curr->next = head1;
    }
    else{
        curr->next = head2;
    }
    
    return dummy->next;
}

Node* mergeListsRecur(int i, int j, vector<Node*>& arr){
    if(i==j){
        return arr[i];
    }
    int mid = (i+j)/2;
    
    Node* head1 = mergeListsRecur(i,mid,arr);
    
    Node* head2 = mergeListsRecur(mid+1,j,arr);
    
    Node* head = mergeTwo(head1,head2);
    return head;
}

Node* mergeKLists(vector<Node*>& arr) {
    if(arr.size()==0){
        return nullptr;
    }
    return mergeListsRecur(0,arr.size()-1,arr);
}

void printList(Node* head){
    Node* temp = head;
    
    while(temp){
        cout<<temp->data;
        if(temp->next){
            cout<<"->";
        }
        temp=temp->next;
    }
}

int main() {
    int k = 3; 
  
    vector<Node*> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    
    Node* head = mergeKLists(arr);

    printList(head);

    return 0;
}
