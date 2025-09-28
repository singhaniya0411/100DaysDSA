/*
    Title: Minimum Cycle in an Undirected Weighted Graph

    Problem Statement:
        - You are given an undirected weighted graph with V vertices and edges.
        - The task is to find the length of the smallest cycle present in the graph.
        - If no cycle exists, return an infinite/large value.

    Approach:
        1. Build an adjacency list from the given edges.
        2. For each edge (u, v, w):
            - Temporarily ignore this edge.
            - Find the shortest path distance between u and v using Dijkstra's algorithm.
            - If such a path exists, the cycle length = distance(u, v) + w.
        3. Keep track of the minimum cycle length across all edges.
        4. Return the minimum cycle length.

    Helper Functions:
        - constructAdjacency():
            Builds adjacency list of type vector<vector<pair<int,int>>> from edges.
        - shortestDistance():
            Uses Dijkstra’s algorithm to find shortest path distance between src and dest
            while ignoring the direct edge between them.
        - findMinCycle():
            Iterates over all edges and computes minimum cycle length.

    Dry Run (Example):
        V = 4, Edges = { {0,1,1}, {1,2,2}, {2,0,3}, {2,3,4} }
        - Check edge (0,1,1): Shortest path from 0→1 without this edge = 3 (0→2→1).
          Cycle length = 3 + 1 = 4.
        - Check edge (1,2,2): Shortest path from 1→2 without this edge = 4 (1→0→2).
          Cycle length = 4 + 2 = 6.
        - Check edge (2,0,3): Shortest path from 2→0 without this edge = 3 (2→1→0).
          Cycle length = 3 + 3 = 6.
        - Check edge (2,3,4): No alternate path → ignore.
        Result = 4 (smallest cycle length).

    Time Complexity:
        - For each edge, we run Dijkstra → O(E * (V log V)).
        - Worst case: O(V * E log V).

    Space Complexity:
        - O(V + E) for adjacency list.
        - O(V) for distance array and priority queue.

    Applications:
        - Detecting and analyzing cycles in road networks, communication networks.
        - Useful in shortest cycle detection for routing algorithms.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<int,int>>> constructAdjacency(vector<vector<int>> &edges, int V){
    vector<vector<pair<int,int>>> adj(V);
    
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    return adj;
}

int shortestDistance(int V, vector<vector<pair<int,int>>>& adj,int src, int dest){
    vector<int> dist (V,INT_MAX);
    dist[src]=0;
    
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<>> q;
    
    q.push({0,src});
    
    while(!q.empty()){
        pair<int,int> top = q.top();
        q.pop();
        int dis = top.first;
        int u = top.second;
        
        if(dis>dist[u]){
            continue;
        }
        
        for(auto neighbour : adj[u]){
            int v = neighbour.first;
            int w = neighbour.second;
            
            if((u==src && v==dest) || (u==dest && v==src)){
                continue;
            }
            
            if(dist[v]>dist[u]+w){
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
    return dist[dest];
}

int findMinCycle(int V, vector<vector<int>>& edges) {
    vector<vector<pair<int,int>>> adj = constructAdjacency(edges,V);
    
    int result = INT_MAX;
    for(auto edge : edges){
        int u =edge[0];
        int v = edge[1];
        int w = edge[2];
        
        int dist = shortestDistance(V,adj,u,v);
        
        if(dist!=INT_MAX){
            result = min(result,dist+w);
        }
    }
    
    return result;
}

int main(){
    int V = 4;
    vector<vector<int>> edges = {
        {0,1,1},
        {1,2,2},
        {2,0,3},
        {2,3,4}
    };

    int minCycle = findMinCycle(V, edges);

    if(minCycle == INT_MAX){
        cout << "No cycle exists in the graph." << endl;
    } else {
        cout << "Length of the minimum cycle: " << minCycle << endl;
    }

    return 0;

}







