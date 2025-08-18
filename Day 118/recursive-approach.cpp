/* 
    Title: Coin Change Problem (Recursive Approach)

    Problem Statement:
        - You are given:
            1. A set of coins with given denominations `coin[]`.
            2. An integer `sum` representing the target value.
        - You need to count the number of distinct ways to make up the given sum
          using the available coins.
        - Each coin can be used **infinite times**.

    Example:
        Input:
            coin = [5, 2, 3, 6]
            sum = 10
        Output: 5
        Explanation:
            Ways are:
                (2+2+2+2+2),
                (2+2+3+3),
                (2+2+6),
                (2+3+5),
                (5+5)

    Approach:
        - Recursive solution:
            - Define countWays(coin[], sum, n):
                1. If sum == 0 → return 1 (valid way found).
                2. If sum < 0 → return 0 (invalid way).
                3. If no coins left (n == 0) → return 0.
                4. Else:
                    - Include current coin → countWays(sum - coin[n-1], n)
                    - Exclude current coin → countWays(sum, n-1)
                    - Add both results.

    Time Complexity:
        - Exponential (O(2^n)) in worst case (due to recursion).

    Space Complexity:
        - O(n) recursion depth.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
using namespace std;

int countWays(vector<int> &coin, int sum,int n){
    
    if(sum == 0){
        return 1;
    }
    if(sum<0){
        return 0;
    }
    if(n==0){
        return 0;
    }
    else{
        return countWays(coin,sum-coin[n-1],n) + countWays(coin,sum,n-1);
    }
}

int main(){
    
    vector<int> coin = {5,2,3,6};
    int sum = 10;
    int n = coin.size();
    cout<<"Ways : "<<countWays(coin,sum,n);
    return 0;
}
