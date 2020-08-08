#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int h = matrix.size();
        if(h==0||matrix[0].empty()){
            return 0;
        }
        int w = matrix[0].size();
        vector<vector<int>> dp(h,vector<int>(w,0));
        int ans = 0;
        for(int row=0;row<h;row++){
            for(int col=0;col<w;col++){
                if(matrix[row][col]=='1'){
                    dp[row][col]=1;
                    if(row&&col){
                        dp[row][col]+=min({dp[row][col-1],dp[row-1][col],dp[row-1][col-1]});
                    }
                    ans=max(ans,dp[row][col]);
                }
            }
        }
        return ans*ans;
    }
};