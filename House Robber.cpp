#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0){
            return 0;
        }
        vector<int> dp(n+2,0);
        for(int i=2;i<n+2;i++){
            dp[i]=max(dp[i-1],nums[i-2]+dp[i-2]);
        }
        return dp[n+1];
    }
};