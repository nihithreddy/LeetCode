#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // O(n^2) time complexity 
    // O(n) space complexity
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return n;
        }
        vector<int> lis(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]&&lis[j]+1>lis[i]){
                    lis[i]=lis[j]+1;
                }
            }
        }
        int max_length = 1;
        for(int i=1;i<n;i++){
            max_length=max(max_length,lis[i]);
        }
        return max_length;
    }
};