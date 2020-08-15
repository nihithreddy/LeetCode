#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<=1||intervals.empty()){
             return 0;
        }
        sort(intervals.begin(),intervals.end(),[](const auto& a,const auto& b) -> int {
            return a[1]<b[1];
        });
        int prevEnd = intervals[0][1];
        int ans = 0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]<prevEnd){
                ans++;
            }
            else{
                prevEnd = intervals[i][1];
            }
        }
        return ans;
    }
};