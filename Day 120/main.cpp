/* 
    Title: Minimum Jumps to Reach End of Array (Dynamic Programming - Tabulation).

    Problem Statement:
        - You are given an array `arr[]` of size `n`.
        - Each element `arr[i]` represents the maximum number of steps 
          you can jump forward from index `i`.
        - Starting from index 0, find the **minimum number of jumps** 
          required to reach the last index.
        - If the last index cannot be reached, return -1.

    Example:
        Input:
            arr = [1, 3, 2, 1, 4]
        Output: 2
        Explanation:
            - Start at index 0 → jump 1 step to index 1
            - From index 1 (value = 3) → jump directly to index 4 (last index)
            - Minimum jumps = 2

    Approach:
        - Use bottom-up DP (tabulation):
            1. Initialize `dp[i]` as the minimum jumps required to reach index `i`.
            2. Base case: `dp[0] = 0` (already at start).
            3. For each index `i`, check all previous indices `j < i`.
                - If `arr[j] + j >= i` (i.e., `i` is reachable from `j`),
                  update `dp[i] = min(dp[i], dp[j] + 1)`.
            4. Final answer = `dp[n-1]` (min jumps to reach last index).
            5. If `dp[n-1]` is still infinity → return -1.

    Time Complexity:
        - O(n²), due to nested loops.

    Space Complexity:
        - O(n), for the DP table.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
using namespace std;


int minJumps(vector<int> &arr){
    int n=arr.size();
    vector<int> dp(n,n+1);
    
    dp[0]=0;
    for(int i =1;i<n;i++){
        for(int j = 0;j<i;j++){
            if(arr[j]+j>=i){
                dp[i]=min(dp[i],dp[j]+1);
            }
        }
    }
    
    if(dp[n-1]==n+1){
        return -1;
    }
    
    return dp[n-1];
    
    
}
int main(){
    vector<int> arr = {1,3,2,4,5,2,3,1,9,3,2,1,3,2,1};
    cout<<"No of minimum jumps to reach the end of the array :"<<minJumps(arr);
    return 0;
}
