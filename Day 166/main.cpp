/*
    Title: Convert Integer to English Words

    Problem Statement:
        - Given a non-negative integer `n`, convert it into its equivalent English words.
        - The output should be properly spaced and formatted.
        - Handle numbers in the range of billions, millions, thousands, hundreds, tens, and units.

    Approach:
        1. Divide the number into groups of three digits (thousands, millions, billions).
        2. For each 3-digit group:
            - Handle hundreds, tens, and ones separately.
            - Use predefined word arrays for units (1–19) and tens (20, 30, ... 90).
        3. Append appropriate multipliers ("Thousand", "Million", "Billion") for each group.
        4. Concatenate all groups and remove trailing spaces.

    Example:
        Input:
            n = 25006326

        Process:
            - Split into groups: 25 | 006 | 326
            - "Twenty Five Million Six Thousand Three Hundred Twenty Six"

        Output:
            Number name to the integer 25006326 is Twenty Five Million Six Thousand Three Hundred Twenty Six

    Time Complexity:
        - O(log₁₀N), as we process each 3-digit group once.

    Space Complexity:
        - O(1), using only small helper arrays for words and multipliers.

    Author: Vishal Singhaniya
*/


#include<bits/stdc++.h>
using namespace std;

string convertToWords(int n) {
    // code here
    if(n==0){
        return "Zero";
    }
    vector<string> unit = {"","One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Eleven",
        "Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"
    };
    
    vector<string> tens = {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    vector<string> multiplier = {"","Thousand","Million","Billion"};
    
    string res = "";
    int group=0;
    while(n>0){
        if(n%1000!=0){
            int val = n%1000;
            string temp = "";
            
            
            if(val>=100){
                temp=unit[val/100]+" Hundred ";
                val%=100;
            }
            
            if(val>=20){
                temp+=tens[val/10]+ " ";
                val%=10;
            }
            
            if(val>0){
                temp+=unit[val]+" ";
            }
            
            temp+=multiplier[group]+" ";
            
            res=temp+res;
        }
        
        n/=1000;
        group++;
    }
    return res.substr(0,res.find_last_not_of(" ")+1);
}


int main(){
    
    int n = 25006326;
    string res = convertToWords(n);
    
    cout<<"Number name to the integer "<<n<<" is "<<res<<"\n";
    
    return 0;
}
