/* 
    Title: Maximum Loot from Houses in a Circular Arrangement 
           (House Robber II - Recursion + Memoization)

    Problem Statement:
        - You are given an array `arr[]` where each element represents the 
          amount of money in a house.
        - Houses are arranged in a circular manner.
        - Constraint: You cannot rob two adjacent houses.
        - Since the first and last house are also adjacent in circular arrangement,
          both cannot be robbed together.
        - Find the maximum amount of money you can loot.

    Example:
        Input:
            arr = [100, 20, 3, 50, 30, 70]
        Output:
            190
        Explanation:
            - Rob house 0 (100) + house 3 (50) + house 5 (70) → 220 (valid, 
              but circular constraint excludes first and last together).
            - Instead:
                Option 1 → Exclude last house: [100, 20, 3, 50, 30] → 180
                Option 2 → Exclude first house: [20, 3, 50, 30, 70] → 190
            - Answer = max(180, 190) = 190

    Approach:
        - Break the circular problem into two linear problems:
            1. Exclude last house → Rob from arr[0] to arr[n-2]
            2. Exclude first house → Rob from arr[1] to arr[n-1]
        - Apply standard House Robber (linear DP with memoization) on both.
        - Return the maximum of the two cases.

    Recurrence:
        maxLoot(i) = max(arr[i] + maxLoot(i-2), maxLoot(i-1))

    Base Cases:
        - If n == 1 → return arr[0]
        - If n == 2 → return max(arr[0], arr[1])

    Time Complexity:
        - O(n), since each house is processed once.

    Space Complexity:
        - O(n), for memoization arrays.

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<vector>
using namespace std;

int maxLoot(vector<int>& arr, vector<int> &memo, int n ){
        if(n<0){
            return 0;
        }
        if(n==0){
            return arr[0];
        }
        if(n==2){
            return max(arr[0],arr[1]);
        }
        
        
        if(memo[n]!=-1){
            return memo[n];
        }
        
        memo[n] = max(maxLoot(arr,memo,n-2)+arr[n-1],maxLoot(arr,memo,n-1));
        return memo[n];
        
    }
int maxValue(vector<int>& arr) {
    int n = arr.size();
    if(n==1){
        return arr[0];
    }
    vector<int> memo1(n,-1);
    vector<int> memo2(n,-1);
    
    vector<int> arr1(arr.begin(),arr.end()-1);
    vector<int> arr2(arr.begin()+1,arr.end());
    
    int res1=maxLoot(arr1,memo1,n-1);
    int res2=maxLoot(arr2,memo2,n-1);
    
    return max(res1,res2);
    
}
    
int main(){
    
    vector<int> house={100,20,3,50,30,70};
    cout<<"Maximum amount can be looted if they are arranged in circular manner (assuming no two adjacent house cna be looted) : "<<maxValue(house);
    return 0;
}
