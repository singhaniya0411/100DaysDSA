/* 
    Title: Best Time to Buy and Sell Stock with At Most 2 Transactions 
           (Recursion + Memoization).

    Problem Statement:
        - You are given an array `prices[]` where `prices[i]` is the stock price on day `i`.
        - You are allowed to complete at most 2 transactions.
        - Each transaction consists of exactly one buy and one sell.
        - Find the maximum profit possible.

    Example:
        Input:
            prices = [10, 50, 5, 800]
        Output:
            835
        Explanation:
            - Buy on day 0 at price 10, sell on day 1 at price 50 → profit = 40
            - Buy on day 2 at price 5, sell on day 3 at price 800 → profit = 795
            - Total profit = 835

    Approach:
        - Use recursion with memoization:
            • State: (i, k, buy)
                - `i` → current day
                - `k` → remaining transactions (max = 2 here)
                - `buy` → 1 if we can buy, 0 if we need to sell
            • Base cases:
                - If i == n → return 0 (no days left)
                - If k == 0 → return 0 (no transactions left)
            • Choices:
                - If buy = 1 → 
                    1. Buy today → subtract prices[i], switch to sell state
                    2. Skip today → move to next day
                - If buy = 0 → 
                    1. Sell today → add prices[i], decrement k, switch to buy state
                    2. Skip today → move to next day
        - Use memo[i][k][buy] to store computed states.

    Time Complexity:
        - O(n * 2 * 2) = O(4n) → linear with memoization.

    Space Complexity:
        - O(n * 2 * 2), due to memoization table.

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



int recFunction(int i, int n, int k, int buy, vector<vector<vector<int>>> &memo, vector<int> &prices){
        if(i==n || k==0){
            return 0;
        }
        
        if(memo[i][k][buy]!=-1){
            return memo[i][k][buy];
        }
        
        int res = recFunction(i+1,n,k,buy,memo,prices);
        
        if(buy){
            res = max(res,recFunction(i+1,n,k,0,memo,prices)-prices[i]);
        }
        else{
            res = max(res,recFunction(i+1,n,k-1,1,memo,prices)+prices[i]);
        }
        
        
        return memo[i][k][buy]=res;
    }
int maxProfit(vector<int> &prices) {
    // code here
    int k =2;
    int n = prices.size();
    
    vector<vector<vector<int>>> memo(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
    
    memo[0][k][1]=recFunction(0,n,k,1,memo,prices);
    return memo[0][k][1];
}

int main(){
    
    vector<int> prices= {10,15,20,5,60,10,80};
    cout<<"Maximum profit you can achieve in 2 transactions "<<maxProfit(prices);
    return 0;

}




