/* 
    Title: Stair Climbing - Count Number of Ways (Dynamic Programming).

    Problem Statement:
        - Given `n` stairs, you can climb either 1 step or 2 steps at a time.
        - Find the total number of distinct ways to reach the top.

    Example:
        Input:  n = 5
        Output: 8
        Explanation:
            Possible ways:
            1-1-1-1-1  
            1-1-1-2  
            1-1-2-1  
            1-2-1-1  
            2-1-1-1  
            2-2-1  
            2-1-2  
            1-2-2

    Approach:
        - Use bottom-up dynamic programming:
            - Let `dp[i]` represent the number of ways to reach the (i+1)-th stair.
            - Base cases:
                - dp[0] = 1 (1 way to climb 1 stair)
                - dp[1] = 2 (2 ways to climb 2 stairs)
            - Transition:
                dp[i] = dp[i-1] + dp[i-2]
            - Answer is dp[n-1].

    Time Complexity:
        - O(n), since each state is computed once.

    Space Complexity:
        - O(n), for the DP array (can be optimized to O(1)).

    Author: Vishal Singhaniya
*/

#include <iostream>
#include <vector>
using namespace std;

int countWays(int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;
    dp[1] = 2;

    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n - 1];
}

int main() {
    int stair = 5;
    cout << countWays(stair);
    return 0;
}

