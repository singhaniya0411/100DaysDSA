/*
    Title: Minimum Removals to Make Intervals Non-Overlapping (O(n log n) Approach)

    Description:
        - This program determines the minimum number of intervals to be removed
          to make the remaining intervals non-overlapping.
        - Two intervals [a, b] and [c, d] overlap if `c < b`.

    Approach:
        1. **Sort the intervals** based on their end time using a greedy approach.
        2. **Iterate** through the sorted list and keep track of the current interval's end.
        3. **Count overlapping intervals** that need to be removed.

    Time Complexity:
        - **O(n log n)** (Sorting step dominates)

    Space Complexity:
        - **O(1)** (In-place processing)

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

    // Constructor to initialize an interval
    Interval(int s, int e)
    {
        start = s;
        end = e;
    }
};

// Comparator function to sort intervals based on their end time (Greedy approach)
bool comparison(Interval a, Interval b)
{
    return a.end < b.end; // Sort intervals in increasing order of their end time
}

// Function to calculate the minimum number of intervals to remove
int min_overlap(vector<Interval> &intervals)
{
    if (intervals.empty())
        return 0; // Edge case: No intervals

    // Step 1: Sort intervals by their end time
    sort(intervals.begin(), intervals.end(), comparison);

    int count = 0;                     // Stores number of intervals removed
    int currEnding = intervals[0].end; // Track the end of the last included interval

    // Step 2: Traverse through the intervals
    for (size_t i = 1; i < intervals.size(); i++)
    {
        if (currEnding > intervals[i].start)
        {
            // Overlapping case: Remove one interval
            currEnding = min(currEnding, intervals[i].end);
            count++;
        }
        else
        {
            // No overlap: Update current ending time
            currEnding = intervals[i].end;
        }
    }

    // Step 3: Return the count of removed intervals
    return count;
}

// Driver function
int main()
{
    // Input: List of intervals
    vector<Interval> intervals = {{1, 3}, {2, 4}, {3, 6}, {7, 9}, {10, 12}};

    // Function call to compute minimum removals
    int result = min_overlap(intervals);

    // Output the result
    cout << "Minimum removals required to make intervals non-overlapping: " << result << endl;

    return 0;
}
