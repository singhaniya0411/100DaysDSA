/* 
    Title: Stair Climbing - Count Number of Ways.

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
        - Use recursion:
            - Base cases:
                - If n == 1 → 1 way
                - If n == 2 → 2 ways
            - Recurrence:
                ways(n) = ways(n-1) + ways(n-2)
        - This is equivalent to the Fibonacci sequence.

    Time Complexity:
        - O(2^n) for the recursive approach (can be optimized using DP).

    Space Complexity:
        - O(n) due to function call stack in recursion.

    Author: Vishal Singhaniya
*/

#include <iostream>
using namespace std;

int stairClimbing(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    return stairClimbing(n - 1) + stairClimbing(n - 2);
}

int main() {
    int stair = 5;
    cout << stairClimbing(stair);
    return 0;
}





