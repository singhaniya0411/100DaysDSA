/*
    Title: Minimum Number of Meeting Rooms Required

    Problem Statement:
        - You are given two arrays:
            1. `start[]` → start times of meetings
            2. `end[]`   → end times of meetings
        - Each meeting requires one room.
        - Find the minimum number of meeting rooms required so that no meetings overlap.

    Example:
        Input:
            start = [2, 9, 6]
            end   = [4, 12, 10]

        Meetings:
            (2,4), (6,10), (9,12)

        Output:
            Number of room required to conduct these meetings : 2

    Approach:
        1. Sort both `start` and `end` arrays.
        2. Use two pointers:
            - `i` for start times
            - `j` for end times
        3. Traverse meetings:
            - If a meeting starts before the previous one ends → need a new room.
            - Else → free a room.
        4. Keep track of:
            - `room` → current rooms in use
            - `res`  → maximum rooms needed at any point.

    Dry Run:
        Sorted start = [2, 6, 9]
        Sorted end   = [4, 10, 12]

        i=0, j=0 → 2 < 4 → room=1
        i=1, j=0 → 6 >= 4 → room=0
        i=1, j=1 → 6 < 10 → room=1
        i=2, j=1 → 9 < 10 → room=2  ✅

        Maximum rooms needed = 2

    Time Complexity:
        - O(n log n) due to sorting.

    Space Complexity:
        - O(1) extra space (ignoring input arrays).

    Applications:
        - Scheduling systems
        - Conference room allocation
        - CPU task scheduling.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<int>& start, vector<int>& end){
    int n = start.size();
    int room = 0;
    int res = 0;
    
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    
    int i = 0,j=0;
    
    while(i<n){
        if(start[i]<end[j]){
            room++;
            i++;
        }
        else{
            room--;
            j++;
        }
        
        res = max(res,room);
    }
    return res;
}

int main(){
    vector<int> start = {2,9,6};
    vector<int> end = {4,12,10};
    cout<<"Number of room required to conduct these meetings : "<<minMeetingRooms(start,end);
    return 0;
}
