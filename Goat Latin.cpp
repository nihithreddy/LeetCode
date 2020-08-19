#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isVowel(char c){
        c= tolower(c);
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    string toGoatLatin(string S) {
        stringstream ss(S);
        vector<string> vs;
        string s;
        while(getline(ss,s,' ')){
            vs.push_back(s);
        }
        int cnt = 1;
        for(string& s:vs){
            int n = s.size();
            if(isVowel(s[0])){
                s+="ma";
            }
            else{
                s=s.substr(1)+s[0]+"ma";
            
            }
            for(int k=1;k<=cnt;k++){
                s+="a";
            }
            cnt++;
        }
        string ans = "";
        for(string s:vs){
            ans+=s;
            ans+=" ";
        }
        return ans.substr(0,ans.size()-1);
    }
};