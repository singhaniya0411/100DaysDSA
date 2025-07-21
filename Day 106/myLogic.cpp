#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int getMaxArea(vector<int> arr) {
    int n = arr.size();
    
    int ans = 0;
    
    for(int i = 0 ;i<n;i++){
        int l = i;
        int r = i;
        while(l>0){
            if(arr[l-1]>=arr[i]){
                l--;
            }
            else{
                break;
            }
        }
        while(r<n-1){
            if(arr[r+1]>=arr[i]){
                r++;
            }
            else{
                break;
            }
        }
        
        ans = max(ans,arr[i]*((r-l)+1));
    }
    
    return ans;
    
}

// Main function to test the logic
int main() {
    vector<int> input = {1,2,3,4,5,6,7,8,8};
    int output = getMaxArea(input);

    cout << "Largest Rectangle Area: " << output << endl;
    return 0;
}