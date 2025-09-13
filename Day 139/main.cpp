/*
    Title: Breadth First Search (BFS) Traversal of a Graph

    Problem Statement:
        - Implement Breadth First Search (BFS) for a given undirected graph 
          represented as an adjacency list.
        - Perform BFS starting from node 0 and print the traversal order.

    Example:
        Input:
            adj = {
                {2, 3, 1},   // Neighbors of node 0
                {0},         // Neighbors of node 1
                {0, 4},      // Neighbors of node 2
                {0},         // Neighbors of node 3
                {2}          // Neighbors of node 4
            }
        Output:
            BFS traversal for the given adjacency matrix : 0 2 3 1 4

    Approach:
        1. Use a queue to implement level-order traversal.
        2. Start BFS from node 0:
            - Mark it as visited.
            - Push it into the queue.
        3. While the queue is not empty:
            - Pop the front node.
            - Visit all its unvisited neighbors.
            - Mark neighbors as visited and push them into the queue.
        4. Store nodes in the result order.

    Time Complexity:
        - O(V + E), where V = number of vertices, E = number of edges.
          (Each node and edge is visited once)

    Space Complexity:
        - O(V), for visited array and queue.

    Output:
        - Returns a vector of nodes in BFS traversal order.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfsRec(int i , vector<vector<int>>& adj, vector<int> & res, vector<bool>& visited){
    queue<int> q;
    q.push(i);
    
    while(!q.empty()){
        int current = q.front();
        res.push_back(current);
        q.pop();
        
        for(int x : adj[current]){
            if(!visited[x]){
                visited[x]=true;
                q.push(x);
            }
        }
    }
}


vector<int> bfs(vector<vector<int>> &adj){
    int n = adj.size();
    vector<int> res;
    vector<bool> visited(n,false);
    
    visited[0]=true;
    
    bfsRec(0,adj,res,visited);
    return res;
}


int main(){
    
    vector<vector<int>> adj = {{2,3,1},{0},{0,4},{0},{2}};
    vector<int> res = bfs(adj);
    
    cout<<"BFS traversal for the given adjacency matrix : ";
    for(int x : res){
        cout<<x<<"  ";
    }
    
    return 0;
}
