#include<bits/stdc++.h>
using namespace std;
class Solution {
    map<string,string> months = {
        {"Jan","01"},
        {"Feb","02"},
        {"Mar","03"},
        {"Apr","04"},
        {"May","05"},
        {"Jun","06"},
        {"Jul","07"},
        {"Aug","08"},
        {"Sep","09"},
        {"Oct","10"},
        {"Nov","11"},
        {"Dec","12"}
    };
public:
    string reformatDate(string date) {
        vector<string> vs;
        string str = "";
        for(char ch:date){
            if(ch!=' '){
                str+=ch;
            }
            else{
                vs.push_back(str);
                str="";
            }
        }
        vs.push_back(str);
        string ans = "";
        ans+=vs[2]+"-";
        ans+=months[vs[1]]+"-";
        if(vs[0].length()==3){
            ans+="0"+vs[0].substr(0,1);
        }
        else{
            ans+=vs[0].substr(0,2);
        }
        return ans;
    }
};