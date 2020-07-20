#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        int n = (int)s.size();
        if(n==0) return 0;
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        for(int i=1;i<=n;i++){
            if(s[i-1]!='0'){
                dp[i]=dp[i-1];
            }
            if(i-2>=0&&(s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<='6'))){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
        
    }
};