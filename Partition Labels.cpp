#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string S) {
          int last[26]={0};
          int n = S.size();
          vector<int> parts;
          for(int i=0;i<n;++i){
              last[S[i]-'a'] = i;
          }
          int start=0;
          while(start!=n){
              int end = last[S[start]-'a'];
              if(end == n-1){
                  parts.push_back(end-start+1);
                  break;
              }
              for(int i = start+1;i<end;++i){
                  int cur = last[S[i]-'a'];
                  if(cur>end){
                      end = cur;
                  }
                  if(end == n-1){
                      break;
                  }
              }
              parts.push_back(end-start+1);
              start = end+1;
          }
        return parts;
    }
};