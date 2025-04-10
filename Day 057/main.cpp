/*
    Title: Count Distinct Elements in Every Subarray of Given Size (Sliding Window)

    Problem Statement:
        - Given an array of integers and a window size `target`,
          return the count of distinct elements in each subarray of size `target`.

    Approach:
        - Use the sliding window technique to traverse the array.
        - Maintain a frequency map for elements within the current window.
        - Update the map as the window slides, adding new elements and removing old ones.

    Time Complexity:
        - **O(n)** — Each element is added and removed at most once.

    Space Complexity:
        - **O(k)** where k is the size of the window (target).

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Count distinct elements in each sliding window of size 'target'
vector<int> countDistinct(vector<int> arr, int target) {
    int n = arr.size();
    vector<int> res;
    unordered_map<int, int> freq;

    // Initialize the frequency map for the first window
    for (int i = 0; i < target; i++) {
        freq[arr[i]]++;
    }
    
    // Add the distinct count of the first window
    res.push_back(freq.size());
    
    // Slide the window across the array
    for (int i = target; i < n; i++) {
        // Add the new element to the window
        freq[arr[i]]++;
        
        // Remove the old element from the window
        freq[arr[i - target]]--;
        if (freq[arr[i - target]] == 0) {
            freq.erase(arr[i - target]);
        }
        
        // Add the count of distinct elements in the current window
        res.push_back(freq.size());
    }
    
    return res;
}

int main() {
    vector<int> arr = {1, 4, 4, 4, 5, 3, 3, 8, 9, 11};
    int target = 4;  // Window size
    
    vector<int> result = countDistinct(arr, target);
    
    cout << "Distinct elements in each window of size " << target << " are: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
