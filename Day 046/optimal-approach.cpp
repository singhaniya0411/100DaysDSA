/*
    Title: Find Union of Two Arrays (Brute Force Approach)

    Problem Statement:
        - Given two integer arrays, find their union (all unique elements from both arrays).

    Approach:
        - Use a result vector and manually check for duplicates before inserting elements.
        - Traverse both arrays and add unique elements to the result vector.

    Returns:
        - A vector containing the unique union of the two arrays.

    Time Complexity:
        - **O(n * m)** in the worst case (for each element, checking if it already exists).

    Space Complexity:
        - **O(n + m)** (storing unique elements in a result vector).

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

// Function to find the union of two arrays
vector<int> findUnion(const vector<int>& a, const vector<int>& b) {
    vector<int> res;

    // Insert elements from the first array if not already present in res
    for (int i = 0; i < a.size(); i++) {
        int j = 0;
        while (j < res.size()) {
            if (a[i] == res[j]) {
                break;  // Element already exists
            }
            j++;
        }
        if (j == res.size()) {  // If element is not found, add it
            res.push_back(a[i]);
        }
    }

    // Insert elements from the second array if not already present in res
    for (int i = 0; i < b.size(); i++) {
        int j = 0;
        while (j < res.size()) {
            if (b[i] == res[j]) {
                break;  // Element already exists
            }
            j++;
        }
        if (j == res.size()) {  // If element is not found, add it
            res.push_back(b[i]);  // ✅ Corrected: `b[i]` instead of `a[i]`
        }
    }

    return res;
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {5, 4, 9};

    vector<int> result = findUnion(a, b);

    cout << "Union: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
