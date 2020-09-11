#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int mp[10]={0};
        for(int i=0;i<n;i++){
            mp[secret[i]-'0']++;
        }
        int a=0,b=0;
        for(int i=0;i<n;i++){
           if(guess[i]==secret[i]){
               a++;
               mp[secret[i]-'0']--;
           }
        }
        for(int i=0;i<n;i++){
            if(guess[i]!=secret[i] && mp[guess[i]-'0'] >0){
                b++;
                mp[guess[i]-'0']--;
            }
        }
        return to_string(a)+"A"+to_string(b)+"B";
    }
};