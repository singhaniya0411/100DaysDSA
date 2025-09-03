/* 
    Title: Word Break Problem (Dynamic Programming)

    Problem Statement:
        - You are given a string `s` and a dictionary of words `dict[]`.
        - Task: Determine if `s` can be segmented into a sequence of one or more dictionary words.
        - You may reuse dictionary words any number of times.

    Example:
        Input:
            s = "catsanddog"
            dict = {"cats", "dog", "sand", "and", "cat"}
        Output:
            true
        Explanation:
            - "cats and dog" → valid segmentation
            - "cat sand dog" → valid segmentation

        Input:
            s = "catsanddogz"
            dict = {"cats","dog","sand","and","cat"}
        Output:
            false
        Explanation:
            - No valid segmentation exists (extra 'z').

    Approach:
        - Use Dynamic Programming with a boolean DP array.
        - dp[i] = true if substring(0..i-1) can be segmented using words from dict.
        - Transition:
            For each i → check all j < i:
                - If dp[j] is true AND s[j..i-1] is in dict → set dp[i] = true.
        - Finally, return dp[n] where n = length of string.

    Time Complexity:
        - O(n^2), since for each index we check all possible partitions.

    Space Complexity:
        - O(n), for the DP array.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

bool wordBreak(string& s, vector<string>&dict){
    int n = s.size();
    vector<bool> dp(n+1,false);
    dp[0]=true;
    
    unordered_set<string> wordSet(dict.begin(),dict.end());
    
    for(int i =1;i<n+1;i++){
        for(int j = 0;j<i;j++){
            if(dp[j] && wordSet.count(s.substr(j,i-j))){
                dp[i]=true;
                break;
            }
            
        }
    }
    
    return dp[n];
}

int main(){
    vector<string> dict = {"cats","dog","sand","dogs","cat","and"};
    string s = "catsanddogz";
    
    if(wordBreak(s,dict)){
        cout<<"Word can be break using dictionary word\n";
    }
    else{
        cout<<"Word can not be break\n";
    }
    return 0;
}
