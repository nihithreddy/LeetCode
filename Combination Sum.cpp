#include<bits/stdc++.h>
using namespace std;
class Solution {  
public:
    vector<vector<int>> combinations;
    void solve(int cur,int n,vector<int>& candidates,vector<int> combination,int target){
        if(target==0){
            combinations.push_back(combination);
            return;
        }
        if(cur==n){
            return;
        }
        for(int i=cur;i<n;i++){
            if(target-candidates[i]>=0){
                combination.push_back(candidates[i]);
                solve(i,n,candidates,combination,target-candidates[i]);
                combination.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         int n = (int)candidates.size();
         vector<int> combination;
         solve(0,n,candidates,combination,target);
         return combinations;
    }
};