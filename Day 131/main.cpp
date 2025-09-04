/* 
    Title: Longest Common Subsequence

    Problem Statement:
        - You are given two strings s1 and s2.
        - Task: Find the length of the longest subsequence present in both strings.
        - A subsequence does not require contiguous characters, 
          but must maintain relative order.
          

    Example:
        Input:
            s1 = "ABCEFGHJKL"
            s2 = "CDEFGHJKLMNO"
        Output: 8
        Explanation:
            - Longest Common Subsequence = "CEFGHJKL"
            - Length = 8

    Approach:
        - Use Bottom-Up DP (Tabulation):
            • Create a 2D DP table of size (m+1) x (n+1).
            • dp[i][j] = length of LCS of s1[0..i-1] and s2[0..j-1].
            • Recurrence:
                - If s1[i-1] == s2[j-1]:
                    dp[i][j] = 1 + dp[i-1][j-1]
                - Else:
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1])
        - Final Answer = dp[m][n].

    Time Complexity:
        - O(m * n), since we fill a 2D table.

    Space Complexity:
        - O(m * n), for the DP table.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<string>
#include<vector>
using namespace std;

int lcs(string& s1, string &s2){
    
    int m = s1.size();
    int n = s2.size();
    
    vector<vector<int>> memo(m+1,vector<int>(n+1,0));
    
    for(int i = 1;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(s1[i-1]==s2[j-1]){
                memo[i][j]=1+memo[i-1][j-1];
            }
            else{
                memo[i][j] = max(memo[i-1][j],memo[i][j-1]);
            }
        }
    }
    
    return memo[m][n];
}

int main(){
    
    string s1="ABCEFGHJKL";
    string s2="CDEFGHJKLMNO";
    
    cout<<"Then length of longest common subsequence of "<<s1<<
    " and "<<s2<<" is "<<lcs(s1,s2);
    return 0;
}
