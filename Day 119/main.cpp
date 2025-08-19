 /* 
    Title: Minimum Coin Change Problem (Dynamic Programming - Memoization)

    Problem Statement:
        - You are given:
            1. An array `coins[]` where each element represents the denomination of a coin.
            2. An integer `sum` representing the target value.
        - Find the minimum number of coins required to make the target sum.
        - If the target sum cannot be formed using given coins, return -1.
        - Each coin can be used **infinite times**.

    Example:
        Input:
            coins = [1, 2, 5], sum = 11
        Output: 3
        Explanation:
            11 = 5 + 5 + 1  (minimum 3 coins)

    Approach:
        - Use recursion + memoization (top-down DP):
            - Define minCoin(coins, n, sum):
                1. If sum < 0 → invalid → return INF.
                2. If sum == 0 → return 0 (no coins needed).
                3. If n == 0 → no coins left → return INF.
                4. If result already in memo → return it.
                5. Choices:
                    - Take coin[n-1] → 1 + minCoin(coins, n, sum - coins[n-1]).
                    - Skip coin[n-1] → minCoin(coins, n-1, sum).
                6. Store and return the minimum of both choices.

    Time Complexity:
        - O(n * sum), since each state is computed once.

    Space Complexity:
        - O(n * sum) for memoization table.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
using namespace std;

 
const int inf = 1e9;
int minCoin(vector<int>&coins,int n,vector<vector<int>> &memo,int sum){
    
    if(sum<0){
        return inf;
    }
    if(sum==0){
        return 0;
    }
    
    if(n==0){
        return inf;
    }
    
    if(memo[n][sum]!=-1){
        return memo[n][sum];
    }
    
    int take = minCoin(coins,n,memo,sum-coins[n-1]);
    if(take!=inf){
        take++;
    }
    
    int notTake = minCoin(coins,n-1,memo,sum);
    
    memo[n][sum] = min(take,notTake);
    return memo[n][sum];
}



int minCoins(vector<int> &coins, int sum) {
    // code here
    int n = coins.size();
    
    vector<vector<int>> memo (n+1,vector<int>(sum+1,-1));
    
    memo[n][sum]=minCoin(coins,n,memo,sum);
    if(memo[n][sum]==inf){
        return -1;
    }
    
    return memo[n][sum];
}

int main(){
    
    vector<int> coins = {10,5,25};
    int sum = 30;
    cout<<"minimum coins needed to be exchanged : "<<minCoins(coins,sum);
    return 0;
}
