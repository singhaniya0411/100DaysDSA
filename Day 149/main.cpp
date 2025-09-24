/*
    Title: Clone an Undirected Graph (DFS Approach).

    Problem Statement:
        - You are given a reference to a node in a connected undirected graph.
        - Each node contains an integer value and a list of neighbors.
        - The task is to return a deep copy (clone) of the graph.

    Node Definition:
        struct Node {
            int val;
            vector<Node*> neighbors;
            Node() {
                val = 0;
                neighbors = vector<Node*>();
            }
            Node(int _val) {
                val = _val;
                neighbors = vector<Node*>();
            }
            Node(int _val, vector<Node*> _neighbors) {
                val = _val;
                neighbors = _neighbors;
            }
        };

    Approach (Depth First Search):
        1. Use a hash map (unordered_map<Node*, Node*>) to store the mapping
           between original node → cloned node.
        2. If a node is already cloned (exists in map), return it to avoid cycles.
        3. Otherwise, create a new node, store it in the map, and recursively
           clone all its neighbors.
        4. Finally, return the clone of the given start node.

    Example Graph:
        Suppose the graph is:
            1 -- 2
            |    |
            4 -- 3

        Input: node = reference to Node(1)
        Output: A cloned graph with the same structure and values.

    Dry Run:
        - Start with Node(1):
            create clone(1), map[1] = clone(1).
            Clone its neighbors (2, 4).
        - For Node(2):
            create clone(2), map[2] = clone(2).
            Clone its neighbors (1, 3). (1 already cloned → reuse).
        - For Node(3):
            create clone(3), map[3] = clone(3).
            Clone neighbors (2, 4).
        - For Node(4):
            create clone(4), map[4] = clone(4).
            Clone neighbors (1, 3). Both already cloned → reuse.

    Time Complexity:
        - O(V + E), where V = number of vertices and E = number of edges.
          Each node and edge is visited once.
    
    Space Complexity:
        - O(V), for hash map and recursion stack.

    Applications:
        - Cloning network structures, dependency graphs, or any object graphs.

    Author: Vishal Singhaniya
*/


#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// DFS helper function
Node* dfs(Node* node, unordered_map<Node*, Node*>& copies) {
    if (copies.count(node)) {
        return copies[node]; // already cloned
    }

    Node* clone = new Node(node->val);
    copies[node] = clone;

    for (auto neighbor : node->neighbors) {
        clone->neighbors.push_back(dfs(neighbor, copies));
    }

    return clone;
}

// Clone graph function
Node* cloneGraph(Node* node) {
    if (node == NULL) return NULL;
    unordered_map<Node*, Node*> copies;
    return dfs(node, copies);
}

// Utility function to print adjacency list of a graph
void printGraph(Node* node) {
    if (!node) return;

    unordered_map<Node*, bool> visited;
    queue<Node*> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << "Node " << curr->val << " -> ";
        for (auto neighbor : curr->neighbors) {
            cout << neighbor->val << " ";
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
        cout << "\n";
    }
}

int main() {
    // Constructing example graph:
    //  1 -- 2
    //  |    |
    //  4 -- 3

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    cout << "Original Graph:\n";
    printGraph(n1);

    Node* clonedGraph = cloneGraph(n1);

    cout << "\nCloned Graph:\n";
    printGraph(clonedGraph);

    return 0;
}



