#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2,-1);
        int n=nums.size();
        if(n==0){
            return res;
        }
        int s=0,e=n-1,m=0;
        while(s<=e){
            m=(s+e)/2;
            //cout<<s<<" "<<e<<endl;
            if(nums[m]==target){
                res[0]=m;
                e=m-1;
            }
            else if(nums[m]<target){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        s=0,e=n-1,m=0;
        while(s<=e){
            //cout<<s<<" "<<e<<"\n";
            m=(s+e)/2;
            if(nums[m]==target){
                res[1]=m;
                s=m+1;
            }
            else if(nums[m]>target){
                e=m-1;
            }
            else{
               s=m+1;
            }
        }
        return res;
    }
};