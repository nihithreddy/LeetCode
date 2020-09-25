#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) {
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        int n = s.size();
        int m = t.size();
        for(int i=0;i<m;i++) cnt[t[i]-'a']++;
        for(int i=0;i<n;i++) cnt[s[i]-'a']--;
        char added;
        for(int i=0;i<26;i++){
            if(cnt[i]==1){
                added=(char)('a'+i);
                break;
            }
        }
        return added;
    }
};