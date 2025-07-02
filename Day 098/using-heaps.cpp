/*
    Title: Running Median of a Stream (Optimized using Heaps)

    Problem Statement:
        - Given a stream of integers, return the median after every new integer is inserted.
        - Median:
            - If count is odd: middle value.
            - If even: average of two middle values.

    Approach:
        - Use two heaps:
            - Max Heap (for the smaller half of elements)
            - Min Heap (for the larger half of elements)
        - Always balance both heaps such that their sizes differ by at most 1.
        - Median will be:
            - Top of max heap if it has more elements.
            - Average of tops of both heaps if sizes are equal.

    Time Complexity:
        - O(n log n), where n is the number of elements (each insertion and balancing takes log n).

    Space Complexity:
        - O(n), for storing elements in heaps.

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<double> getMedian(vector<int> &arr) {
    vector<double> result;
    
    priority_queue<int> max_heap; // max heap for left half
    priority_queue<int, vector<int>, greater<int>> min_heap; // min heap for right half
    
    for (int i = 0; i < arr.size(); i++) {
        // Step 1: Insert into appropriate heap
        if (max_heap.empty() || arr[i] <= max_heap.top()) {
            max_heap.push(arr[i]);
        } else {
            min_heap.push(arr[i]);
        }

        // Step 2: Balance both heaps
        if (max_heap.size() > min_heap.size() + 1) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else if (min_heap.size() > max_heap.size()) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        // Step 3: Find median
        if (min_heap.size() == max_heap.size()) {
            double median = (max_heap.top() + min_heap.top()) / 2.0;
            result.push_back(median);
        } else {
            result.push_back(max_heap.top()); // max_heap will have more elements
        }
    }

    return result;
}

// Main for testing
int main() {
    vector<int> arr = {5, 15, 1, 3, 2, 8};
    vector<double> medians = getMedian(arr);

    cout << "Running Median: ";
    for (double m : medians) {
        cout << m << " ";
    }
    cout << endl;

    return 0;
}
