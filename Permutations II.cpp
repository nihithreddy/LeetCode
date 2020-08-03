#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        solve(nums,res,0,n);
        return res;
    }
    bool canSwap(vector<int> nums,int start,int end){
        for(int i=start;i<end;i++){
            if(nums[i]==nums[end]){
                return false;
            }
        }
        return true;
    }
    void solve(vector<int> nums,vector<vector<int>>& ans,int cur,int n){
        if(cur==n){
            ans.push_back(nums);
            return;
        }
        for(int j=cur;j<n;j++){
            if(canSwap(nums,cur,j)){
                swap(nums[cur],nums[j]);
                solve(nums,ans,cur+1,n);
                swap(nums[cur],nums[j]);
            }
       }
    }
};
