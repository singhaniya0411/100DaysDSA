/*
    Title: Count Subarrays with a Given XOR (Optimized Hashing Approach)

    Problem Statement:
        - Given an array of integers and a target XOR value `k`, find the number of subarrays whose XOR equals `k`.

    Optimized Approach:
        - Use an **unordered_map** to store prefix XOR frequencies.
        - Traverse the array while maintaining the prefix XOR.
        - If `preXOR == k`, increment the count.
        - Check if `preXOR ^ k` exists in the hash map; if yes, add its frequency to count.
        - Update the map with the current prefix XOR.
    Time Complexity:
        - **O(n)** (Each element is processed once)

    Space Complexity:
        - **O(n)** (To store prefix XOR frequencies)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to count subarrays with XOR equal to k (Optimized Hashing)
int subArrayXOR(vector<int> arr, int k) {
    unordered_map<int, int> mp;
    int res = 0, preXOR = 0;

    for (int i = 0; i < arr.size(); i++) {
        preXOR ^= arr[i];  // Compute prefix XOR

        if (preXOR == k) {
            res++;
        }

        if (mp.count(preXOR ^ k)) {
            res += mp[preXOR ^ k];
        }

        mp[preXOR]++;  // Store prefix XOR in the map
    }

    return res;
}

int main() {
    vector<int> arr = {4, 2, 2, 6, 4};  
    int k = 6;

    // Print the count of subarrays with XOR = k
    cout << "The subarray count having XOR = " << k << " is " << subArrayXOR(arr, k) << endl;
    
    return 0;
}
