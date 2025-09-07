/* 
    Title: Activity Selection Problem (Greedy Approach)

    Problem Statement:
        - You are given two arrays:
            • start[] → starting times of activities
            • finish[] → finishing times of activities
        - Task: Select the maximum number of activities that can be performed 
          by a single person such that no two activities overlap.

    Example:
        Input:
            start  = {1, 3, 0, 5, 8, 5}
            finish = {2, 4, 6, 7, 9, 9}
        Output:
            4
        Explanation:
            One possible set of non-overlapping activities: 
            {(1,2), (3,4), (5,7), (8,9)}

    Approach:
        - Step 1: Pair each activity as (finish, start) for easier sorting.
        - Step 2: Sort activities by finish time (earliest finish first).
        - Step 3: Traverse sorted activities:
            • Select an activity if its start time is greater than the finish 
              time of the last selected activity.
        - Step 4: Count all such selections → maximum number of activities.

    Time Complexity:
        - O(n log n), due to sorting.
    
    Space Complexity:
        - O(n), for storing activity pairs.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int activitySelction(vector<int>& start, vector<int>& finish){
    int n = start.size();
    
    vector<pair<int,int>> act ; 
    
    for(int i = 0;i<n;i++){
        act.push_back({finish[i],start[i]});
    }
    
    sort(act.begin(),act.end());
    
    int res = 0;
    int last = -1;
    
    for(int i =0;i<n; i++){
        if(act[i].second>last){
            res++;
            last=act[i].first;
        }
    }
    
    return res;
}

int main(){
    
    vector<int> start = {1,3,0,5,8,5};
    vector<int> finish = {2,4,6,7,9,9};
    
    cout<<"Maximum activity can be done without overlapping : ";
    cout<<activitySelction(start,finish);
    
    return 0;
}
