/*
    Title: Flood Fill Algorithm (DFS Approach)

    Problem Statement:
        - Given a 2D image (matrix of integers), each integer represents a pixel color.
        - Starting from a given pixel (sr, sc), replace the entire connected region
          of the same color (4-directionally connected) with a new color.

    Example Input:
        images = {
            {1, 1, 0, 1},
            {0, 1, 0, 0},
            {1, 0, 1, 0},
            {1, 1, 0, 0}
        }
        sr = 2, sc = 3, newColor = 2

    Output (exact program printout):
        Current image :
        1  1  0  1
        0  1  0  0
        1  0  1  0
        1  1  0  0


        Updated image :
        1  1  2  1
        0  1  2  2
        1  0  1  2
        1  1  2  2

        (Explanation: the connected region of zeros that includes position (2,3)
         → {(2,3),(1,3),(1,2),(0,2),(3,3),(3,2)} gets recolored to 2.)

    Approach (Depth First Search):
        1. If the starting pixel already has newColor, return immediately.
        2. Save oldColor = images[sr][sc].
        3. DFS from (sr, sc), changing each visited pixel from oldColor to newColor.
        4. DFS explores 4 neighbors: up, right, down, left. Stop at boundaries
           or at pixels with a different color.

    Time Complexity:
        - O(N * M), where N = rows and M = columns (each pixel visited at most once).

    Space Complexity:
        - O(N * M) in worst-case recursion depth (when the whole grid is one region).

    Applications:
        - Paint-bucket tools in image editors, region filling, connected component labeling.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &images, int sr, int sc, int oldColor, int newColor){
    if(sr<0 || sr>=images.size() || sc<0 || sc>=images[0].size() || images[sr][sc]!=oldColor){
        return;
    }
    
    vector<int> xDir = {-1,0,1,0};
    vector<int> yDir = {0,1,0,-1};
    
    images[sr][sc]=newColor;
    for(int i = 0;i<4;i++){
        int x = sr+xDir[i];
        int y = sc + yDir[i];
        dfs(images,x,y,oldColor,newColor);
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &images, int sr, int sc, int newColor){
    if(images[sr][sc]==newColor){
        return images;
    }
    
    int oldColor = images[sr][sc];
    dfs(images,sr,sc,oldColor,newColor);
    return images;
}


int main(){
    vector<vector<int>> images = {{1,1,0,1},{0,1,0,0},{1,0,1,0},{1,1,0,0}};
    cout<<"Current image : \n";
    for(auto row : images){
        for(auto val : row){
            cout<<val<<"  ";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    
    int sr = 2;
    int sc = 3;
    int newColor = 2;
    // Calling function 
    vector<vector<int>> updatedImg = floodFill(images,sr,sc,newColor);
    cout<<"Updated image : \n";
    for(auto row : updatedImg){
        for(auto val : row){
            cout<<val<<"  ";
        }
        cout<<"\n";
    }
    
    return 0;
}
