/*
    Title: Rotten Oranges Problem (Minimum Time to Rot All Oranges)

    Problem Statement:
        - You are given a grid (n x m) where:
            0 → Empty cell
            1 → Fresh orange
            2 → Rotten orange
        - Every minute, a rotten orange makes its 4-directionally adjacent
          fresh oranges rotten.
        - Return the minimum time required so that no fresh orange remains.
        - If it is impossible, return -1.

    Example:
        Input:
            mat = {
                {2,1,1},
                {1,1,0},
                {0,1,1}
            }
        Output:
            4

    Explanation:
        - At time 0: One rotten orange at (0,0).
        - At time 1: Oranges at (0,1) and (1,0) rot.
        - At time 2: Oranges at (0,2) and (1,1) rot.
        - At time 3: Orange at (2,1) rots.
        - At time 4: Orange at (2,2) rots → all oranges rotten.

    Approach:
        1. Use a queue (BFS) to simulate the rotting process.
        2. Push all initially rotten oranges into the queue.
        3. Perform BFS level by level:
            - For each rotten orange, rot its 4 neighbors.
            - Push newly rotten oranges into the queue.
        4. Track elapsed time with each BFS level.
        5. After BFS, check if any fresh orange is left:
            - If yes, return -1.
            - Otherwise, return elapsedTime - 1.

    Time Complexity:
        - O(n * m), where n = rows, m = columns
          (each cell is visited at most once)

    Space Complexity:
        - O(n * m), for the queue and visited states.

    Output:
        - Minimum time for all oranges to rot, or -1 if impossible.

    Author: Vishal Singhaniya
*/


#include<iostream>
#include<deque>
#include<vector>
using namespace std;

bool isSafe(int x,int y, int n , int m){
    if(x<0 || x>=n || y<0 || y>=m){
        return false;
    }
    return true;
}


int rottenOranges(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();
    
    deque<pair<int,int>> q;
    
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(mat[i][j]==2){
                q.push_back({i,j});
            }
        }
    }
    
    int elapsedTime = 0;
    
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    
    while(!q.empty()){
        elapsedTime++;
        
        int l = q.size();
        
        for(int k=0;k<l;k++){
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            
            for(auto d : dir){
                x = x + d[0];
                y = y + d[1];
                
                if(isSafe(x,y,n,m) && mat[x][y]==1){
                    mat[x][y]=2;
                    q.push_back({x,y});
                }
            }
        }
    }
    
    for(int i = 0;i<n;i++){
        for(int j =0;j<m;j++){
            if(mat[i][j]==1){
                return -1;
            }
        }
    }
    
    return elapsedTime==0 ? 0 : elapsedTime-1;
}


int main(){
    vector<vector<int>>mat = {{2,1,1},{2,0,1},{1,0,1}};
    
    cout<<"Minimum time required to rotten all oranges : "<<rottenOranges(mat);
    return 0;
}