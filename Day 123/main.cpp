/* 
    Title: Best Time to Buy and Sell Stock IV (Recursion + Memoization).

    Problem Statement:
        - You are given an array `prices[]` where `prices[i]` is the price of a stock on day `i`.
        - You are also given an integer `k`, the maximum number of allowed transactions.
        - A transaction is defined as one buy and one sell.
        - Find the maximum profit you can achieve under these constraints.

    Example:
        Input:
            prices = [10, 50, 5, 800], k = 2
        Output:
            Maximum profit which can be acheived : 835
        Explanation:
            Buy on day 0 at price 10, sell on day 1 at price 50 → profit = 40
            Buy on day 2 at price 5, sell on day 3 at price 800 → profit = 795
            Total profit = 835

    Approach:
        - Use recursion with memoization:
            • State: (i, k, buy)
                - `i` → current day
                - `k` → remaining transactions
                - `buy` → 1 if we can buy, 0 if we need to sell next
            • Base cases:
                - If i == n → return 0 (no days left)
                - If k == 0 → return 0 (no transactions left)
            • Choices:
                - If buy = 1 → we can either:
                    1. Buy at current price → subtract prices[i], switch to sell state
                    2. Skip buying → move to next day
                - If buy = 0 → we can either:
                    1. Sell at current price → add prices[i], decrease k, switch to buy state
                    2. Skip selling → move to next day
        - Store results in memo[i][k][buy] to avoid recomputation.

    Time Complexity:
        - O(n * k * 2), since each state (day, transactions, buy/sell) is computed once.

    Space Complexity:
        - O(n * k * 2), due to memoization table.

    Author: Vishal Singhaniya
*/




#include<iostream>
#include<vector>
using namespace std;

int recFunction(int i,int n , int k, int buy, vector<int> &prices,vector<vector<vector<int>>> &memo){
    
        if(i==n){
            return 0;
        }
        
        if(k==0){
            return 0;
        }
        if(memo[i][k][buy]!=-1){
            return memo[i][k][buy];
        }
        
            int res=recFunction(i+1,n,k,buy,prices,memo);
       
            if(buy){
                res=max(res,recFunction(i+1,n,k,0,prices,memo) - prices[i]);
            }
            else{
                res=max(res,recFunction(i+1,n,k-1,1,prices,memo) + prices[i]);
            }
            memo[i][k][buy] = res;
        
        
        return memo[i][k][buy];
    }
    
    
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n = prices.size();
        
        vector<vector<vector<int>>> memo (n,vector<vector<int>> (k+1,vector<int>(2,-1)));
        
        memo[0][k][1]=recFunction(0,n,k,1,prices,memo);
        
        return memo[0][k][1];
    }

int main(){
    
    vector<int> arr = {10,50,5,800};
    int k = 2;
    cout<<"Maximum profit which can be acheived is : "<<maxProfit(arr,k);
    
    return 0;
}
