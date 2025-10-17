/*
    Title: Minimum Repetition to Make One String a Substring of Another

    Problem Statement:
        - Given two strings `s1` and `s2`, determine the minimum number of times `s1`
          must be repeated so that `s2` becomes a substring of the repeated string.
        - If it's not possible, return `-1`.

    Approach:
        1. Use the **KMP (Knuth-Morris-Pratt)** algorithm for efficient substring searching.
        2. Compute the **LPS (Longest Prefix Suffix)** array for `s2`.
        3. Repeat `s1` enough times such that its total length ≥ `s2`.
        4. Check if `s2` exists within `s1` repeated `x` times or `x+1` times.
        5. Return the minimum repetition count where the condition holds.

    Example:
        Input:
            s1 = "abcd"
            s2 = "cdabcdabcdab"

        Process:
            - Repeated strings:
                1 → "abcd"
                2 → "abcdabcd"
                3 → "abcdabcdabcd"
            - At 3 repetitions, "cdabcdabcdab" is found as a substring.

        Output:
            Minimum repetition to make s2 as a substring of s1 : 3

    Dry Run:
        s1 = "abc"
        s2 = "cabca"
        x = (3 + 5 - 1) / 3 = 2
        Repeats → "abcabc" → contains "cabca"
        ✅ Output → 2

    Time Complexity:
        - O(N + M), where N = length of s1, M = length of s2
          (due to KMP preprocessing and search steps)

    Space Complexity:
        - O(M), for storing the LPS array

    Applications:
        - Pattern searching in repeated cyclic strings
        - DNA sequence matching and text repetition problems

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

void computeLPS(string &txt, vector<int>& lps){
    int len = 0;
    int idx = 1;
    
    lps[0] = 0;
    
    while(idx < txt.size()){
        if(txt[idx] == txt[len]){
            len++;
            lps[idx] = len;
            idx++;
        }
        else{
            if(len == 0){
                lps[idx] = 0;
                idx++;
            }
            else{
                len = lps[len - 1];
            }
        }
    }
}

bool KMPsearch(string &text, string &pat, vector<int> &lps, int rep){
    int n = text.size();
    int m = pat.size();
    int i = 0, j = 0;
    
    while(i < n * rep){
        if(text[i % n] == pat[j]){
            i++;
            j++;
            if(j == m) return true;
        }
        else{
            if(j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return false;
}

int minRepeat(string &s1, string &s2){
    int n = s1.size();
    int m = s2.size();
    
    vector<int> lps(m);
    computeLPS(s2, lps);
    
    int x = (n + m - 1) / n;
    
    if(KMPsearch(s1, s2, lps, x)) return x;
    if(KMPsearch(s1, s2, lps, x + 1)) return x + 1;
    
    return -1;
}

int main(){
    string s1 = "abcd";
    string s2 = "cdabcdabcdab";
    
    cout << "Minimum repetition to make s2 as a substring of s1 : " 
         << minRepeat(s1, s2);
    return 0;
}













