#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
         int n = (int)s.size();
         if(n<=1){
             return false;
         }
         string substr = "";
        for(int i=0;i<n/2;i++){
            substr+=s[i];
            if(n%(i+1)==0&&isValid(substr,s)){
                return true;
            }
        }
        return false;
    }
    bool isValid(string &s,string &t){
         int n = (int)s.size();
         int m = (int)t.size();
         for(int i=0;i<m;i++){
             if(t[i]!=s[i%n]){
                 return false;
             }
         }
        return true;
    }
};