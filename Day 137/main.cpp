/*
    Title: Maximum Number of Partitions of a String.

    Problem Statement:
        - Given a string s, partition it into as many parts as possible 
          so that each letter appears in at most one part.
        - Return the maximum number of such partitions.

    Example:
        Input:
            s = "ababcbacadefegdehijhklij"
        Output:
            3
        Explanation:
            - The string can be partitioned as "ababcbaca", "defegde", "hijhklij".
            - Each character appears in only one partition.

    Approach:
        1. Traverse the string and record the last occurrence of every character.
        2. Iterate again, and for each index:
             • Track the farthest last occurrence (`last`).
             • If current index equals `last`, we can "cut" the partition here.
        3. Count the number of partitions.

    Time Complexity:
        - O(n), where n = length of string.
          (One pass to store last occurrences, one pass to compute partitions)

    Space Complexity:
        - O(1), as at most 26 characters (for lowercase English letters) 
          are stored in the map.

    Output:
        - Returns the maximum number of partitions possible.

    Author: Vishal Singhaniya
*/

#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;



int maxPartitions(string &s) {
    int n = s.size();
    int ans = 0;
    
    unordered_map<char,int> map;
    
    for(int i = 0;i<n;i++){
        map[s[i]]=i;
    }
    
    int last=-1;
    
    for(int i = 0;i<n;i++){
        last = max(last,map[s[i]]);
        
        if(last==i){
            ans++;
        }
    }
    
    return ans;
    
}

    
int main(){
    
    string s = "abccbsfdzjjq";
    
    cout<<"Maximum partition of this string : "<<maxPartitions(s);
    return 0;

}






