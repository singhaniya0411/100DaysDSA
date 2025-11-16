/*
    Title: Count Quadruples That Sum to a Target (Using Pair-Sum Hashing)

    Problem Statement:
        - You are given an array of integers and a target value.
        - Your task is to count the number of UNIQUE quadruples (a, b, c, d)
              such that:  a + b + c + d = target
        - The order of elements must respect the index order in the array:
              i < j < k < l

    Approach (Optimized Using Hash Map of Pair Sums):
        1. Maintain a hash map `freq` where:
               freq[x] = number of pairs formed so far having sum = x
        2. For each element at index `i`, do two things:
            
            (A) Count valid future quadruples:
                    For every j > i:
                        temp = arr[i] + arr[j]
                        If (target - temp) exists in freq:
                            Add freq[target - temp] to the answer.
            
            (B) Store all previous pair sums:
                    For every j < i:
                        temp = arr[i] + arr[j]
                        Increase freq[temp] by 1.

        3. This ensures:
               - All quadruples follow index ordering (i < j < k < l)
               - We count all valid combinations without duplicates.

    Example:
        Input:
            arr = [1, 2, 10, 4, 12, 11, 5, 9]
            target = 27

        Possible quadruples:
            (1, 10, 11, 5)  → 1+10+11+5 = 27
            (2, 10, 12, 3)  → etc...
        Output:
            Number of valid quadruples → 6

    Dry Run (Conceptual):
        - Build freq of pair-sums for earlier indices.
        - For each i, count future pairs using stored pair-sums.
        - Continue updating the map to maintain correctness.

    Time Complexity:
        - O(n²), since every element forms pairs with earlier and later indices.

    Space Complexity:
        - O(n²) in worst case for storing pair sums in the hash map.

    Applications:
        - Counting 4-sum combinations efficiently
        - Optimized variant of 4-Sum problem
        - Useful in hashing-based pair sum problems

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

int countQuadraple(vector<int>& arr,int target){
    int n = arr.size();
    int count = 0;
    unordered_map<int,int> freq;
    
    for(int i = 0;i<n-1;i++){
        for(int j = i+1;j<n;j++){
            int temp = arr[i]+arr[j];
            
            count+=freq[target-temp];
        }
        
        for(int j = 0;j<i;j++){
            int temp = arr[i]+arr[j];
            freq[temp]++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {1,2,10,4,12,11,5,9};
    int target = 27;
    
    cout<<"Number of quadraples in array to produce target sum : "<<countQuadraple(arr,target);
    return 0;
}