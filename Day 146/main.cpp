/*
    Title: Minimum Cost to Connect All Houses in a City (Prim’s Algorithm with Manhattan Distance)

    Problem Statement:
        - A city has houses represented as points on a 2D grid.
        - The cost of connecting two houses is the Manhattan distance between them.
        - Find the minimum cost to connect all houses such that the city becomes fully connected.

    Example:
        Input:
            houses = {{0,0}, {1,3}, {3,3}, {0,3}}

        Output:
            Minimum cost = 6

        Explanation:
            - Connect houses (0,0) → (0,3) → (1,3) → (3,3)
            - Total minimum cost = 3 + 1 + 2 = 6

    Approach (Prim’s Minimum Spanning Tree Algorithm):
        1. Start with any house (node 0).
        2. Use a Min-Heap (priority_queue with min ordering) to always pick the 
           smallest cost edge to connect a new house.
        3. Keep track of visited houses to avoid cycles.
        4. Add the Manhattan distance between current house and unvisited houses
           into the priority queue.
        5. Repeat until all houses are connected.

    Manhattan Distance Formula:
        distance = |x1 - x2| + |y1 - y2|

    Time Complexity:
        - O(n^2 log n), where n = number of houses
        - Each house can connect to all others (n^2 edges), 
          heap operations take log n.

    Space Complexity:
        - O(n^2) for priority queue in worst case.
        - O(n) for visited array.

    Output:
        - Prints the minimum total cost required to connect all houses.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

int manHattan(vector<int>&a, vector<int>& b){
    return abs(a[0]-b[0]) + abs(b[1]-a[1]);
}

int minCost(vector<vector<int>> &houses){
    int n  = houses.size();
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
    vector<bool> vis(n,false);
    
    minHeap.push({0,0});
    int totalCost=0;
    
    while(!minHeap.empty()){
        int cost = minHeap.top().first;
        int u = minHeap.top().second;
        minHeap.pop();
        
        if(vis[u]){
            continue;
        }
        
        vis[u]=true;
        totalCost+=cost;
        for(int v = 0;v<n;v++){
            if(vis[v]==false){
                int dist = manHattan(houses[u],houses[v]);
                minHeap.push({dist,v});
            }
        }
    }
    
    return totalCost;
}

int main(){
    vector<vector<int>> houses = {{0,0},{1,3},{3,3},{0,3}};
    cout<<"Minimum cost to connect all houses in this city : ";
    cout<<minCost(houses);
    return 0;
}
