/*
    Title: Floyd-Warshall Algorithm (All Pairs Shortest Path).

    Problem Statement:
        - You are given a weighted directed graph represented by an adjacency matrix.
        - dist[i][j] represents the weight of the edge from i → j.
            - If no edge exists, dist[i][j] = 1e8 (infinity).
        - The task is to compute the shortest path between every pair of vertices.

    Approach (Dynamic Programming):
        1. Initialize the distance matrix with given edge weights.
        2. For each intermediate vertex k:
            - Update every pair (i, j) as:
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
              if both dist[i][k] and dist[k][j] are not infinity.
        3. After completion, dist[i][j] contains the shortest path from i to j.
        4. If dist[i][i] < 0 for any i → negative cycle exists.

    Example:
        Input (Adjacency Matrix):
            V = 4
            dist = { {0,   5,  1e8, 10},
                     {1e8, 0,   3,  1e8},
                     {1e8, 1e8, 0,   1},
                     {1e8, 1e8, 1e8, 0} }

        Output (Shortest Paths):
            0   5   8   9
            1e8 0   3   4
            1e8 1e8 0   1
            1e8 1e8 1e8 0

    Dry Run:
        - k = 0 → no new updates.
        - k = 1 → updates dist[0][2] via (0→1→2).
        - k = 2 → updates dist[0][3] via (0→2→3).
        - k = 3 → no new updates.
        - Final result is the shortest paths matrix.

    Time Complexity:
        - O(V³), as three nested loops run over vertices.

    Space Complexity:
        - O(V²), for the distance matrix.

    Author: Vishal Singhaniya
*/


#include <bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<double>> &dist) {
    int V = dist.size();
    
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != 1e8 && dist[k][j] != 1e8) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int V = 5;
    vector<vector<double>> dist={{0, 4, 1e8, 5, 1e8}, {1e8, 0, 1, 1e8, 6}, {2, 1e8, 0, 3, 1e8}, {1e8, 1e8, 1, 0, 2},{1,1e8,1,4,0}};

    floydWarshall(dist);

    cout << "All Pairs Shortest Path Matrix:\n";
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] == 1e8)
                cout << "INF ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << "\n";
    }

    return 0;
}



