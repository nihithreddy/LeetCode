#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(string s) {
        int n = (int)s.size();
        if(n<=1){
            return n;
        }
        int freq[256]={0};
        for(char c:s){
            freq[c]++;
        }
        int maxLength = 0,cnt = 0;
        for(int i=0;i<256;i++){
            if(freq[i]&1){
                maxLength+=freq[i]-1;
                cnt++;
            }
            else{
                maxLength+=freq[i];
            }
        }
        return cnt?maxLength+1:maxLength;
        
    }
};