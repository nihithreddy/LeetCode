#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitals = 0;
        int n = word.size();
        for(char ch:word){
            if(isupper(ch)) capitals++;
        }
        return (capitals==0||capitals==n||(capitals==1&&isupper(word[0])));
    }
};