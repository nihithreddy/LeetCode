#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> combs;
    void solve(vector<int>& comb,int k,int cur,int n){
        if(n==0 && k==0){
            combs.push_back(comb);
            return;
        }
        for(int i=cur;i<=9;i++){
            if(n-i>=0){
                comb.push_back(i);
                solve(comb,k-1,i+1,n-i);
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        if(k<=45){
            solve(comb,k,1,n);
        }
        return combs;
    }
};