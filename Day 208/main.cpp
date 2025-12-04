/*
    Title: Generating IP Addresses

    Problem Statement:
        - Given a string `s` containing only digits, return all possible valid IPv4 addresses
          that can be formed by inserting three dots into `s`.
        - An IPv4 address consists of four decimal numbers (each between 0 and 255) separated by dots.
        - Each of the four parts must not contain leading zeros unless the part is exactly "0".

    Example:
        Input:  s = "25525511135"
        Output: ["255.255.11.135", "255.255.111.35"]

    Approach (Backtracking / Recursion):
        1. Use a recursive helper that builds parts one by one.
        2. Maintain:
            - `index` : current position in the string `s`.
            - `cnt`   : how many dots/parts have been placed so far (0..3).
            - `curr`  : the prefix built so far (parts + dots).
            - `res`   : vector to collect valid IP strings.
        3. At each recursion step, try to take 1, 2 or 3 digits from `s` (as long as available).
            - For each candidate substring, check if it is a valid part:
                • Not empty, no leading zeros (except single '0').
                • Its numeric value is between 0 and 255.
            - If valid, recurse from the next index, appending the part and a dot (unless it's the final part).
        4. When `cnt == 3`, treat the remaining substring as the final part and validate it. If valid, append to result.

    Dry Run (brief):
        s = "101023"
        - Try splits like 1.0.10.23, 10.10.2.3, 101.0.2.3, etc.
        - Each candidate part validated (leading zeros and <=255 check) before recursing / finalizing.

    Time Complexity:
        - Upper-bounded by exploring a small constant branching factor (at most 3 choices per part),
          so practically O(1) relative to input length limits (string length <= 12 for any valid IP).
        - For longer `s`, complexity grows but valid IP formation restricts depth; typical bound O(3^4) combinations checked.

    Space Complexity:
        - O(1) extra apart from the recursion stack and output storage. Recursion depth ≤ 4.

    Author: Vishal Singhaniya
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(string& s){
    int n = s.size();
    
    if(n == 0) return false;
    if(n == 1){
        // single digit (including '0') is valid
        return true;
    }
    // leading zero is invalid for multi-digit parts
    if(s[0] == '0') return false;
    
    // numeric value must be <= 255
    int val = stoi(s);
    if(val > 255) return false;
    
    return true;
}

void generateIpRec(int index, vector<string>& res, string& s, string curr, int cnt){
    string temp = "";
    
    if(index >= (int)s.size()){
        return ;
    }
    
    if(cnt == 3){
        // last part: take the rest of the string
        temp = s.substr(index);
        if(temp.size() <= 3 && isValid(temp)){
            res.push_back(curr + temp);
        }
        return;
    }
    
    // try length 1, 2 and 3 for the current part
    for(int i = index; i < min(index + 3, (int)s.size()); i++){
        temp.push_back(s[i]);
        if(isValid(temp)){
            generateIpRec(i + 1, res, s, curr + temp + '.', cnt + 1);
        }
    }
}

vector<string> generateIp(string &s) {
    vector<string> res;
    generateIpRec(0, res, s, "", 0);
    return res;
}

int main(){
    string s = "25525511135";
    vector<string> ips = generateIp(s);
    cout << "Valid IPs from string \"" << s << "\":" << endl;
    for (auto &ip : ips) {
        cout << ip << endl;
    }
    return 0;
}






