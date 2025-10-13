/*
    Title: CamelCase Pattern Matching

    Problem Statement:
        - You are given a list of words in CamelCase format (like "HiTechCity", "HelloWorld", etc.).
        - You are also given a pattern string (e.g., "HAT").
        - The goal is to find all words whose uppercase letter sequence matches the given pattern.

    Approach:
        1. Traverse each word character by character.
        2. Ignore lowercase letters since they do not affect the CamelCase pattern.
        3. Compare each uppercase letter of the word with the corresponding character in the pattern.
        4. If all characters in the pattern match before the word ends, it’s a valid match.
        5. Add that word to the result list.

    Example:
        Input:
            arr = {"HiTechCity", "HelloWorld", "HiTechLab", "HiAliensTravel"}
            pat = "HTC"

        Process:
            - "HiTechCity" → Uppercase: "HTC" → ✅ Matches pattern
            - "HelloWorld" → Uppercase: "HW" → ❌
            - "HiTechLab"  → Uppercase: "HTL" → ❌

        Output:
            HiTechCity

    Time Complexity:
        - O(N * M), where N = number of words, M = average word length.

    Space Complexity:
        - O(1) additional space (excluding output vector).

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

vector<string> camelCasePattern(vector<string> &arr, string &pat){
    vector<string> res ;
    
    for(auto word : arr){
        int i =0,j=0;
        while(i<word.size() && j<pat.size()){
            if(islower(word[i])){
                i++;
            }
            else if(word[i]!=pat[j]){
                break;
            }
            else{
                i++;
                j++;
            }
        }
        
        if(j==pat.size()){
            res.push_back(word);
        }
    }
    
    return res;
}

int main(){
    
    vector<string> arr = {"HiTechCity", "HelloWorld", "HiTechLab", "HiAliensTravel"};
    string pat = "HTC";
    
    vector<string> res = camelCasePattern(arr,pat);
    
    for(auto resWord : res){
        cout<<resWord<<" ";
    }
    return 0;
}