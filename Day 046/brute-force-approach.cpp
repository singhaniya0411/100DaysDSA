/*
    Title: Find Union of Two Arrays (Using Hashing)

    Problem Statement:
        - Given two integer arrays, find their union (all unique elements from both arrays).

    Approach:
        - Use an **unordered_set** to store unique elements from both arrays.
        - Convert the set back to a **vector** and return it.

    Returns:
        - A vector containing the unique union of the two arrays.

    Time Complexity:
        - **O(n + m)** (where n and m are the sizes of the two arrays, using set operations efficiently)

    Space Complexity:
        - **O(n + m)** (since we store all unique elements)

    Author: Vishal Singhaniya
*/


#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Function to find the union of two arrays
vector<int> findUnion(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> res;
    
    // Insert elements of first array
    for (int num : a) {
        res.insert(num);
    }

    // Insert elements of second array
    for (int num : b) {
        res.insert(num);
    }

    // Convert set to vector
    return vector<int>(res.begin(), res.end());
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
