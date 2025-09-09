/*
    Title: Job Sequencing Problem with Deadlines (Greedy + Min Heap)

    Problem Statement:
        - You are given two arrays:
            • deadline[i] → last time slot by which job i should be completed
            • profit[i]   → profit earned if job i is completed before or on its deadline
        - Task: Find the maximum number of jobs that can be done and the maximum 
          profit achievable, assuming each job takes exactly 1 unit of time.

    Example:
        Input:
            deadline = {2, 2, 1, 3, 3}
            profit   = {100, 19, 27, 25, 15}
        Output:
            Jobs Done = 3, Maximum Profit = 152
        Explanation:
            Possible schedule: Job1 (profit 100), Job3 (profit 27), Job4 (profit 25)

    Approach:
        - Step 1: Pair jobs as (deadline, profit) and sort them by deadline.
        - Step 2: Use a min-heap (priority_queue with greater<>) to keep track 
                  of selected job profits.
        - Step 3: For each job:
            • If the number of jobs in heap < deadline, push profit.
            • Else if the smallest profit in heap is less than current job profit, 
              replace it with the current job (better profit optimization).
        - Step 4: Count jobs in heap and sum their profits → final result.

    Time Complexity:
        - O(n log n), due to sorting and heap operations.
    
    Space Complexity:
        - O(n), for storing jobs in heap.

    Output:
        Returns a vector<int> of size 2:
            • ans[0] → number of jobs completed
            • ans[1] → maximum profit earned

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;


vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
    
    int n = deadline.size();
    priority_queue<int,vector<int>,greater<int>> pq;
    
    vector<pair<int,int>> jobs;
    
    for(int i = 0;i<n;i++){
        jobs.push_back({deadline[i],profit[i]});
    }
    
    sort(jobs.begin(),jobs.end());
    
    for(int i =0;i<n;i++){
        if(jobs[i].first>(int)pq.size()){
            pq.push(jobs[i].second);
        }else if(!pq.empty() && pq.top() < jobs[i].second){
            pq.pop();
            pq.push(jobs[i].second);
        }
    }
    
    vector<int> ans = {0,0};
    while(!pq.empty()){
        ans[0]+=1;
        ans[1]+=pq.top();
        pq.pop();
    }
    return ans;
}

int main(){
    
    vector<int> deadline = {2,1,2,1,1};
    vector<int> profit = {100,19,27,25,15};
    
    vector<int> result = jobSequencing(deadline,profit);
    
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<"   ";
    }
    return 0;
}
