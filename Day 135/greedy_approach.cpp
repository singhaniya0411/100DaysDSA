/*
    Title: Job Sequencing Problem (Greedy - Slot Allocation Method).

    Problem Statement:
        - You are given two arrays:
            • deadline[i] → the last time unit by which job i must be completed
            • profit[i]   → the profit earned if job i is completed on or before its deadline
        - Each job takes exactly 1 unit of time to complete.
        - The objective is to maximize both:
            1. The number of jobs completed
            2. The total profit earned

    Example:
        Input:
            deadline = {2, 1, 2, 1, 3}
            profit   = {100, 19, 27, 25, 15}
        Output:
            Jobs Done = 2, Maximum Profit = 127
        Explanation:
            Possible schedule: Job1 (profit 100, deadline 2), Job3 (profit 27, deadline 2)

    Approach:
        - Step 1: Pair each job as (profit, deadline).
        - Step 2: Sort jobs in descending order of profit.
        - Step 3: Create a slot array of size = max(deadline), initialized with -1 (empty).
        - Step 4: For each job:
            • Find the latest available slot ≤ job's deadline.
            • If found, schedule the job in that slot and add its profit.
        - Step 5: Return total jobs scheduled and total profit.

    Time Complexity:
        - Sorting jobs: O(n log n)
        - Scheduling jobs: O(n * maxDeadline)
        - Overall worst case: O(n * maxDeadline)

    Space Complexity:
        - O(maxDeadline), for slot allocation.

    Output:
        Returns a vector<int> of size 2:
            • ans[0] → number of jobs completed
            • ans[1] → maximum profit earned

    Author: Vishal Singhaniya
*/

#include <stdio.h>
#include<functional>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;



vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    vector<pair<int,int>> pairJobs;
    
    int n = deadline.size();
    
    for(int i = 0;i<n;i++){
        pairJobs.push_back({profit[i],deadline[i]});
    }
    
    sort(pairJobs.begin(),pairJobs.end(),[](auto &a,auto &b){
        return a.first>b.first;
    });
    
    int maxDeadline = *max_element(deadline.begin(),deadline.end());
    
    vector<int> slot (maxDeadline,-1);
    
    int res = 0;
    int count = 0;
    for(int i = 0;i<n;i++){
        for(int j = pairJobs[i].second-1;j>=0;j--){
            if(slot[j]==-1){
                slot[j]=i;
                count++;
                res+=pairJobs[i].first;
                break;
            }
        }
        
        
    }
    return {count,res};
    
}
int main()
{
    vector<int> deadline = {4,1,1,1};
    vector<int> profit = {20,10,40,30};
    vector<int> answer = jobSequencing(deadline,profit);
    
    for(int i = 0;i<answer.size();i++){
        cout<<answer[i];
    }

    return 0;
}
