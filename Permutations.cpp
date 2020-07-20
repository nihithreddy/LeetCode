#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        solve(nums,ans,0,n);
        return ans;
    }
    void solve(vector<int> nums,vector<vector<int>>& ans,int index,int n){
        if(index==n){
            ans.push_back(nums);
            return;
        }
        for(int j=index;j<n;j++){
            swap(nums[index],nums[j]);
            solve(nums,ans,index+1,n);
            swap(nums[index],nums[j]);
        }
    }
};