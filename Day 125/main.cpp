/* 
    Title: Maximum Loot from Non-Adjacent Houses (House Robber Problem).
    
    Problem Statement:
        - You are given an array `arr[]` where each element represents the 
          amount of money stored in a house.
        - You cannot rob two adjacent houses (to avoid alerting the police).
        - Find the maximum amount of money you can loot.

    Example:
        Input:
            arr = [10, 15, 20, 5, 60, 10, 80]
        Output:
            165
        Explanation:
            - Rob house 0 (10) + house 2 (20) + house 4 (60) + house 6 (80) 
              = 170 
            - Another option: house 1 (15) + house 4 (60) + house 6 (80) 
              = 155
            - Optimal = 170 (but depending on array it varies).
              (Your code’s logic will compute this optimal solution.)

    Approach:
        - Use recursion with memoization:
            • State: maxLootRec(i) = maximum money looted from first `i` houses.
            • Choices:
                - Rob current house → arr[i] + maxLootRec(i-2)
                - Skip current house → maxLootRec(i-1)
                - Take the maximum of both.
        - Use a memo array to store already computed results.

    Base Cases:
        - If n == 0 → loot = arr[0]
        - If n == 1 → loot = max(arr[0], arr[1])

    Time Complexity:
        - O(n), since each house is computed once.

    Space Complexity:
        - O(n) for memoization.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxLootRec(vector<int>& arr,int n , vector<int> &memo){
    if(n==0){
        return arr[0];
    }
    if(n==2){
        return max(arr[0],arr[1]);
    }
    
    if(memo[n]!=-1){
        return memo[n];
    }
    
    memo[n] = max(arr[n-1]+maxLootRec(arr,n-2,memo),maxLootRec(arr,n-1,memo));
    
    return memo[n];
}

int maxLoot(vector<int> &arr){
    int n = arr.size();
    
    vector<int> memo(n+1,-1);
    
    memo[n] = maxLootRec(arr,n,memo);
    return memo[n];
}

int main(){
    
    vector<int> prices= {10,15,20,5,60,10,80};
    cout<<"Maximum loot can be achieve is "<<maxLoot(prices);
    return 0;

}






