/*
    Title: Group Shifted Strings.

    Problem Statement:
        - You are given a list of lowercase strings.
        - Two strings belong to the same group if they are "shifted versions"
          of each other.
        - A shifted version means each character is shifted by the same amount.
          
          Example:
                "abc" → shift by 1 → "bcd"
                "xyz" → shift by 2 → "zab"

        - Your task is to group all such shifted strings together.

    Approach:
        1. For each string, generate a "hash" based on how much it is shifted.
           Example:
                "bcd" → normalized to "abc"
                "xyz" → normalized to "abc"
           → Both belong to same group.
        
        2. To generate the hash:
            - Compute shift = s[0] - 'a'
            - Shift every character back by `shift`
            - If it goes below 'a', wrap around using +26
            - The resulting normalized string is the hash.

        3. Use a hashmap:
            - Key   = hash
            - Value = index of group in result

        4. For each string:
            - Compute its hash
            - Insert the string in the correct group

    Example:
        Input:
            arr = ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"]

        Groups:
            ["abc", "bcd", "xyz"]
            ["az", "ba"]
            ["acef"]
            ["a", "z"]

    Dry Run:
        s = "bcd"
        shift = 'b' - 'a' = 1
        Normalize:
            'b'→'a', 'c'→'b', 'd'→'c' → "abc"
        Group under "abc"

        Final groups formed accordingly.

    Time Complexity:
        - O(N * L)
          where:
            N = number of strings,
            L = maximum string length.

    Space Complexity:
        - O(N * L) for storing grouped strings and hash map entries.

    Applications:
        - String pattern grouping
        - Detecting rotation/shift equivalence classes
        - Text normalization tasks

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;


string getHash(string s){
    int shifts=s[0]-'a';
    
    for(char &ch:s){
        ch=ch-shifts;
        if(ch<'a'){
            ch+=26;
        }
    }
    return s;
}
vector<vector<string>> groupShiftedString(vector<string> &arr) {
    // Your code here
    vector<vector<string>> res;
    
    unordered_map<string,int> mp;
    
    for(string s:arr){
        string hash = getHash(s);
        if(mp.find(hash)==mp.end()){
            mp[hash]=res.size();
            res.push_back({});
        }
        
        res[mp[hash]].push_back(s);
    }
    return res;
}


int main(){
    vector<string> arr = {"acd", "dfg", "wyz", "yab", "mop", "bdfh", "a", "x", "moqs"};
    
    vector<vector<string>> res = groupShiftedString(arr);
    
    cout<<"\nThe groups of string based on shifting : \n\n";
    
    for (vector<string> &group : res) {
        for (string &s : group) {
            cout << s << " ";
        }
        cout << endl;
    }
    return 0;

}







