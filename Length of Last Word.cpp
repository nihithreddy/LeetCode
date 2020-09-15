#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        int prev=0;
        int i=0;
        while(i<n){
            while(i<n&&s[i]==' ') i++;
            int cur=0;
            while(i<n&&s[i]!=' '){
                cur++;
                i++;
            }
            if(cur>0)prev=cur;
        }
        return prev; 
    }
};