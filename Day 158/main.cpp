/*
    Title: Generate All Subsets of a Set (Power Set)

    Problem Statement:
        - You are given an array of integers.
        - The task is to generate all possible subsets (the power set).
        - Each element may either be included or excluded from a subset.

    Approach (Bitmask Enumeration):
        1. For an array of size n, the total number of subsets = 2^n.
        2. Use a bitmask (integer from 0 to (1<<n)-1).
            - If the j-th bit is set, include arr[j] in the subset.
        3. Collect all subsets in a result vector.

    Example:
        Input:
            arr = {2, 3, 5}

        Process:
            - Total subsets = 2^3 = 8
            - i = 0 (000) → {}
            - i = 1 (001) → {2}
            - i = 2 (010) → {3}
            - i = 3 (011) → {2,3}
            - i = 4 (100) → {5}
            - i = 5 (101) → {2,5}
            - i = 6 (110) → {3,5}
            - i = 7 (111) → {2,3,5}

        Output:
            { }, {2}, {3}, {2,3}, {5}, {2,5}, {3,5}, {2,3,5}

    Time Complexity:
        - O(2^n * n), since each subset generation takes O(n).
        - For n elements, 2^n subsets are possible.

    Space Complexity:
        - O(2^n * n), to store all subsets.

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &arr){
    int n = arr.size();
    int total = 1 << n;
    
    vector<vector<int>> res;
    
    for(int i = 0; i < total; i++){
        vector<int> subset;
        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                subset.push_back(arr[j]);
            }
        }
        res.push_back(subset);
    }
    
    return res;
}

int main(){
    vector<int> arr = {2,3,5};
    vector<vector<int>> res = subsets(arr);
    
    cout << "Subsets are: ";
    for(auto sub : res){
        cout << "{";
        for(auto elem : sub){
            cout << elem << " ";
        }
        cout << "}, ";
    }
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &arr){
    int n = arr.size();
    int total = 1<<n;
    
    vector<vector<int>> res ;
    
    for(int i = 0;i<total;i++){
        vector<int> subset ;
        for(int j = 0;j<n;j++){
            if(i&(1<<j)){
                subset.push_back(arr[j]);
            }
        }
        
        res.push_back(subset);
    }
    
    return res;
}

int main(){
    vector<int> arr = {2,3,5};
    vector<vector<int>> res = subsets(arr);
    
    cout<<"Subsets are : ";
    for( auto sub:res){
        cout<<"{";
        for(auto elem: sub){
            cout<<elem<<" ";
        }
        cout<<"}, ";
    }
    return 0;
}