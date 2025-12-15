#include<bits/stdc++.h>
using namespace std;

int minMeetingRooms(vector<int>& start, vector<int>& end){
    int n = start.size();
    int room = 0;
    int res = 0;
    
    sort(start.begin(),start.end());
    sort(end.begin(),end.end());
    
    int i = 0,j=0;
    
    while(i<n){
        if(start[i]<end[j]){
            room++;
            i++;
        }
        else{
            room--;
            j++;
        }
        
        res = max(res,room);
    }
    return res;
}

int main(){
    vector<int> start = {2,9,6};
    vector<int> end = {4,12,10};
    cout<<"Number of room required to conduct these meetings : "<<minMeetingRooms(start,end);
    return 0;
}