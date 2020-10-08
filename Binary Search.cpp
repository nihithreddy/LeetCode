/* Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums. 
If target exists, then return its index, otherwise return -1. */
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=(int)nums.size();
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m]==target){
                return m;
            }
            else if(nums[m]>target){
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return -1;
    }
};