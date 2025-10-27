/*
    Title: Koko Eating Bananas – Minimum Eating Speed (Binary Search)

    Problem Statement:
        - Koko loves bananas and has several piles represented by an array `arr`.
        - Each element `arr[i]` represents the number of bananas in the i-th pile.
        - Koko can eat at a constant speed of `midSpeed` bananas per hour.
        - In one hour, she can only eat from one pile.
        - If the pile has fewer bananas than `midSpeed`, she finishes it and moves to the next.
        - Given a total of `k` hours, find the **minimum eating speed** that allows Koko to eat all bananas.

    Approach:
        1. **Binary Search** over possible eating speeds (from 1 to the maximum pile size).
        2. For each possible speed `midSpeed`, calculate total hours required:
            - `hours = ceil(arr[i] / midSpeed)` for each pile.
            - Implemented efficiently as `(arr[i] + midSpeed - 1) / midSpeed`.
        3. If total hours ≤ k → try smaller speeds (move left).
           Else → increase the speed (move right).
        4. The smallest valid speed is the answer.

    Example:
        Input:
            arr = [4, 2, 8, 10, 5]
            k = 6
        Process:
            - Try midSpeed = 5 → Total hours = 1+1+2+2+1 = 7 ❌
            - Try midSpeed = 6 → Total hours = 1+1+2+2+1 = 7 ❌
            - Try midSpeed = 7 → Total hours = 1+1+2+2+1 = 7 ❌
            - Try midSpeed = 8 → Total hours = 1+1+1+2+1 = 6 ✅
        Output:
            ✅ Minimum eating speed = 8
            
    Time Complexity:
        - O(N log M), where N = number of piles, M = max pile size.

    Space Complexity:
        - O(1), using constant extra space.

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

bool isValidSpeed(int midSpeed, vector<int> &arr, int k) {
    int totalHours = 0;
    for (int bananas : arr) {
        totalHours += (bananas + midSpeed - 1) / midSpeed; // ceil division
    }
    return totalHours <= k;
}

int kokoEatBanana(vector<int> &arr, int k) {
    int lowSpeed = 1;
    int highSpeed = *max_element(arr.begin(), arr.end());
    int res = highSpeed;

    while (lowSpeed <= highSpeed) {
        int midSpeed = (lowSpeed + highSpeed) / 2;

        if (isValidSpeed(midSpeed, arr, k)) {
            res = midSpeed;
            highSpeed = midSpeed - 1;
        } else {
            lowSpeed = midSpeed + 1;
        }
    }
    return res;
}

int main() {
    vector<int> arr = {4, 2, 8, 10, 5};
    int k = 6;
    cout << "The minimum speed such that Koko can finish all the piles within "
         << k << " hours : " << kokoEatBanana(arr, k);
    return 0;
}




