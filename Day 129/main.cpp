/* 
    Title: Boolean Parenthesization Problem (Recursion + Memoization)

    Problem Statement:
        - You are given a boolean expression consisting of operands {T, F} 
          and operators {&, |, ^}.
        - The task is to count the number of ways to parenthesize the 
          expression such that the final result evaluates to True.

    Example:
        Input:  s = "T|F&T"
        Output: 2
        Explanation:
            - (T | (F & T)) = (T | F) & T = T → Valid
            - ((T | F) & T) = (T | F) & T = T → Valid
            Total = 2 ways.

    Approach:
        - Use recursion with memoization (Top-down DP).
        - Define recFunction(i, j, req):
            → Number of ways to evaluate the subexpression s[i..j] 
              such that the result equals `req` (0 = False, 1 = True).
        - Partition expression at every operator (odd index k).
        - Compute left (i..k-1) and right (k+1..j) evaluations 
          for both True and False cases.
        - Combine them based on operator at s[k] using evaluate() function.

    Recurrence Relation:
        recFunction(i, j, req) = Σ (ways from left × ways from right) 
                                 where operator evaluation == req

    Base Case:
        - If i == j:
            → If s[i] == 'T' and req == 1 → return 1
            → If s[i] == 'F' and req == 0 → return 1
            → Else return 0

    Time Complexity:
        - O(n^3), since we try all partitions (k) for each subproblem.
    
    Space Complexity:
        - O(n^2 * 2), for memoization of [i][j][req].

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool evaluate(int n1, int n2, char op){
        if(op=='&'){
            return (n1&n2);
        }
        if(op=='|'){
            return (n1|n2);
        }
        if(op=='^'){
            return (n1^n2);
        }
        return -1;
    }
    
    int recFunction(int i , int j , string& s, vector<vector<vector<int>>> &memo, int req){
        if(i==j){
            if(s[i]=='T' && req==1){
                return 1;
            }
            else if(s[i]=='F' && req==0){
                return 1;
            }
            else{
                return 0;
            }
        }
        
        if(memo[i][j][req]!=-1){
            return memo[i][j][req];
        }
        
        int ans = 0;
        
        for(int k = i+1;k<j;k+=2){
            int LF = recFunction(i,k-1,s,memo,0);
            int LT = recFunction(i,k-1,s,memo,1);
            int RF = recFunction(k+1,j,s,memo,0);
            int RT = recFunction(k+1,j,s,memo,1);
            
            
            if(evaluate(1,1,s[k])==req){
                ans = ans + (LT * RT);
            }
            if(evaluate(1,0,s[k])==req){
                ans = ans + (LT*RF);
            }
            if(evaluate(0,1,s[k]) == req){
                ans = ans + (LF*RT);
            }
            if(evaluate(0,0,s[k])==req){
                ans = ans + (LF*RF);
            }
        }
        memo[i][j][req] = ans;
        
        return memo[i][j][req];
        
    }
    
    int countWays(string &s) {
        // code here
        int n = s.size();
        
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(n,vector<int>(2,-1)));
        
        return recFunction(0,n-1,s,memo,1);
        
        
    }


int main(){
    
    string s = "T|F&T";
    cout<<countWays(s);
    
    return 0;
    

}







