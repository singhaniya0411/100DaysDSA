/*
    Title: Alien Dictionary (Topological Sort Approach).

    Problem Statement:
        - You are given a list of words from an alien dictionary sorted 
          lexicographically according to the rules of the alien language.
        - The goal is to determine a valid order of characters in that language.
        - If no valid order exists, return an empty string.

    Approach (Graph + Topological Sort):
        1. Build a directed graph of character dependencies:
           - Compare each pair of adjacent words.
           - Find the first mismatching character → this defines an edge u → v.
        2. Maintain an indegree array to count dependencies for each character.
        3. Perform a BFS (Kahn’s Algorithm for topological sort):
           - Start with characters having indegree 0.
           - Remove edges one by one, reducing indegree of neighbors.
           - If a neighbor’s indegree becomes 0, push it into the queue.
        4. If all characters are processed, return the order.
           Else, return "" (cycle or invalid ordering).

    Example:
        Input:
            words = {"baa","abcd","abca","cab","cad"}
        Output:
            "bdac"  (One possible valid ordering)

    Dry Run:
        - Compare "baa" and "abcd" → b → a (edge b→a).
        - Compare "abcd" and "abca" → d → a.
        - Compare "abca" and "cab" → a → c.
        - Compare "cab" and "cad" → b → d.
        Graph edges: b→a, d→a, a→c, b→d.
        Topological order possible: b d a c.

    Time Complexity:
        - O(N * L), where:
            N = number of words,
            L = average length of each word.
        - Each adjacent word comparison is at most O(L),
          and topological sort is O(V + E).

    Space Complexity:
        - O(26 + E), where:
            26 = fixed alphabet size,
            E = number of edges in the graph.

    Applications:
        - Deciphering alien or unknown language rules.
        - Ordering tasks with dependencies.
        - Compiler dependency resolution.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;


string findOrder(vector<string> &words) {
    vector<vector<int>> graph(26);
    vector<int> inDegree(26,0);
    vector<bool> exists(26,false);
    for(auto word:words){
        for(char ch:word){
            exists[ch-'a']=true;
        }
    }
    
    for(int i =0;i<words.size()-1;i++){
        string w1=words[i];
        string w2 = words[i+1];
        int j = 0;
        int len = min(w1.size(),w2.size());
        while(j<len && w1[j] == w2[j]){
            j++;
        }
        
        if(j<len){
            int u = w1[j]-'a';
            int v = w2[j]-'a';
            graph[u].push_back(v);
            inDegree[v]++;
        }
        else if(w1.size()>w2.size()){
            return "";
        }
    }
    
    queue<int> q;
    
    for(int i = 0;i<26;i++){
        if(exists[i]&& inDegree[i]==0){
            q.push(i);
        }
    }
    
    string res;
    
    while(!q.empty()){
        int u = q.front();
        q.pop();
        res +=char(u+'a');
        
        for(int v : graph[u]){
            inDegree[v]--;
            if(inDegree[v]==0){
                q.push(v);
            }
        }
    }
    
    for(int i =0;i<26;i++){
        if(exists[i] && inDegree[i]!=0){
            return "";
        }
    }
    return res;
}

int main(){
    
    vector<string> words = {"baa","abcd","abca","cab","cad"};
    string order = findOrder(words);
    cout<<"Alien Dictionary order : "<<order;
    return 0;
}
