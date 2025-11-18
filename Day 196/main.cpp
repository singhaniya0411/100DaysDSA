/*
    Title: Count X-Axis Crossings in a Cumulative Sum Graph

    Problem Statement:
        - You are given an integer array representing values added sequentially.
        - Imagine plotting a graph of the cumulative sum of this array.
        - You must count how many times the cumulative-sum curve
          **touches or crosses the X-axis**.

        Example:
            arr = {1, -4, 2, -9, 10}
            
            Cumulative sum:
                1  → above X-axis
               -3  → crossed from + to -
               -1  → stays below
               -10 → stays below
                0  → crosses from - to 0

            Crossings = 2

    Approach:
        1. Maintain a running cumulative sum.
        2. Each step, check whether adding the next value *changes the sign*
           or brings the cumulative sum exactly to zero.
           
           Cases:
                - If current sum > 0 and next causes ≤ 0 → crossing occurs.
                - If current sum < 0 and next causes ≥ 0 → crossing occurs.

        3. Increase count whenever such a sign change happens.
        4. Return the total number of crossings.

    Dry Run:
        arr = {1, -4, 2}
        
        sum = 0
        i=0: sum=1      (above)
        i=1: 1 + (-4) = -3  → crosses ✓
        i=2: -3 + 2 = -1    → no cross

        Result = 1

    Time Complexity:
        - O(N), single pass.

    Space Complexity:
        - O(1), constant extra memory.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int touchedAxis(vector<int> &arr){
    int res = 0,sum = 0;
    int size = arr.size();
    for(int i = 0;i<size;i++){
        if(sum>0 && sum+arr[i]<=0){
            res++;
        }
        else if(sum<0 && sum+arr[i]>=0){
            res++;
        }
        sum+=arr[i];
    }
    return res;
}

int main(){
    vector<int> arr = {1,-4,2,-9,10,3,-5,2,-7,-6,11};
    cout<<"Number of times graph cuts the X-axis : "<<touchedAxis(arr);
    return 0;
}
