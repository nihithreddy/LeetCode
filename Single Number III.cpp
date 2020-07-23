#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
       int Xor = 0,first =0,second =0;
       int n = nums.size();
       for(int i=0;i<n;i++){
           Xor^=nums[i];
       }
       int last_set_bit_pos= Xor & ~(Xor -1);
       for(int i=0;i<n;i++){
           if(nums[i]&last_set_bit_pos){
               first^=nums[i];
           }
           else{
               second^=nums[i];
           }
       }
       return {first,second};  
    }
};