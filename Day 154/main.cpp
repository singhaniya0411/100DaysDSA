/*
    Title: Bipartite Graph

    Problem Statement:
        - You are given an undirected graph represented by edges.
        - The task is to determine whether the graph is bipartite or not.
        - A graph is bipartite if its vertices can be divided into two sets such that no two adjacent vertices belong to the same set.

    Approach (Breadth First Search):
        1. Build the adjacency list from the given edge list.
        2. Maintain a color array (initialized with -1) to store colors of nodes.
        3. For each unvisited node, assign a color and perform BFS:
            - Assign alternate colors to adjacent nodes.
            - If an adjacent node already has the same color, return false.
        4. If BFS completes without conflict, the graph is bipartite.

    Example:
        Input:
            V = 4
            edges = { {0,3}, {1,2}, {3,2}, {0,2} }

        Adjacency List:
            0 --> [3, 2]
            1 --> [2]
            2 --> [1, 3, 0]
            3 --> [0, 2]

        Output:
            This graph is not a Bipartite graph

    Dry Run:
        - Start at node 0, color[0] = 0.
        - Its neighbors (3,2) get color 1.
        - From node 3, neighbor 2 already has color 1 → conflict found → Not Bipartite.

    Time Complexity:
        - O(V + E), where V = number of vertices, E = number of edges.

    Space Complexity:
        - O(V + E) for adjacency list, O(V) for color array and queue.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> buildAdjacency(int V, vector<vector<int>>&edges){
    vector<vector<int>> adj(V);
    
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    return adj;
}

bool isBipartite(vector<vector<int>> &edges, int V){
    vector<int> color(V,-1);
    vector<vector<int>> adj = buildAdjacency(V,edges);
    
    queue<int> q;
    
    for(int i = 0;i<V;i++){
        if(color[i]==-1){
            color[i]=0;
            q.push(i);
            
            while(!q.empty()){
                int u = q.front();
                q.pop();
                
                for(auto v : adj[u]){
                    if(color[v]==-1){
                        color[v]=1-color[u];
                        q.push(v);
                    }
                    else if(color[v]==color[u]){
                        return false;
                    }
                }
            }
        }
    }
    
    return true;
}

int main(){
    int V = 4;
    vector<vector<int>> edges = {{0,3},{1,2},{3,2},{0,2}};
    vector<vector<int>> adj = buildAdjacency(V,edges);
    
    cout<<"Adjacency List:\n\n";
    int cnt =0;
    for(auto edge:adj){
        cout<<cnt<<" --> [ ";
        for(auto elem : edge){
            cout<<elem<<" ";
        }
        cout<<"]\n";
        cnt++;
    }
    cout<<"\n";
    
    if(isBipartite(edges,V)){
        cout<<"This graph is Bipartite\n";
    }
    else{
        cout<<"This graph is not a Bipartite graph\n";
    }
}















