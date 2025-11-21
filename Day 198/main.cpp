/*
    Title: Longest Subarray with Sum Divisible by K.

    Problem Statement:
        - Given an integer array `arr` and an integer `k`,
          find the length of the **longest subarray** whose sum is divisible by `k`.
        - A subarray (i, j) is valid if:
                (arr[i] + arr[i+1] + ... + arr[j]) % k == 0

    Core Idea:
        - Use **prefix sum with modulo k**.
        - If two prefix sums have the same remainder when divided by k,
          then the subarray between them has sum divisible by k.
        - To get the *longest* such subarray, store the **first index**
          where each remainder appears.

    Approach:
        1. Initialize `sum = 0` and `res = 0`.
        2. Use an unordered_map to store:
                remainder → first index of occurrence
        3. Traverse the array:
            - Update running sum:
                  sum = ((sum + arr[i]) % k + k) % k
            - If sum == 0, then subarray (0..i) is divisible by k.
            - If sum is already in the map:
                  length = i - prefIdx[sum]
                  update result with maximum length
            - Else store prefIdx[sum] = i
        4. Return the maximum length found.

    Example:
        Input:
            arr = [2, 7, 6, 1, 4, 5]
            k = 3

        Prefix sum mod sequence:
            [2, 0, 0, 1, 2, 1]

        Subarr(0..1) → sum=9, divisible by 3 (length = 2)
        Subarr(0..2) → sum=15, divisible by 3 (length = 3)
        Subarr(2..4) → sum=11, not divisible
        ...

        ✅ Output: 4 (Longest valid subarray)

    Dry Run:
        i=0 → sum=2 → store {2:0}
        i=1 → sum=0 → res=2
        i=2 → sum=0 → res=3
        i=3 → sum=1 → store {1:3}
        i=4 → sum=2 → (2 occurred at 0) → length=4 → res=4
        i=5 → sum=1 → (1 occurred at 3) → length=2 → res still 4

        Final Answer = 4

    Time Complexity:
        - O(N), each element is processed once.

    Space Complexity:
        - O(K) for storing remainders in the map.

    Applications:
        - Data stream analysis
        - Subarray-based optimization problems
        - Competitive programming challenges

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int longestSubarrayDivK(vector<int>& arr, int k) {
    int n= arr.size();
    int res = 0;
    unordered_map<int,int> prefIdx;
    int sum = 0;
    
    for(int i = 0;i<n;i++){
        sum = ((sum+arr[i])%k+k)%k;
        if(sum==0){
            res=i+1;
        }
        else if(prefIdx.find(sum)!=prefIdx.end()){
            res = max(res,i-prefIdx[sum]);
        }
        else{
            prefIdx[sum]=i;
        }
    }
    return res;
}

int main(){
    vector<int> arr = {-2, 2, -5, 12, -11, -1, 7};
    int k = 3;
    cout<<"Longest length of subarray whose sum is divisible by "<<k<<" is : "<<longestSubarrayDivK(arr,k);
    
    return 0;

}
