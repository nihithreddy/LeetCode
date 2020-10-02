/*
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. 
Two combinations are unique if the frequency of at least one of the chosen numbers is different.
*/
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