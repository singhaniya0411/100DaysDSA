/*
    Title: Last Moment Before All Ants Fall Off a Plank.

    Problem Statement:
        - A number of ants are walking on a plank of length `n`.
        - Each ant moves at a constant speed of 1 unit per second.
        - Some ants move to the left, others to the right.
        - When two ants meet, they effectively just pass through each other (swap directions),
          which means the result is the same as if they keep walking independently.
        - Find the **last moment (time)** before all ants fall off the plank.

    Approach:
        - For ants moving to the left:
              Time to fall = distance to left edge = position of ant.
        - For ants moving to the right:
              Time to fall = distance to right edge = (n - position).
        - The last moment when the final ant falls off = 
              max(max(left positions), max(n - right positions)).

    Example:
        Input:
            n = 4
            left = [2]
            right = [0, 1, 3]

        Process:
            - Ants moving left:
                * From position 2 → falls in 2 seconds
            - Ants moving right:
                * From position 0 → falls in 4 seconds
                * From position 1 → falls in 3 seconds
                * From position 3 → falls in 1 second
            - Maximum of all times = max(2, 4, 3, 1) = 4

        Output:
            Last moment until all ants fall from plank : 4

    Time Complexity:
        - O(L + R), where L = number of left-moving ants, R = number of right-moving ants.

    Space Complexity:
        - O(1), constant auxiliary space.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

int getLastMoment(int n ,vector<int> &left, vector<int>& right){
    int res = 0;
    for(int i =0;i<left.size();i++){
        res = max(res,left[i]);
    }
    
    for(int i =0;i<right.size();i++){
        res=max(res,n-right[i]);
    }
    
    return res;
}

int main(){
    int n = 4;
    vector<int> left = {2};
    vector<int> right = {0,1,3};
    
    cout<<"Last moment until all ants would get fall from plank : "<<getLastMoment(n,left,right);
    return 0;
    
}
