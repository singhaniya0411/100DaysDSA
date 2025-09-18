/*
    Title: Cycle Detection in a Directed Graph using DFS and Recursion Stack

    Problem Statement:
        - Given a directed graph with V vertices and edges.
        - Detect whether the graph contains a cycle or not.

    Example:
        Input:
            V = 5
            edges = {{0,1},
                        {0,2},
                        {0,4},
                        {1,2},
                        {2,3},
                        {2,4},
                        {3,4},
                        {1,4},
                        {4,2}
                    }

        Output:
            Cycle is present

        Explanation:
            - DFS traversal is used with an extra recursion stack.
            - If a node is visited again while still in the recursion stack, 
              it means a back edge exists → cycle detected.

    Approach (DFS + Recursion Stack):
        1. Build adjacency list from edges.
        2. Maintain two arrays:
            • visited[] → marks if a node has been fully explored.
            • recStack[] → keeps track of nodes in the current DFS path.
        3. Run DFS from each unvisited node:
            • Mark node visited and add to recStack.
            • For each neighbor:
                - If not visited → DFS call.
                - If visited and still in recStack → cycle detected.
            • After DFS finishes for that node, remove it from recStack.
        4. If any DFS call detects a cycle, return true.

    Time Complexity:
        - O(V + E), where V = number of vertices, E = number of edges.

    Space Complexity:
        - O(V) for visited[] and recStack[] arrays.
        - O(V) recursion depth in worst case.

    Output:
        - Prints "Cycle is present" if a cycle exists,
          otherwise prints "Cycle is not present".

    Author: Vishal Singhaniya
*/


#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> constructAdjacency(int V, vector<vector<int>> &edges){
    vector<vector<int>> res (V);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        res[u].push_back(v);
    }
    return res;
}


bool dfs(int i , vector<bool>&visited ,vector<bool>&recStack, vector<vector<int>> &adj){
    visited[i]=true;
    recStack[i]=true;
    
    for(auto x : adj[i]){
        if(!visited[x]){
            if(dfs(x,visited,recStack,adj)){
                return true;
            }
        }
        else if(recStack[x]){
            return true;
        }
    }
    
    recStack[i]=false;
    return false;
}
bool isCycle(int V, vector<vector< int>> & edges){
    vector<vector<int>> adj = constructAdjacency(V,edges);
    
    vector<bool> visited(V, false);
    vector<bool> recStack(V,false);
    
    for(int i = 0 ;i<V;i++){
        if(!visited[i]){
            if(dfs(i,visited,recStack,adj)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    
    int V = 5;
    vector<vector<int>> edges = {{0,1},{0,2},{0,4},{1,2},{2,3},{2,4},{3,4},{1,4},{4,2}};
    if(isCycle(V,edges)){
        cout<<"Cycle is present \n";
    }
    else{
        cout<<"Cycle is not present\n";
    }
    return 0;
}
