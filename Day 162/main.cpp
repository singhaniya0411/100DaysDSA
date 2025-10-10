/*
    Title: Longest Subarray with At Most K Zero Flips

    Problem Statement:
        - Given a binary array (0/1) and an integer k,
          you may flip at most k zeros to ones.
        - Find the maximum length of a contiguous subarray containing only 1s after at most k flips.

    Approach (Sliding Window):
        - Maintain a window [start, end].
        - Count zeros in the window.
        - Expand end; when zero count > k, move start forward until zero count ≤ k.
        - Track maximum window length.

    Example:
        Input:
            arr = {1,1,0,1,0,0,1,0,1,1,1}
            k = 2
            
        Output:
            6

    Time Complexity:
        - O(n), each element visited at most twice.

    Space Complexity:
        - O(1), constant extra storage.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr,int k){
    int res = 0;
    int count=0,start=0,end=0;
    
    while(end<arr.size()){
        if(arr[end]==0){
            count++;
        }
        
        while(count>k){
            if(arr[start]==0){
                count--;
            }
            start++;
        }
        res = max(res,(end-start+1));
        end++;
    }
    
    
    return res;
}

int main(){
    vector<int> arr = {1,1,0,1,0,0,1,0,1,1,1};
    int k =2;
    cout<<"Maximum of length of array containing 1 after flipping : "<<maxLen(arr,k);
    return 0;
}
