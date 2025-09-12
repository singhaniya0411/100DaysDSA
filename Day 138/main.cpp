/*
    Title: Depth First Search (DFS) Traversal of a Graph

    Problem Statement:
        - Implement Depth First Search (DFS) for a given undirected graph 
          represented as an adjacency list.
        - Perform DFS starting from node 0 and print the traversal order.

    Example:
        Input:
            adj = {
                {2, 3, 1},   // Neighbors of node 0
                {0},         // Neighbors of node 1
                {0, 4},      // Neighbors of node 2
                {0},         // Neighbors of node 3
                {2}          // Neighbors of node 4.
            }
        Output:
            The DFS traversal will be : 0 2 4 3 1

    Approach:
        1. Use a recursive helper function `dfsRec`:
             - Mark current node as visited.
             - Store it in the result.
             - Recursively call DFS for all unvisited neighbors.
        2. Start DFS from node 0.
        3. Collect nodes in the traversal order.

    Time Complexity:
        - O(V + E), where V = number of vertices, E = number of edges.
          (Each node and edge is visited once)

    Space Complexity:
        - O(V), for visited array and recursion stack.

    Output:
        - Returns a vector of nodes in DFS traversal order.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


void dfsRec(int i, vector<bool> &visited, vector<int> &res, vector<vector<int>> &adj) {
    visited[i] = true;
    res.push_back(i);

    for (auto x : adj[i]) {
        if (!visited[x]) {
            dfsRec(x, visited, res, adj);
        }
    }
}

vector<int> dfs(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> res;

    dfsRec(0, visited, res, adj); // start from node 0
    return res;
}
int main(){
    
    vector<vector<int>> adj ={{2,3,1},{0},{0,4},{0},{2}};
    
    vector<int> result = dfs(adj);
    
    cout<<"The DFS traversal will be : ";
    for(int i = 0;i<result.size();i++){
        cout<<" "<<result[i];
    }
    cout<<"\n";
    return 0;

}
