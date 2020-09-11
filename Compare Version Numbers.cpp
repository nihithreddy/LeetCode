#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> split(string str){
        vector<string> tokens;
        string cur="";
        for(char c:str){
            if(c=='.'){
                tokens.push_back(cur);
                cur="";
                continue;
            }
            cur+=c;
        }
        tokens.push_back(cur);
        return tokens;
    }
    int to_int(string s){
        int num = 0;
        for(char c:s){
            num = num*10+(c-'0');
        }
        return num;
    }
    int compareVersion(string version1, string version2) {
          vector<string> v1 = split(version1);
          vector<string> v2 = split(version2);
          int n = (int)v1.size();
          int m = (int)v2.size();
          int mx = max(n,m);
          int mi = min(n,m);
          if(n==mi && n!=m){
              v1.resize(mx);
              for(int i=n;i<mx;i++){
                  v1[i]="0";
              }
          }
          else if(m==mi && n!=m){
              v2.resize(mx);
              for(int i=m;i<mx;i++){
                  v2[i]="0";
              } 
          }
          for(int i=0;i<mx;++i){
              int res1 = to_int(v1[i]);
              int res2 = to_int(v2[i]);
              if(res1 > res2){
                  return 1;
              }
              else if(res1 < res2){
                  return -1;
              }
          }
          return 0;
        
    }
};