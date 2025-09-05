/* 
    Title: Longest String Chain (Using Hashmap).

    Problem Statement:
        - You are given a list of words.
        - A word `a` is a predecessor of word `b` if:
            • `b` has exactly one extra character compared to `a`.
            • `a` can be obtained by removing exactly one character from `b`.
        - A string chain is formed where each word is a predecessor of the next.
        - Task: Find the length of the longest possible word chain.

    Example:
        Input:
            words = {"a", "b", "ab", "bab", "babc", "babac"}
        Output:
            5
        Explanation:
            One valid chain:
            "a" → "ab" → "bab" → "babc" → "babac"
            Length = 5

    Approach:
        - Step 1: Sort words by length (shortest first).
        - Step 2: Use a HashMap `dp` to store the longest chain ending at each word.
        - Step 3: For each word:
            • Initialize dp[word] = 1.
            • Generate all possible predecessors by removing one character.
            • If predecessor exists in dp, update:
                dp[word] = max(dp[word], dp[pred] + 1).
        - Step 4: Keep track of the maximum chain length.

    Time Complexity:
        - O(n * L²), where:
            • n = number of words,
            • L = maximum word length (L deletions + substring operations).

    Space Complexity:
        - O(n), for storing dp states in HashMap.

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

bool comp (string& a, string&b){
    return a.size()<b.size();
}

int longestChain(vector<string>& words){
    sort(words.begin(),words.end(),comp);
    unordered_map<string,int> dp;
    
    int res = 0;
    
    for(auto w : words){
        dp[w]=1;
        
        int m = w.size();
        for(int i = 0;i<m;i++){
            string pred = w.substr(0,i)+w.substr(i+1,m);
            
            if(dp.count(pred)){
                dp[w] = max(dp[w],dp[pred]+1);
            }
        }
        res = max(res,dp[w]);
        
    }
    
    return res;
    
}


int main(){
    
    vector<string> words = {"a","b","ab","bab","babc","babac"};
    cout<<"Longest Word Chain "<<longestChain(words);
    return 0;
}
