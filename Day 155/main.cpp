/*
    Title: Longest Word with All Prefixes using Trie

    Problem Statement:
        - You are given a list of words.
        - A word is considered valid if all its prefixes are also present in the list.
        - The task is to find the longest valid word. 
        - If there are multiple such words of the same length, return the lexicographically smallest one.

    Approach (Trie Data Structure):
        1. Build a Trie by inserting all words from the list.
        2. For each word, check if all its prefixes exist in the Trie (marked as `isEnd`).
        3. Keep track of the "longest valid word" during traversal.
        4. If two words have the same length, choose the lexicographically smaller one.

    Example:
        Input:
            words = {"a","banana","app","appl","ap","apply","apple"}
        
        Process:
            - "a" → valid
            - "app" → valid (prefixes: "a","ap")
            - "appl" → valid (prefixes: "a","ap","app")
            - "apple" → valid (prefixes: "a","ap","app","appl")
            - "banana" → invalid (prefix "b" not present)

        Output:
            "apple"
            
    Time Complexity:
        - Insertion: O(N * L), where N = number of words, L = max word length.
        - Checking prefixes: O(N * L).
        - Overall: O(N * L).

    Space Complexity:
        - O(26 * N * L) for the Trie structure in the worst case.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    public:
        TrieNode * child[26];
        bool isEnd;
        
        TrieNode(){
            isEnd = false;
            fill(child,child+26,nullptr);
        }
};

class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        
        void insert(string &word){
            TrieNode* node = root;
            for(char ch : word){
                int idx = ch-'a';
                if(!node->child[idx]){
                    node->child[idx]=new TrieNode();
                }
                node=node->child[idx];
            }
            node->isEnd=true;
        }
        
        bool allPrefixExist(string &word){
            TrieNode * node = root;
            for(char ch:word){
                int idx = ch-'a';
                node=node->child[idx];
                if(!node || !node->isEnd){
                    return false;
                }
            }
            return true;
        }
};

string longestValidWord(vector<string> &words){
    Trie trie;
    
    for(string word: words){
        trie.insert(word);
    }
    
    string result = "";
    
    for(string word:words){
        if(trie.allPrefixExist(word)){
            if(word.size()>result.size() || (word.size()==result.size() && word<result)){
                result=word;
            }
        }
    }
    
    return result;
}


int main(){
    
    vector<string> words = {"a","banana","app","appl","ap","apply","apple"};
    string result = longestValidWord(words);
    cout<<"Longest Word with all Prefix : "<<result<<"\n";
    return 0;
}
