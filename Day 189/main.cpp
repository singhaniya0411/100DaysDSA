/*
    Title: Count Subarrays with Exactly K Distinct Integers

    Problem Statement:
        Given an array of integers and an integer K, find the total number of subarrays that contain 
        exactly K distinct integers
        
    Example:
        Input:
            arr = [1, 2, 1, 2, 3]
            K = 2
        Output:
            7

        Explanation:
            The subarrays with exactly 2 distinct integers are:
            [1, 2], [2, 1], [1, 2], [2, 3], 
            [1, 2, 1], [2, 1, 2], [1, 2, 3]

    Approach:
        1. To count subarrays with exactly K distinct elements, 
           use the formula:
               exactlyK = atMostK(K) - atMostK(K - 1)
        2. The helper function atMostK() counts subarrays with 
           at most K distinct integers using the sliding window technique.
        3. Maintain a frequency map for current window elements.
        4. Expand the window by moving the right pointer.
        5. If the number of distinct elements exceeds K, 
           shrink the window from the left until it becomes valid.
        6. Add (right - left + 1) to the result for each iteration.

    Dry Run:
        arr = [1, 2, 1, 2, 3], K = 2

        Subarrays with at most 2 distinct = 12
        Subarrays with at most 1 distinct = 5
        → exactlyK = 12 - 5 = 7

    Time Complexity: O(n)
    Space Complexity: O(n) (for the frequency map)

    Author: Vishal Singhaniya
*/


#include <bits/stdc++.h>
using namespace std;

int atMostK(vector<int>& arr, int k) {
    int n = arr.size();
    int res = 0;
    
    int left = 0, right = 0;
    unordered_map<int,int> freq;
    
    while(right < n) {
        freq[arr[right]]++;
        
        if(freq[arr[right]] == 1) {
            k--;
        }
        
        while(k < 0) {
            freq[arr[left]]--;
            if(freq[arr[left]] == 0) {
                k++;
            }
            left++;
        }
        
        res += (right - left + 1);
        right++;
    }
    
    return res;
}

int exactlyK(vector<int>& arr, int k) {
    return atMostK(arr, k) - atMostK(arr, k - 1);
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3};
    int k = 2;
    
    cout << "\nArray : ";
    for(int val : arr) {
        cout << val << " ";
    }
    
    cout << "\nK : " << k;
    
    int result = exactlyK(arr, k);
    
    cout << "\nNumber of subarrays having exactly " << k 
         << " distinct elements are : " << result << "\n";
    
    return 0;
}




