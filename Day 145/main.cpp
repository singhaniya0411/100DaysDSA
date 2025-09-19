#include <vector>.
#include <stack>
#include <algorithm>
using namespace std;

vector<vector<int>> constructAdj(int V, vector<vector<int>>& edges) {
    vector<vector<int>> res(V);
    for(auto edge : edges){
        int u = edge[0];
        int v = edge[1];
        res[u].push_back(v);
        res[v].push_back(u);
    }
    return res;
}

void dfs(int start, vector<vector<int>> &adj, vector<bool> &visited) {
    stack<int> st;
    st.push(start);
    visited[start] = true;
    
    while(!st.empty()) {
        int current = st.top();
        st.pop();
        
        for(auto neighbour : adj[current]) {
            if(!visited[neighbour]) {
                visited[neighbour] = true;
                st.push(neighbour);
            }
        }
    }
}

vector<int> articulationPoints(int V, vector<vector<int>>& edges) {
    vector<vector<int>> adj = constructAdj(V, edges);
    vector<int> res;
    
    // For each vertex, check if it's an articulation point
    for(int i = 0; i < V; i++) {
        vector<bool> visited(V, false);
        visited[i] = true; // Remove vertex i
        
        int comp = 0;
        
        // Count connected components after removing vertex i
        for(int j = 0; j < V; j++) {
            if(j != i && !visited[j]) {
                comp++;
                dfs(j, adj, visited);
            }
        }
        
        // If removing vertex i increases number of components, it's articulation point
        if(comp > 1) {
            res.push_back(i);
        }
    }
    
    if(res.empty()) {
        return {-1};
    }
    
    sort(res.begin(), res.end());
    return res;

}


