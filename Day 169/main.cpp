/*
    Title: Minimum Sum from Two Numbers Formed by Array Digits

    Problem Statement:
        - Given an array of digits (0–9), form two numbers such that their sum is minimized.
        - The digits of the array must all be used exactly once.
        - Return the minimum possible sum as a string (to handle very large values).

    Approach:
        1. Sort the array in ascending order.
        2. Distribute digits alternately between two numbers `s1` and `s2`:
            - Even indices → `s2`
            - Odd indices → `s1`
        3. Add both strings using a helper function `addString()`, which:
            - Performs digit-by-digit addition from the end.
            - Manages carry values.
            - Removes leading zeros before returning the final result.
        4. Return the resulting sum as a string.

    Example:
        Input:
            arr = [6, 3, 9, 2, 5, 7]

        Process:
            Sorted: [2, 3, 5, 6, 7, 9]
            s1 = "357", s2 = "269"
            Sum = 357 + 269 = 626

        Output:
            Minimum Sum from two integers that can be obtained from the array : 626

    Time Complexity:
        - O(N log N) for sorting + O(N) for addition → O(N log N)

    Space Complexity:
        - O(N) for storing digits and result strings

    Applications:
        - Used in optimization and greedy problems involving digit manipulation
        - Financial and number rearrangement algorithms

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;

string addString(string &s1, string &s2){
    int sum = 0;
    int carry = 0;
    
    int m = s1.size() - 1;
    int n = s2.size() - 1;
    vector<int> res;

    while(m >= 0 || n >= 0 || carry){
        int num1 = (m >= 0) ? s1[m] - '0' : 0;
        int num2 = (n >= 0) ? s2[n] - '0' : 0;
        
        sum = num1 + num2 + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        m--; n--;
    }
    
    reverse(res.begin(), res.end());
    string ans;
    for(int x : res) ans.push_back('0' + x);

    // Remove leading zeros
    int pos = 0;
    while(pos < ans.size() - 1 && ans[pos] == '0') pos++;
    
    return ans.substr(pos);
}

string minSum(vector<int> &arr){
    sort(arr.begin(), arr.end());
    
    string s1 = "", s2 = "";
    for(int i = 0; i < arr.size(); i++){
        if(i % 2 != 0) s1.push_back('0' + arr[i]);
        else s2.push_back('0' + arr[i]);
    }
    return addString(s1, s2);
}

int main(){
    vector<int> arr = {6, 3, 9, 2, 5, 7};
    cout << "Minimum Sum from two integer that can be obtained from the array : " 
         << minSum(arr);
    return 0;
}


#include<bits/stdc++.h>
using namespace std;

string addString(string &s1,string &s2){
    int sum =0;
    int carry = 0;
    
    int m = s1.size()-1;
    int n = s2.size()-1;
    
    vector<int> res;
    int num1 = 0;
    int num2=0;
    
    while(m>=0 || n>=0 || carry){
        if(m<0){
            num1=0;
        }
        else{
            num1=s1[m]-'0';
        }
        if(n<0){
            num2=0;
        }
        else{
            num2=s2[n]-'0';
        }
        
        sum = (num1+num2+carry);
        res.push_back(sum%10);
        carry=sum/10;
        m--;
        n--;
    }
    
    reverse(res.begin(),res.end());
    
    string ans ;
    for(int x : res){
        ans.push_back('0'+x);
    }
    
    int pos = 0;
    while(pos<ans.size()-1 && ans[pos]=='0'){
        pos++;
    }
    
    return ans.substr(pos,ans.size());
}

string minSum(vector<int> &arr){
    sort(arr.begin(),arr.end());
    
    string s1="";
    string s2="";
    
    for(int i = 0;i<arr.size();i++){
        if(i%2!=0){
            s1.push_back('0'+arr[i]);
        }
        else{
            s2.push_back('0'+arr[i]);
        }
    }
    
    return addString(s1,s2);
}

int main(){
    
    vector<int> arr = {6,3,9,2,5,7};
    cout<<"Minimum Sum from two integer that can be obtained from the array : "<<minSum(arr);
    return 0;
}
