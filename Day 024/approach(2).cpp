/*
    Title: Merging Overlapping Intervals (Optimized O(n) Approach)
    
    Description:
        - This program merges overlapping intervals when a **new interval** is inserted into a sorted list.
        - It efficiently merges without sorting, reducing the complexity to **O(n)**.

    Approach:
        - Traverse the sorted interval list in **one pass**.
        - **Three cases**:
            1. Non-overlapping intervals (before new interval) → Directly add them.
            2. Overlapping intervals → Merge by adjusting start & end values.
            3. Remaining non-overlapping intervals (after merging) → Add them directly.
    
    Time Complexity:
        - O(n) (Single pass traversal)

    Space Complexity:
        - O(n) (For storing merged intervals)

    Author: Vishal Singhaniya
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// Class representing an interval with start and end times
class Interval {
public:
    int start, end;
};

// Function to merge intervals after inserting a new interval
vector<Interval> merge_intervals(vector<Interval> intervals, Interval newInterval) {
    vector<Interval> result;
    int i = 0, n = intervals.size();

    // Step 1: Add all intervals before the new interval (Non-overlapping)
    while (i < n && intervals[i].end < newInterval.start) {
        result.push_back(intervals[i]);
        i++;
    }

    // Step 2: Merge overlapping intervals
    while (i < n && intervals[i].start <= newInterval.end) {
        newInterval.start = min(newInterval.start, intervals[i].start);
        newInterval.end = max(newInterval.end, intervals[i].end);
        i++;
    }
    result.push_back(newInterval); // Insert the merged interval

    // Step 3: Add remaining intervals (Non-overlapping ones after merging)
    while (i < n) {
        result.push_back(intervals[i]);
        i++;
    }
    
    return result;
}

// Function to print merged intervals
void printIntervals(vector<Interval> intervals) {
    for (auto interval : intervals) {
        cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    cout << endl;
}

// Driver function
int main() {
    // Input: Existing sorted intervals (Can be modified for testing)
    vector<Interval> intervals = {{1, 3}, {4, 5}, {6, 7}, {8, 10}};

    // New interval to be inserted
    Interval newInterval = {5, 6};

    // Merging the intervals
    vector<Interval> merged = merge_intervals(intervals, newInterval);

    // Output: Merged intervals
    cout << "Merged Intervals: ";
    printIntervals(merged);

    return 0;
}
