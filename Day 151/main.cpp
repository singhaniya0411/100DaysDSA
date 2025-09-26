/*
    Title: Bellman-Ford Algorithm (Single Source Shortest Path)

    Problem Statement:
        - You are given a weighted directed graph with V vertices and a list of edges.
        - Each edge is represented as {u, v, w}, meaning there is an edge from u → v 
          with weight w (which can be negative).
        - The task is to find the shortest path from a given source vertex to all 
          other vertices.
        - If there exists a negative weight cycle reachable from the source, return {-1}.

    Approach (Relaxation Method):
        1. Initialize distance array with "infinity" (1e8 here), except src = 0.
        2. Repeat (V - 1) times:
            - For each edge (u, v, w), update:
              if dist[u] + w < dist[v], then update dist[v].
        3. Perform one more relaxation:
            - If any distance can still be updated, a negative weight cycle exists → return {-1}.
        4. Otherwise, return the distance array.

    Example:
        Input:
            V = 5, src = 0
            edges = { {1,3,2}, {4,3,-1}, {2,4,1}, {1,2,1}, {0,1,5} }
        Output:
            Shortest path from 0 vertex : 0  5  6  7  7

    Dry Run:
        - Initialize dist = [0, 1e8, 1e8, 1e8, 1e8].
        - Relax edges V-1 = 4 times:
            Iteration 1: dist[1]=5, dist[3]=7, dist[2]=6, dist[4]=7.
            Further iterations confirm no shorter updates.
        - No negative cycle detected.
        - Final distances = [0, 5, 6, 7, 7].

    Time Complexity:
        - O(V * E), where:
            V = number of vertices,
            E = number of edges.
        - Each iteration scans all edges.

    Space Complexity:
        - O(V), for the distance array.

    Applications:
        - Graphs with negative weight edges.
        - Currency arbitrage detection.
        - Routing protocols like RIP (Routing Information Protocol).

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> bellmanFord(int V, int src, vector<vector<int>>& edges){
    vector<int> dist (V,1e8);
    dist[src]=0;
    
    for(int i = 0 ;i<V;i++){
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            
            if(dist[u]!=1e8 && dist[u]+w<dist[v]){
                if(i==V-1){
                    return {-1};
                }
                
                dist[v] = dist[u]+w;
            }
        }
    }
    
    return dist;
}

int main(){
    int V = 5;
    vector<vector<int>> edges = {{1,3,2},{4,3,-1},{2,4,1},{1,2,1},{0,1,5}};
    int src = 0;
    
    vector<int> res = bellmanFord(V,src,edges);
    cout<<"Shortest path from "<<src<<" vertex : ";
    for(auto val : res){
        cout<<val<<"  ";
    }
}