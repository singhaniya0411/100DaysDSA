/*
    Title: Container with Most Water (Two Pointers Approach)

    Problem Statement:
        - Given an array where each element represents the height of a vertical line on the x-axis,
          find two lines that, together with the x-axis, form a container that holds the most water.

    Approach:
        - Use two pointers starting from both ends of the array.
        - Calculate the area between the two lines.
        - Move the pointer pointing to the shorter line inward to possibly find a taller line.

    Time Complexity:
        - **O(n)** — Each element is visited at most once.

    Space Complexity:
        - **O(1)** — Constant space used.



    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

// Function to calculate container with most water
int maxWater(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    int res = 0;

    while (left < right) {
        int water = min(arr[left], arr[right]) * (right - left);
        res = max(res, water);

        if (arr[left] < arr[right]) {
            left++;
        } else {
            right--;
        }
    }

    return res;
}

int main() {
    int arr[] = {1, 4, 5, 3, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum water that can be contained: " << maxWater(arr, size) << endl;

    return 0;
}
