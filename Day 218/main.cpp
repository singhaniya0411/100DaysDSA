/*
    Title: Rearrange String So That No Two Adjacent Characters Are Same

    Problem Statement:
        - You are given a string `s` consisting of lowercase English letters.
        - Rearrange the characters of the string such that no two adjacent
          characters are the same.
        - If it is not possible to rearrange the string, return an empty string.

    Example:
        Input:
            s = "aaabbc"

        Possible Output:
            "ababac"

        Explanation:
            - Characters are rearranged so that no two identical characters
              appear next to each other.
            - Multiple valid outputs may exist.

        Input:
            s = "aaab"

        Output:
            ""  (not possible)

    Approach (Greedy + Max Heap):
        1. Count the frequency of each character using a hash map.
        2. Push all characters into a max heap (priority queue),
           ordered by their frequency.
        3. Repeatedly:
            - Take the character with the highest remaining frequency.
            - Append it to the result string.
            - Decrease its frequency.
            - Push the previously used character back into the heap
              (if it still has remaining frequency).
        4. This ensures that the same character is never placed
           adjacent to itself.
        5. If the final string length is not equal to the input length,
           rearrangement is not possible.

    Dry Run:
        s = "aaabbc"
        Frequencies:
            a → 3, b → 2, c → 1

        Heap picks:
            a → b → a → b → a → c

        Result = "ababac" ✅

        s = "aaab"
        Heap cannot place characters without repetition
        Result length < original length → return ""

    Time Complexity:
        - O(n log k), where:
            n = length of string
            k = number of unique characters (≤ 26)

    Space Complexity:
        - O(k), for frequency map and priority queue.

    Applications:
        - Task scheduling with cooling period
        - Load balancing
        - String rearrangement problems

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;


string rearrangeString(string s) {
    // code here
    int n  = s.size();
    
    unordered_map<char,int> freq;
    
    for(int i = 0;i<n;i++){
        freq[s[i]]++;
    }
    
    priority_queue<pair<int,char>> pq;
    
    for(char c = 'a' ; c<='z' ; c++){
        if(freq[c]>0){
            pq.push({freq[c],c});
        }
    }
    
    string res = "";
    
    pair<int, char> prev = {-1,'#'};
    
    while(!pq.empty()){
        pair<int,char> p = pq.top();
        pq.pop();
        
        res.push_back(p.second);
        
        if(prev.first > 0){
            pq.push(prev);
        }
        
        p.first--;
        prev = p;
    }
    
    if(res.size()!=n){
        return "";
    }
    return res;
}

int main() {
    string s = "aaabc";
    cout << rearrangeString(s);
    return 0;
}