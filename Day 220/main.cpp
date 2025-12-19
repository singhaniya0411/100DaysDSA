/*
    Title: Meeting Room with Maximum Bookings (Priority Queue Simulation)

    Problem Statement:
        - You are given `n` meeting rooms, indexed from 0 to n-1.
        - You are also given a list of meetings, where each meeting is represented
          as [startTime, endTime].
        - Meetings must be scheduled using the following rules:
            1. A meeting is assigned the smallest-indexed available room.
            2. If no room is available, the meeting is delayed until the earliest
               room becomes free.
            3. Delayed meetings keep the same duration.
        - Return the index of the room that gets booked the maximum number of times.
        - If there is a tie, return the smallest room index.

    Example:
        Input:
            n = 2
            meetings = {{0,10}, {1,5}, {2,7}, {3,4}}

        Output:
            0

        Explanation:
            - Room 0 hosts meetings at [0,10], [10,15]
            - Room 1 hosts meetings at [1,5], [5,9]
            - Room 0 is booked more times → answer = 0

    Approach (Greedy + Priority Queues):
        1. Sort meetings by start time.
        2. Maintain two priority queues:
            - `available` → min-heap of free room indices.
            - `occupied` → min-heap storing {endTime, roomIndex}.
        3. For each meeting:
            - Free rooms whose meetings have ended.
            - If a room is available:
                assign the meeting to it.
            - Else:
                delay the meeting until the earliest room frees up.
        4. Count how many times each room is used.
        5. Return the room with maximum usage.

    Dry Run:
        meetings = {{0,10}, {1,5}, {2,7}}
        rooms = {0,1}

        Meeting [0,10] → room 0
        Meeting [1,5]  → room 1
        Meeting [2,7]  → delayed → room 1 at time 5

        Usage count:
            room 0 → 1
            room 1 → 2

        Output → 1

    Time Complexity:
        - O(m log n), where:
            m = number of meetings
            n = number of rooms

    Space Complexity:
        - O(n), for priority queues and counters.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

int mostBooked(int n, vector<vector<int>> &meetings) {
    vector<int> cnt(n,0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> occ;
    priority_queue<int, vector<int>, greater<int>> avail;

    for(int i = 0 ; i < n ; i++){
        avail.push(i);
    }

    sort(meetings.begin(), meetings.end());

    for(auto &m : meetings){
        int s = m[0];
        int e = m[1];

        while(!occ.empty() && occ.top().first <= s){
            avail.push(occ.top().second);
            occ.pop();
        }

        if(!avail.empty()){
            int room = avail.top();
            avail.pop();
            occ.push({e, room});
            cnt[room]++;
        }
        else{
            auto [endTime, room] = occ.top();
            occ.pop();
            occ.push({endTime + (e - s), room});
            cnt[room]++;
        }
    }

    int res = 0;
    for(int i = 1; i < n; i++){
        if(cnt[i] > cnt[res]){
            res = i;
        }
    }

    return res;
}

int main(){
    int n = 2;
    vector<vector<int>> meetings = {{0,10}, {1,5}, {2,7}, {3,4}};

    cout << "Room with maximum bookings: "
         << mostBooked(n, meetings) << "\n";

    return 0;
}














