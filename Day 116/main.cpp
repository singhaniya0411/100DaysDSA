/* 
    Title: Minimum Cost Climbing Stairs (Dynamic Programming)

    Problem Statement:
        - You are given an array `cost` where cost[i] is the cost of stepping on the i-th stair.
        - Once you pay the cost, you can climb either 1 or 2 steps.
        - You can start from stair 0 or stair 1.
        - Find the minimum cost to reach the top of the floor (beyond the last stair).

    Example:
        Input:  cost = [10, 15, 20]
        Output: 15
        Explanation:
            - Start at stair 1 (cost = 15), then directly climb 2 steps to the top.
            - Total cost = 15 (minimum possible).

    Approach:
        - Use bottom-up dynamic programming:
            - Let dp[i] represent the minimum cost to reach stair i.
            - Base cases:
                - dp[0] = cost[0]
                - dp[1] = cost[1]
            - Transition:
                dp[i] = cost[i] + min(dp[i-1], dp[i-2])
            - Answer is min(dp[n-1], dp[n-2]), since you can reach the top
              from either of the last two stairs.

    Time Complexity:
        - O(n), since each stair is processed once.

    Space Complexity:
        - O(n), for the DP array (can be optimized to O(1)).

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

int minWeight(vector<int> cost) {
    int n = cost.size();
    vector<int> dp(n, 0);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[n - 1], dp[n - 2]);
}

int main() {
    vector<int> stair = {10, 15, 20};
    cout << minWeight(stair);
    return 0;
}
