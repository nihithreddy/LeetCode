#include<bits/stdc+.h>
using namespace std;
class Solution {
public:
    int dp[365];
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = (int)days.size();
        int minCost = solve(days,0,costs[0],costs[1],costs[2]);
        memset(dp,0,sizeof(dp));
        return minCost;
    }
    int solve(vector<int>& days,int idx,int cost1,int cost2,int cost3){
        if(idx==(int)days.size()){
            return 0;
        }
        if(dp[idx]!=0){
            return dp[idx];
        }
        //Case 1 Buying a ticket on each day
        int dayCost = cost1+solve(days,idx+1,cost1,cost2,cost3);
        //Case 2 Buying a ticket for a week
        int i=0;
        for(i=idx+1;i<(int)days.size();i++){
            if(days[i]-days[idx]>6){
                break;
            }
        }
        int weekCost = cost2+solve(days,i,cost1,cost2,cost3);
        //Case 3 Buying a ticket for 30 days
        i=0;
        for(i=idx+1;i<(int)days.size();i++){
            if(days[i]-days[idx]>29){
                break;
            }
        }
        int monthlyCost = cost3+solve(days,i,cost1,cost2,cost3);
        return dp[idx]=min({dayCost,weekCost,monthlyCost});
        
    }
};