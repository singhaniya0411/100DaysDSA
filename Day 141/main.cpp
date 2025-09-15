/*
    Title: Cycle Detection in an Undirected Graph (DFS)

    Problem Statement:
        - You are given an undirected graph with `V` vertices and a list of edges.
        - Task: Check if the graph contains a cycle.
        - Return:
            • true  → if there exists a cycle
            • false → otherwise

    Example:
        Input:
            V = 5
            edges = {{1,0}, {2,3}, {4,1}, {1,3}, {2,4}, {2,1}}

        Output:
            Cycle is detected

    Approach:
        1. Convert the edge list into an adjacency list representation.
        2. Use Depth-First Search (DFS) to traverse the graph.
        3. During DFS:
            - Mark each visited node.
            - If a visited neighbor is not the parent of the current node,
              then a cycle is detected.
        4. Check all components (disconnected graph case).

    Time Complexity:
        - O(V + E), where V = number of vertices, E = number of edges.

    Space Complexity:
        - O(V + E), for adjacency list and visited array.

    Output:
        - Prints "Cycle is detected" if a cycle exists,
          otherwise "No cycle detected".

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> adjacency(int V, vector<vector<int>>&edges){
    vector<vector<int>> res(V);
    
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        res[u].push_back(v);
        res[v].push_back(u);
    }
    
    return res;
}

bool dfs(int i , vector<bool> & vis,vector<vector<int>>&adj,int parent){
    vis[i] = true;
    
    for(auto x : adj[i]){
        if(!vis[x]){
            if(dfs(x,vis,adj,i)){
                return true;
            }
        }
        else{
            if(x!=parent){
                return true;
            }
        }
    }
    return false;
}


bool isCycle(int V, vector<vector<int>> edges){
    vector<vector<int>> adj(V);
    
    adj = adjacency(V,edges);
    
    vector<bool> vis(V,false);
    for(int i = 0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,vis,adj,-1)){
                return true;
            }
        }
    }
    return false;
}

int main(){
    
    vector<vector<int>> edges = {{1,0},{2,3},{4,1},{1,3},{2,4},{2,1}};
    int V = 5;
    if(isCycle(V,edges)){
        cout<<"Cycle is detected\n";
    }
    else{
        cout<<"No cycle detected\n";
    }
    return 0;
}