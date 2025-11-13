/*
    Title: Count Pairs with Given Difference (Using Hash Map).

    Problem Statement:
        - You are given an integer array `arr` and an integer `k`.
        - Find the total number of unordered pairs (i, j) such that:
            
                |arr[i] - arr[j]| = k

        - Each valid pair should be counted only once.

    Example:
        Input:
            arr = [1, 5, 3, 4, 2]
            k = 2
        Output:
            3
        Explanation:
            Valid pairs are:
                (1,3), (5,3), (4,2)

    Approach:
        - Use an unordered_map to store frequencies of elements while iterating.
        - For each element x, check:
              • if (x + k) exists → add its frequency
              • if (x - k) exists → add its frequency
        - Increment the frequency of current element afterwards.
        - This ensures no double counting and maintains O(n) efficiency.

    Dry Run:
        arr = [3, 1, 4, 1, 5], k = 2

        i=0 → 3 → no matches → map={3:1}
        i=1 → 1 → check(1+2=3) → found → cnt=1 → map={3:1,1:1}
        i=2 → 4 → check(4-2=2), (4+2=6) → none → map={3:1,1:1,4:1}
        i=3 → 1 → check(1+2=3) → found → cnt=2 → map={3:1,1:2,4:1}
        i=4 → 5 → check(5-2=3) → found → cnt=3 → map={3:1,1:2,4:1,5:1}

        Final answer = 3

    Time Complexity:  O(n)
    Space Complexity: O(n)

    Author: Vishal Singhaniya
*/


#include <bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& arr, int k) {
    int cnt = 0;
    unordered_map<int,int> map;
    
    int n = arr.size();
    for(int i = 0; i < n; i++){
        if(map.find(arr[i] + k) != map.end()){
            cnt += map[arr[i] + k];
        }
        if(map.find(arr[i] - k) != map.end()){
            cnt += map[arr[i] - k];
        }
        map[arr[i]]++;
    }
    
    return cnt;
}

int main() {
    vector<int> arr = {1, 5, 3, 4, 2};
    int k = 2;

    cout << "\nArray : ";
    for (int x : arr) cout << x << " ";

    cout << "\nDifference (k) : " << k;

    int result = countPairs(arr, k);

    cout << "\nNumber of valid pairs with difference " << k
         << " : " << result << "\n";

    return 0;
}

