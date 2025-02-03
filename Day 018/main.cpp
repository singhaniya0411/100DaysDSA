#include<iostream>
#include<string>
#include<vector>
using namespace std;

void computeLPS_Array(string pattern, int lps[]){
    int m = pattern.length();
    int len = 0;
    lps[0]=0;
    int i = 1;
    while(i<m){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else{
            if(len!=0){
                len = lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
    }
    }
}

void KMP_algorithm(string text, string pattern){
    int m = text.length();
    int n = pattern.length();
    
    vector<int> lps(n,0);
    computeLPS_Array(pattern,lps);
    
    vector<int> res;
    int i=0;
    int j = 0;
    
    while(i<m){
        if(text[i] == pattern[j]){
            i++;
            j++;
            
            if(j==n){
                res.push_back(i - j);
                j=lps[j-1];
            }
        }
        else{
            if(j!=0){
                j=lps[j-1];
            }
            else{
                i++;
            }
        }
    }
    
    if(res.empty()){
        cout<<"No occurence found.\n";
    }else{
    for(int a=0;a<res.size();a++){
        cout<<"Found at "<<res[a]<<"\n";
    }
        
    }
}

 

int main(){
    
    string text;
    getline(cin,text);
    string pattern;
    getline(cin,pattern);
    KMP_algorithm(text,pattern);
    return 0;
}
