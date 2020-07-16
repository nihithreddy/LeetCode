#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = (int)nums.size();
        map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]+=1;
        }
        int ans = 0;
        for(pair<int,int> p:m){
            if(p.second>1){
                ans+=(p.second)*(p.second-1)/2;
            }
        }
        return ans;
    }
};