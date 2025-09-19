/*
    Title: Articulation Points in an Undirected Graph using DFS (Tarjan’s Algorithm)

    Problem Statement:
        - Given an undirected graph with V vertices and edges,
          find all the articulation points.
        - An articulation point (cut vertex) is a vertex whose removal increases
          the number of connected components in the graph.

    Example:
        Input:
            V = 5
            edges = {{0,1},{1,4},{4,3},{4,2},{2,3}}

        Output:
            {1 ,4}

        Explanation:
            - Removing node 1 or node 4 disconnects the graph,
              hence they are articulation points.

    Approach (Tarjan’s Algorithm):
        1. Build adjacency list from edges.
        2. Maintain arrays:
            • disc[u]  → discovery time of node u during DFS.
            • low[u]   → lowest discovery time reachable from u.
            • parent[u] → parent of u in DFS tree.
            • ap[u]    → boolean to mark if u is an articulation point.
        3. Perform DFS traversal:
            • For root node (parent = -1), if it has >1 children → articulation point.
            • For non-root nodes, if low[v] >= disc[u] (where v is a child of u),
              then u is an articulation point.
            • Update low[u] for back edges.
        4. Collect all articulation points.

    Time Complexity:
        - O(V + E), where V = number of vertices, E = number of edges.

    Space Complexity:
        - O(V) for disc[], low[], parent[], ap[] arrays.
        - O(V + E) for adjacency list.

    Output:
        - Prints all articulation points in sorted order.
        - If no articulation point exists, returns -1.

    Author: Vishal Singhaniya
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> constructAdj(int V, vector<vector<int>>& edges) {
    vector<vector<int>> res(V);
    for (auto edge : edges) {
        int u = edge[0];
        int v = edge[1];
        if (u < V && v < V) {
            res[u].push_back(v);
            res[v].push_back(u);
        }
    }
    return res;
}

void dfs(int u, vector<vector<int>>& adj, vector<int>& disc, vector<int>& low, 
         vector<int>& parent, vector<bool>& ap, int& time) {
    disc[u] = low[u] = ++time;
    int children = 0;
    
    for (int v : adj[u]) {
        if (disc[v] == -1) {
            children++;
            parent[v] = u;
            dfs(v, adj, disc, low, parent, ap, time);
            low[u] = min(low[u], low[v]);
            
            // Check for articulation point
            if (parent[u] == -1 && children > 1) {
                ap[u] = true;
            }
            if (parent[u] != -1 && low[v] >= disc[u]) {
                ap[u] = true;
            }
        } else if (v != parent[u]) {
            low[u] = min(low[u], disc[v]);
        }
    }
}

vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
    if (V == 0) return {-1};
    
    vector<vector<int>> adj = constructAdj(V, edges);
    
    vector<int> disc(V, -1);
    vector<int> low(V, -1);
    vector<int> parent(V, -1);
    vector<bool> ap(V, false);
    int time = 0;
    
    for (int i = 0; i < V; i++) {
        if (disc[i] == -1) {
            dfs(i, adj, disc, low, parent, ap, time);
        }
    }
    
    set<int> result;
    for (int i = 0; i < V; i++) {
        if (ap[i]) {
            result.insert(i);
        }
    }
    
    if (result.empty()) {
        return {-1};
    }
    
    return vector<int>(result.begin(), result.end());
}

int main() {
    int V = 5;
    vector<vector<int>> edges = {{0, 1}, {1, 4}, {4, 3}, {4, 2}, {2, 3}};
    
    vector<int> points = articulationPoints(V, edges);
    for (int point : points) {
        cout << point << " ";
    }
    cout << endl;
    
    return 0;
}





