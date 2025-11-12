/*
    Title: Maximum Distance Between equal Elements in an Array.

    Problem Statement:
        Given an array of integers, find the maximum distance between
        two equal elements in the array.  
        The distance is defined as the difference between their indices.

    Example:
        Input:
            arr = [1, 2, 3, 2, 1, 4, 1]
        Output:
            6
        Explanation:
            The element '1' appears at indices 0, 4, and 6.
            Maximum distance = 6 - 0 = 6.

    Approach:
        1. Use an unordered_map to store the **first occurrence index**
           of each element.
        2. Traverse the array:
            - If the element is seen for the first time, store its index.
            - If it already exists, calculate the distance between the 
              current index and its first occurrence.
            - Keep track of the maximum distance found so far.
        3. Return the maximum distance.

    Dry Run:
        arr = [1, 2, 3, 2, 1]
        i=0 → store(1,0)
        i=1 → store(2,1)
        i=2 → store(3,2)
        i=3 → res = max(0, 3-1=2)
        i=4 → res = max(2, 4-0=4)
        Final Result = 4

    Time Complexity: O(n)
    Space Complexity: O(n)

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<int> &arr){
    unordered_map<int,int> map;
    
    int res = 0;
    for(int i = 0;i<arr.size();i++){
        if(map.find(arr[i])==map.end()){
            map[arr[i]]=i;
        }
        else{
            res=max(res,i-map[arr[i]]);
        }
    }
    
    return res;
}

int main(){
    vector<int> arr= {1,2,3,2,4,9,2,6,1,8};
    cout<<"\nMaximum Distance Between Equal Elements in this Array : "<<maxDistance(arr);
    return 0;

}







