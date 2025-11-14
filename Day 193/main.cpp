/*
    Title: Count Number of Distinct Subsets in an Array.

    Problem Statement:
        - You are given an array of integers.
        - A subset here is defined as a **sequence of consecutive integers**
          such that it forms a chain like:
              
                x, x+1, x+2, ... , y

        - The task is NOT to list all subsets, but simply to count how many
          such distinct consecutive-number subsets exist in the array.

        - A subset STARTS only when:
              (x - 1) does NOT exist in the array.
          Meaning: x is the beginning of a new consecutive chain.

    Example:
        Input:
            arr = [2, 4, 3, 7, 8, 1]
        
        Consecutive groups:
            {1,2,3,4}
            {7,8}

        Output:
            2 subsets

    Approach:
        1. Insert all elements into an unordered_set for O(1) lookup.
        2. For every element x:
               If (x - 1) is NOT present → x starts a new subset.
        3. Count how many such starting points exist.

    Dry Run:
        arr = [100, 4, 200, 1, 3, 2]

        Set = {1,2,3,4,100,200}

        - x=100 → 99 not found → new subset → count=1
        - x=4   → 3 found → not a start
        - x=200 → 199 not found → new subset → count=2
        - x=1   → 0 not found → new subset → count=3
        - x=3   → 2 found → not a start
        - x=2   → 1 found → not a start

        Final Result = 3

    Time Complexity:
        - O(n), since each lookup in unordered_set is O(1).

    Space Complexity:
        - O(n), to store unique elements.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

int minSet(vector<int> &arr){
    unordered_set<int> s(arr.begin(),arr.end());
    
    int count = 0;
    for(int x : arr){
        if(s.find(x-1)==s.end()){
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> arr = {1,2,3,4,200,202,201,40,56};
    cout<<"Minimum number of subset of Consecutive numbers are "<<minSet(arr);
    return 0;

}






