/* 
    Title: 0/1 Knapsack Problem (Dynamic Programming - Memoization)
    
    Problem Statement:
        - You are given:
            1. An array `value[]` where value[i] represents the value of the i-th item.
            2. An array `weight[]` where weight[i] represents the weight of the i-th item.
            3. An integer `capacity` representing the maximum weight the knapsack can hold.
        - Each item can either be included **once** (0/1 property) or not at all.
        - Find the maximum total value that can be obtained without exceeding the knapsack capacity.

    Example:
        Input:
            capacity = 5
            value  = [10, 40, 30, 50]
            weight = [5,  4,  2,  3]
        Output: 70
        Explanation:
            - Select items with weight 2 and 3 → total weight = 5
            - Total value = 30 + 50 = 80 (maximum possible)

    Approach:
        - Use recursion + memoization (top-down dynamic programming):
            - Define knapSolve(capacity, n):
                - Returns max value using first `n` items with given capacity.
            - Choices:
                1. If weight[n-1] > capacity → cannot pick item → solve for (capacity, n-1).
                2. Else:
                    - Pick = value[n-1] + knapSolve(capacity - weight[n-1], n-1)
                    - NotPick = knapSolve(capacity, n-1)
                    - Take max(Pick, NotPick).
            - Store results in memo table to avoid recomputation.

    Time Complexity:
        - O(n * capacity), since each state is computed once.

    Space Complexity:
        - O(n * capacity), for the memo table (can be optimized).

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;


int knapSolve(int capacity, int n, const vector<int> &value, const vector<int> &weight, vector<vector<int>> &memo) {
    if (n == 0 || capacity == 0) {
        return 0;
    }
    
    if (memo[capacity][n] != -1) {
        return memo[capacity][n];  
    }
    
    int pick = 0;
    if (weight[n - 1] <= capacity) {
        
        pick = value[n - 1] + knapSolve(capacity - weight[n - 1], n - 1, value, weight, memo);
    }
    
    
    int notPick = knapSolve(capacity, n - 1, value, weight, memo);
    
    
    return memo[capacity][n] = max(pick, notPick);
} 

// Main knapsack function
int knapsack(int capacity, const vector<int> &value, const vector<int> &weight) {
    int n = weight.size();
    vector<vector<int>> memo(capacity + 1, vector<int>(n + 1, -1));
    return knapSolve(capacity, n, value, weight, memo);
}

int main() {
    int capacity = 5;
    vector<int> value = {10, 40, 30, 50};
    vector<int> weight = {5, 4, 2, 3};
    
    cout << "Max value achievable: " << knapsack(capacity, value, weight) << endl;    
    return 0;
}









