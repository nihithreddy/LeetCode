#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n<=1){
            return 0;
        }
        int max_profit = 0;
        int sell_price = prices[0];
        for(int i=1;i<n;i++){
            max_profit = max(max_profit,prices[i]-sell_price);
            sell_price = min(sell_price,prices[i]);
        }
        return max_profit;
    }
};