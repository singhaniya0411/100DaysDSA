/*
    Title: Sort a Nearly Sorted (K-Sorted) Array Using Min Heap

    Problem Statement:
        - You are given an array where each element is at most `k` positions
          away from its correct position in the sorted order.
        - Such an array is called a **k-sorted** or **nearly sorted** array.
        - The task is to efficiently sort the array.

    Example:
        Input:
            arr = [2, 3, 1, 4]
            k = 2

        Output:
            [1, 2, 3, 4]

        Explanation:
            - Each element is at most 2 positions away from its correct position.
            - Using a min heap of size (k + 1), we can sort efficiently.

    Approach (Min Heap / Priority Queue):
        1. Create a min heap (priority queue).
        2. Insert the first `k` elements into the heap.
        3. For each remaining element:
            - Push the current element into the heap.
            - Extract the minimum element from the heap and place it
              in the correct position in the array.
        4. After processing all elements, extract and place
           the remaining elements from the heap.
        5. This guarantees the array is fully sorted.

    Dry Run:
        arr = [2, 3, 1, 4], k = 2

        Heap initially: {2, 3}
        Insert 1 → heap = {1, 3, 2}
        Extract min → arr[0] = 1

        Insert 4 → heap = {2, 3, 4}
        Extract min → arr[1] = 2

        Remaining heap → {3, 4}
        arr[2] = 3, arr[3] = 4

        Final Array = [1, 2, 3, 4]

    Time Complexity:
        - O(n log k), where:
            n = number of elements
            k = maximum distance from sorted position

    Space Complexity:
        - O(k), for the min heap.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

void nearlySorted(vector<int>& arr, int k ){
    int  n =arr.size();
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0 ; i<k ;i++){
        pq.push(arr[i]);
    }
    int i;
    for(i = k ; i<n;i++){
        pq.push(arr[i]);
        
        arr[i-k]=pq.top();
        pq.pop();
    }
    
    while(!pq.empty()){
        arr[i-k]=pq.top();
        pq.pop();
        i++;
    }
}

int main(){
    
    vector<int>arr = {2,3,1,4};
    int k =2;
    
    cout<<"Original Vector : [ ";
    for(int x : arr){
        cout<<x << " ";
    }
    cout<<" ]\n\n";
    
    nearlySorted(arr, k);
    
    cout<<"Sorted Vector : [ ";
    for(int x : arr){
        cout<<x << " ";
    }
    cout<<" ]\n";
    return 0;
}
