/*
    Title: Count Number of Islands in a Grid (DFS – 8 Directions)

    Problem Statement:
        - You are given a 2D grid of characters:
            • 'L' → land
            • 'W' → water
        - An island is a group of connected 'L' cells.
        - Connectivity is allowed in **8 directions** (vertical, horizontal, and diagonal).
        - Task: Count the total number of islands.

    Example:
        Input:
            grid = {
                        {'W','L'},
                        {'L','W'},
                        {'L','L'},
                        {'L','W'}
                   }
        Output:
            No of island : 1

        Explanation:
            - Island 1: cells (0,1), (1,0), (2,0), (2,1), (3,0)
            
    Approach:
        1. Traverse each cell of the grid.
        2. If a cell contains 'L' and is not visited:
            • Perform DFS to mark all connected 'L' cells as visited.
            • Increment the island counter.
        3. DFS explores all 8 directions using relative coordinate arrays.

    Time Complexity:
        - O(N * M), where N = number of rows, M = number of columns.

    Space Complexity:
        - O(N * M) for visited matrix + recursion stack.

    Output:
        - Prints the number of islands in the given grid.

    Author: Vishal Singhaniya
*/


#include <bits/stdc++.h>
using namespace std;


bool isSafe (int x,int y,vector<vector<bool>> &visited , vector<vector<char>> & grid){
    int row = grid.size();
    int col = grid[0].size();
    
    if(x<0 || x>=row || y<0 || y>=col || visited[x][y]){
        return false;
        
    }
    return true;
}


void dfs(int i,int j ,vector<vector<bool>> &visited , vector<vector<char>> & grid){
    vector<int> rowNum = {-1,-1,-1,0,0,1,1,1};
    vector<int> colNum = {-1,0,1,-1,1,-1,0,1};
    
    visited[i][j]=true;
    
    for(int k = 0 ;k<8;k++){
        int x = i + rowNum[k];
        int y = j + colNum[k];
        if(isSafe(x,y,visited,grid)){
            dfs(x,y,visited,grid);
        }
    }
}


int countIsland(vector<vector<char>> & grid){
    int row = grid.size();
    int col = grid[0].size();
    
    vector<vector<bool>> visited (row,vector<bool>(col,false));
    
    int count = 0;
    
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col ;j ++){
            if(grid[i][j]=='L' && !visited[i][j]){
                dfs(i,j,visited,grid);
                count++;
            }
        }
    }
    return count;
}

int main() {
	int n =4;
	int m = 2;
	
	vector<vector<char>> grid = {{'W','L'},{'L','W'},{'L','L'},{'L','W'}};
	
	int res = countIsland (grid);
	
	cout<<"No of island : "<<res;
	

}