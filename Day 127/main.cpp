/* 
    Title: Decode Ways,

    Problem Statement:
        - You are given a string of digits (e.g., "45121213").
        - Each digit or pair of digits can represent a letter:
              '1' -> 'A', '2' -> 'B', ... '26' -> 'Z'
        - The task is to count the total number of ways 
          the string can be decoded into letters.

    Example:
        Input:  "123"
        Output: 3
        Explanation:
            Possible decodings include:
                "ABC" , "LC" , "AW" 

    Approach:
        - Use recursion with memoization (Top-down DP).
        - At each index i:
            1. Decode one digit (if it's not '0').
            2. Decode two digits (if valid between "10" and "26").
        - Store results in memo[i] to avoid recomputation.
    
    Time Complexity:
        - O(n), since each index is solved once.
    
    Space Complexity:
        - O(n), for memoization array.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;

int recCount(int i ,int n, string &digits, vector<int>& memo){
    if(i==n){
        return 1;
    }
    if(digits[i]=='0'){
        return 0;
    }
    
    if(memo[i]!=-1){
        return memo[i];
    }
    
    int res= 0;
    
    if(digits[i]!='0'){
        res=recCount(i+1,n,digits,memo);
    }
    
    if(i+1<n && (digits[i]=='1' || (digits[i]=='2' && digits[i+1]<='6'))){
        res = res+recCount(i+2,n,digits,memo);
    }
    memo[i]=res;
    
    return memo[i];
}

int countWays(string digits){
    int n = digits.size();
    
    if(n==0){
        return 0;
    }
    
    vector<int> memo(n,-1);
    memo[0]=recCount(0,n,digits,memo);
    
    return memo[0];
}

int main(){
    string digit = "45121213";
    
    cout<<"No of ways to decode this string : "<<countWays(digit);
    
    return 0;
}
