/*
    Title: Longest Prefix which is also a Suffix (LPS)

    Problem Statement:
        - Given a string `s`, find the length of the longest proper prefix 
          which is also a suffix of the string.
        - Proper prefix means it cannot be equal to the entire string itself.

    Approach:
        1. Use the **KMP (Knuth-Morris-Pratt)** preprocessing technique.
        2. Maintain a `len` pointer to track the current longest prefix-suffix length.
        3. For each character:
            - If characters match, increase `len` and assign to `lps[i]`.
            - If not, reduce `len` using the previously computed `lps` value.
        4. The last value in the `lps` array gives the answer.

    Example:
        Input:
            s = "abcbaabcbaabc"

        Process:
            - Compute LPS array step by step:
              [0, 0, 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 3]
            - Last element (3) → longest prefix-suffix length = 3

        Output:
            Length of longest prefix which is also a suffix is : 3

    Time Complexity:
        - O(N), where N = length of string `s`

    Space Complexity:
        - O(N), for storing the LPS array

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int getLPSLength(string &s){
    int n = s.size();
    vector<int> lps(n, 0);
    
    int len = 0;
    int i = 1;
    
    while(i < n){
        if(s[i] == s[len]){
            len++;
            lps[i] = len;
            i++;
        }
        else{
            if(len != 0){
                len = lps[len - 1];
            }
            else{
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps[n - 1];
}

int main(){
    string s = "abcbaabcbaabc";
    cout << "Length of longest prefix which is also a suffix is : " << getLPSLength(s);
    return 0;
}




