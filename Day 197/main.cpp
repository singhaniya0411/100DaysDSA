/*
    Title: Count Subarrays With Sum Divisible by K.

    Problem Statement:
        - Given an integer array `arr` and an integer `k`,
          count how many subarrays have a sum that is divisible by `k`.
        - A subarray (i, j) is valid if:
                (arr[i] + arr[i+1] + ... + arr[j]) % k == 0

    Core Idea:
        - Use prefix-sum modulo technique.
        - If two prefix sums have the same remainder mod k,
          then the subarray between them has sum divisible by k.

    Approach:
        1. Maintain a running prefix sum.
        2. Convert prefix sum to a positive modulo value:
                mod = ((prefix % k) + k) % k
        3. If mod == 0 → one valid subarray ends here.
        4. If this mod appeared before, all previous occurrences
           contribute valid subarrays.
        5. Store frequency of each mod value using a hash map.

    Example:
        arr = [4, 5, 0, -2, -3, 1], k = 5

        prefix sum mod k sequence:
            4 % 5 = 4
            9 % 5 = 4  → match with previous '4'
            9 % 5 = 4  → again
            7 % 5 = 2
            4 % 5 = 4
            5 % 5 = 0  → directly divisible

        Total = 7 valid subarrays

    Dry Run:
        i=0 → sum=4 → freq[4] used 0 times → res=0  
        i=1 → sum=4 → freq[4] used 1 time  → res=1  
        i=2 → sum=4 → freq[4] used 2 times → res=3  
        i=3 → sum=2 → freq[2] used 0 times → res=3  
        i=4 → sum=4 → freq[4] used 3 times → res=6  
        i=5 → sum=0 → directly divisible → res=7  

        Final output = 7

    Time Complexity:
        - O(N), as every element is processed once.

    Space Complexity:
        - O(K) for storing frequency of remainders.

    Applications:
        - Financial analysis (finding divisible intervals)
        - Pattern detection in time-series sums
        - Competitive programming on subarray-sum problems

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

int subCount(vector<int> &arr, int k){
    int res = 0,n = arr.size();
    int sum = 0;
    unordered_map<int,int> prefCnt;
    for(int i = 0;i<n;i++){
        sum = ((sum+arr[i])%k+k)%k;
        if(sum == 0){
            res++;
        }
        res+=prefCnt[sum];
        prefCnt[sum]++;
    }
    return res;
}


int main(){
    vector<int> arr = {4, 5, 0, -2, -3, 1};
    int k = 5;
    cout<<"Number of subarray which has the sum divisible by "<<k<<" : "<<subCount(arr,k);
    return 0;
}
