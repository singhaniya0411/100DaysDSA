/* 
    Title: Matrix Chain Multiplication (MCM) 

    Problem Statement:
        - Given a sequence of matrices, we want to multiply them together
          in such a way that the total number of scalar multiplications 
          is minimized.
        - The order of multiplication affects the total cost, but the 
          final result (matrix dimensions) remains the same.
        - Input is given as an array 'arr' of dimensions, where the 
          ith matrix has dimensions arr[i-1] x arr[i].

    Example:
        Input:  arr = {10, 30, 5, 60}
        Matrices: A1 (10x30), A2 (30x5), A3 (5x60)
        Output:  4500
        Explanation:
            - (A1 x (A2 x A3)) → cost = (30*5*60) + (10*30*60) = 9000 + 18000 = 27000
            - ((A1 x A2) x A3) → cost = (10*30*5) + (10*5*60) = 1500 + 3000 = 4500 (minimum)

    Approach:
        - Use recursion with memoization (Top-down DP).
        - Define a function recFunction(i, j):
            → Minimum cost of multiplying matrices from index i to j.
        - Try placing a partition at every possible k between (i, j),
          compute cost of left & right multiplications, and add 
          multiplication cost of merging them.
        - Store the result in memo[i][j] to avoid recomputation.

    Recurrence Relation:
        recFunction(i, j) = min( recFunction(i, k) + recFunction(k, j) 
                                  + arr[i] * arr[k] * arr[j] )
                            for all i < k < j

    Base Case:
        - If i+1 == j → cost = 0 (no multiplication needed).

    Time Complexity:
        - O(n^3), because we try all partitions k for every (i, j).
    
    Space Complexity:
        - O(n^2) for the memoization table.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>

using namespace std;
#define MAX_INT  10000000

int recFunction(int i ,int j, vector<int>& arr, vector<vector<int>> &memo){
    if(i+1==j){
        return 0;
    }
    
    if(memo[i][j]!=-1){
        return memo[i][j];
    }
    
    int res = MAX_INT;
    
    for(int k = i+1;k<j;k++){
        int curr = recFunction(i,k,arr,memo) + recFunction(k,j,arr,memo) + (arr[i]*arr[j]*arr[k]);
        res = min(curr,res);
    }
        memo[i][j]=res;
        return memo[i][j];
    
    
}

int minOperation(vector<int>& arr){
    int n = arr.size();
    
    vector<vector<int>> memo(n,vector<int>(n,-1));
    
    memo[0][n-1]=recFunction(0,n-1,arr,memo);
    return memo[0][n-1];
}

int main(){
    
    vector<int> arr = {10,30,5,60};
    
    cout<<"Minimum number of operation to multiply these matrices : "<<minOperation(arr);
    return 0;
}
