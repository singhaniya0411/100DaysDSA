/*
    Title: Find Intersection of Two Arrays (Using Hashing)

    Problem Statement:
        - Given two integer arrays, find their intersection (i.e., common elements without duplicates).

    Approach:
        - Use an **unordered_set** to store unique elements from the first array.
        - Iterate through the second array and check if the element exists in the set.
        - If found, add it to the result and remove it from the set to avoid duplicates.

    Returns:
        - A vector containing the unique intersection of the two arrays.

    Time Complexity:
        - **O(n + m)** (where n and m are the sizes of the two arrays, using set operations efficiently)

    Space Complexity:
        - **O(min(n, m))** (storing the smaller array in a set)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find the intersection of two arrays
vector<int> intersection(const vector<int>& a, const vector<int>& b) {
    unordered_set<int> as_set(a.begin(), a.end()); // Store unique elements of 'a'
    vector<int> res;
    
    for (int element : b) {
        if (as_set.count(element)) {
            res.push_back(element);
            as_set.erase(element); // Remove to ensure uniqueness in result
        }
    }
    
    return res;
}

int main() {
    vector<int> a = {1, 2, 2, 3, 4};
    vector<int> b = {2, 3, 3, 5};
    
    vector<int> result = intersection(a, b);
    
    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
