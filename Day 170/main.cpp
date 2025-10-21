/*
    Title: Meeting Room Scheduler – Check if All Meetings Can Be Attended.

    Problem Statement:
        - You are given an array of meeting time intervals where each interval is represented as [start, end].
        - Determine if a person can attend all meetings without any overlap.
        - If any two meetings overlap, return false; otherwise, return true.

    Approach:
        1. Sort all meeting intervals based on their start times.
        2. Iterate through the sorted intervals and compare the start time of the current meeting
           with the end time of the previous meeting.
        3. If `arr[i][0] < arr[i-1][1]`, there is an overlap → return false.
        4. If no overlaps are found after checking all intervals, return true.

    Example:
        Input:
            arr = {{1,5}, {8,10}, {6,7}}

        Process:
            - Sort intervals → {{1,5}, {6,7}, {8,10}}
            - Compare consecutive intervals:
                (6 < 5)? No
                (8 < 7)? No → No overlap found.

        Output:
            ✅ The person can attend all meetings.

    Time Complexity:
        - Sorting: O(N log N)
        - Checking overlaps: O(N)
        - Total: O(N log N)

    Space Complexity:
        - O(1), as we use only constant extra space.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

bool canAttend(vector<vector<int>> &arr){
    sort(arr.begin(), arr.end());
    
    for(int i = 1; i < arr.size(); i++){
        if(arr[i][0] < arr[i-1][1]){
            return false;
        }
    }
    return true;
}

int main(){
    vector<vector<int>> arr = {{1,5},{8,10},{6,7}};
    cout << "\nThe person " << (canAttend(arr) ? "can" : "can't") << " attend the meeting\n";
    return 0;
}





