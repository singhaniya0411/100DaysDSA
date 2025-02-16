/*
    Title: Merging Overlapping Intervals (O(n log n) Approach)

    Description:
        - This program merges overlapping intervals in a given list.
        - Two intervals [a, b] and [c, d] are overlapping if `c ≤ b`.
        - The result contains **non-overlapping merged intervals**.

    Approach:
        1. **Sort the intervals** by their start times.
        2. **Iterate** through the sorted list and merge overlapping intervals.
        3. Store and print the **merged intervals**.

    Time Complexity:
        - **O(n log n)** (Sorting step dominates)

    Space Complexity:
        - **O(n)** (Storing merged intervals)

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Class representing an interval with start and end times
class Interval
{
public:
    int start, end;
};

// Comparator function to sort intervals based on the start time
bool comparison(Interval a, Interval b)
{
    return a.start < b.start;
}

// Function to merge overlapping intervals
void merge_overlapping_intervals(vector<Interval> intervals)
{
    if (intervals.empty())
        return;

    // Step 1: Sort intervals by start time
    sort(intervals.begin(), intervals.end(), comparison);

    // Step 2: Merging intervals
    vector<Interval> result;
    result.push_back(intervals[0]); // Push first interval

    for (int i = 1; i < intervals.size(); i++)
    {
        Interval &lastInterval = result.back(); // Get last merged interval

        if (intervals[i].start <= lastInterval.end)
        {
            // Overlapping case: merge by updating end time
            lastInterval.end = max(intervals[i].end, lastInterval.end);
        }
        else
        {
            // Non-overlapping case: add new interval to result
            result.push_back(intervals[i]);
        }
    }

    // Step 3: Print merged intervals
    cout << "Merged Intervals: ";
    for (auto i : result)
    {
        cout << "[" << i.start << ", " << i.end << "] ";
    }
    cout << endl;
}

// Driver function
int main()
{
    // Input: List of intervals (Modify for testing)
    vector<Interval> intervals = {{1, 3}, {2, 4}, {3, 6}, {7, 9}, {10, 12}};

    // Function call to merge intervals
    merge_overlapping_intervals(intervals);

    return 0;
}
