#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = (int)prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(3,vector<int>(2,0)));
        dp[0][1][0]=dp[0][2][0]=INT_MAX;
        for(int i=0;i<n;i++){
            dp[i+1][1][0]=min(dp[i][1][0],prices[i]);
            dp[i+1][1][1]=max(dp[i][1][1],prices[i]-dp[i][1][0]);
            dp[i+1][2][0]=min(dp[i][2][0],prices[i]-dp[i][1][1]);
            dp[i+1][2][1]=max(dp[i][2][1],prices[i]-dp[i][2][0]);
        }
        return dp[n][2][1];
    }
};