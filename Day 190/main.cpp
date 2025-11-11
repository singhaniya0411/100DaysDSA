/*
    Title: Roman to Decimal Conversion

    Problem Statement:
        Given a string representing a Roman numeral,
        convert it into its corresponding decimal (integer) value.

    Roman Numerals and Their Values:
        I → 1
        V → 5
        X → 10
        L → 50
        C → 100
        D → 500
        M → 1000

    Example:
        Input:
            s = "MCMIV"
        Output:
            1904

        Explanation:
            M  = 1000
            CM = 900  (100 before 1000 → subtract)
            IV = 4    (1 before 5 → subtract)
            Total = 1000 + 900 + 4 = 1904

    Approach:
        1. Create a hash map (unordered_map) to store Roman numeral values.
        2. Traverse the string from left to right.
        3. For each character:
            - If the current numeral is less than the next one,
              subtract its value (handle cases like IV, IX, XL, etc.).
            - Otherwise, add its value.
        4. Return the accumulated result.

    Dry Run:
        s = "IX"
        I (1) < X (10)
        → result = 10 - 1 = 9

    Time Complexity: O(n)
    Space Complexity: O(1)

    Author: Vishal Singhaniya
*/

#include<bits/stdc++.h>
using namespace std;


int romanToDecimal(string &s) {
    // code here
    unordered_map<char,int> romanMap = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    
    int res = 0;
    
    for(int i =0 ;i<s.size();i++){
        if(i+1 < s.size() && romanMap[s[i]]<romanMap[s[i+1]]){
            res+=romanMap[s[i+1]] - romanMap[s[i]];
            i++;
        }
        else{
            res+=romanMap[s[i]];
        }
    }
    return res;
}

int main(){
    
    string romanNum = "LXXVI";
    cout<<"Roman to int conversion for string : "<<romanToDecimal(romanNum);
    return 0;

}











