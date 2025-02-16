/*
    Title: Merging Overlapping Intervals
    Description:
        - This program merges overlapping intervals when a **new interval** is inserted into a sorted list.
        - If intervals overlap, they are merged into a single interval.

    Approach:
        - Insert the new interval into the existing list.
        - Sort the list based on start times.
        - Merge overlapping intervals by comparing end times.

    Time Complexity:
        - **O(n log n)** (Due to sorting)
        - **O(n)** (Merging process)
        - **Overall: O(n log n)**

    Space Complexity:
        - **O(n)** (To store the merged intervals)

    Author: Vishal Singhaniya
*/

#include <vector>
#include <algorithm>
#include <iostream>
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

// Function to merge intervals after inserting a new interval
vector<Interval> merge_intervals(vector<Interval> intervals, Interval newInterval)
{
    // Case when the interval list is empty
    if (intervals.empty())
    {
        return {newInterval};
    }

    // Step 1: Insert the new interval and sort based on start times
    intervals.push_back(newInterval);
    sort(intervals.begin(), intervals.end(), comparison);

    // Step 2: Merging intervals
    vector<Interval> merged;
    merged.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++)
    {
        Interval &lastMerge = merged.back();

        // If current interval overlaps with the last merged interval, merge them
        if (intervals[i].start <= lastMerge.end)
        {
            lastMerge.end = max(lastMerge.end, intervals[i].end);
        }
        // Otherwise, add a new interval to the merged list
        else
        {
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}

// Function to print merged intervals
void printIntervals(vector<Interval> intervals)
{
    for (auto interval : intervals)
    {
        cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    cout << endl;
}

// Driver function
int main()
{
    // Input: Existing intervals (Can be modified for testing)
    vector<Interval> intervals = {{1, 3}, {5, 7}, {8, 12}};

    // New interval to be inserted
    Interval newInterval = {4, 10};

    // Merging the intervals
    vector<Interval> merged = merge_intervals(intervals, newInterval);

    // Output: Merged intervals
    cout << "Merged Intervals: ";
    printIntervals(merged);

    return 0;
}
