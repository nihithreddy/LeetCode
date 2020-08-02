#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n<=1){
            return n;
        }
        int max_length = 1,length = 1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                length++;
            }
            else{
                max_length = max(length,max_length);
                length = 1;
            }
        }
        max_length = max(length,max_length);
        return max_length;
    }
};