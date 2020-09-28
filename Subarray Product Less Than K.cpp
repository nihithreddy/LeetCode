#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = (int)nums.size();
        if(k<=1){
            return 0;
        }
        int left=0,right=0,product=1,count=0;
        while(right<n){
            product*=nums[right];
            while(left<n&&product>=k){
                product/=nums[left];
                left++;
            }
            count+=right-left+1;
            right++;
        }
        return count;
    }
};