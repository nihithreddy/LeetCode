#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = (int)intervals.size();
        vector<int> ans(n,-1);
        if(n==1){
            return ans;
        }
        set<int> starts;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            starts.insert(intervals[i][0]);
            mp[intervals[i][0]]=i;
        }
        for(int i=0;i<n;i++){
            auto it = starts.upper_bound(intervals[i][1]-1);
            if(it == starts.end()) continue;
            else{
                ans[i] = mp[*it];
            }
        }
        return ans;
        
    }
};