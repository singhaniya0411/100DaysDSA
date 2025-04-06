/*
    Title: Count Valid Triangles (Using Two Pointers)
    Problem Statement:
        - Given an array of positive integers representing side lengths,
          count the number of triplets `(i, j, k)` such that:
              arr[i] + arr[j] > arr[k]  (triangle inequality)
              where i < j < k.
    Approach:
        - First, sort the array.
        - Fix the largest side (arr[i]) from the end and use two pointers
          to find all valid pairs on its left.

    Time Complexity:
        - **O(n^2)** due to nested traversal and two-pointer search.

    Space Complexity:
        - **O(1)** extra space (in-place sorting and constant space).

    Assumption:
        - Only positive integers are considered valid side lengths.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Count number of valid triangles that can be formed
int countTriangle(vector<int> arr) {
    int n = arr.size();
    int res = 0;

    if (n < 3) {
        cout << "Array must have at least three elements!" << endl;
        return -1;
    }

    sort(arr.begin(), arr.end()); // Sort array

    for (int i = n - 1; i >= 2; i--) {
        int left = 0, right = i - 1;
        while (left < right) {
            if (arr[left] + arr[right] > arr[i]) {
                res += (right - left); // All elements from left to right-1 will form a triangle
                right--;
            } else {
                left++;
            }
        }
    }
    return res;
}

int main() {
    vector<int> arr = {2, 4, 4, 4, 5, 3, 3, 8, 9, 11}; // Only positive integers considered

    cout << "Number of valid triangles that can be formed: ";
    cout << countTriangle(arr) << endl;

    return 0;
}
