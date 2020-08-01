#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n  = candies.size();
        vector<bool> ans(n);
        int max_candies = 0;
        for(int i = 0;i<n;i++){
            max_candies = max(max_candies,candies[i]);
        }
        for(int i=0;i<n;i++){
            if(candies[i]+extraCandies>=max_candies){
                ans[i] = true;
            }
            else{
                ans[i] = false;
            }
        }
        return ans;
    }
};