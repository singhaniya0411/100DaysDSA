/*
    Title: Median of Two Sorted Arrays

    Problem Statement:
        - You are given two sorted arrays `a[]` and `b[]` of sizes `n` and `m`.
        - You need to find the **median** of the two sorted arrays combined.
        - The median is the middle value if total elements are odd,
          or the average of the two middle values if total elements are even.
        - The combined array must be considered as if both arrays were merged and sorted.

    Approach (Merge Method):
        1. Use two pointers (`i` for array a, `j` for array b`).
        2. Iterate until you reach the middle of the merged array — i.e. `(m+n)/2` times.
        3. Track two elements:
            - `m1` = current element.
            - `m2` = previous element.
        4. At each step, pick the smaller of `a[i]` and `b[j]`.
        5. When you reach the middle:
            - If total (m+n) is **odd**, median = `m1`.
            - If total (m+n) is **even**, median = `(m1 + m2) / 2.0`.

    Example:
        Input:
            a = [1, 3, 5]
            b = [2, 4, 6]

        Process:
            Merged sequence: [1, 2, 3, 4, 5, 6]
            Middle two = 3, 4 → Median = (3 + 4) / 2 = 3.5

        Output:
            ✅ Median = 3.5

    Time Complexity:- O(m + n)  
    
    Space Complexity:- O(1)

    Optimized Approach (not implemented here):
        - Using Binary Search in O(log(min(n, m))) time.

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find the median of two sorted arrays
double medianOf2(vector<int>& a, vector<int>& b) {
    int n = a.size(), m = b.size();
    int i = 0, j = 0;
    int m1 = -1, m2 = -1;

    for (int count = 0; count <= (m + n) / 2; count++) {
        m2 = m1;

        if (i != n && j != m) {
            // Pick the smaller element
            if (a[i] > b[j]) {
                m1 = b[j++];
            } else {
                m1 = a[i++];
            }
        } 
        else if (i < n) {
            m1 = a[i++];
        } 
        else {
            m1 = b[j++];
        }
    }

    // If total number of elements is odd
    if ((m + n) % 2 == 1) {
        return m1;
    } 
    // If even
    else {
        return (m1 + m2) / 2.0;
    }
}

// Driver code
int main() {
    vector<int> a = {1, 3, 5};
    vector<int> b = {2, 4, 6};

    cout << "Median of the two sorted arrays is : " 
         << medianOf2(a, b) << "\n";

    return 0;
}











