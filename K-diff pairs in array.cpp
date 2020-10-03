/*
Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

0 <= i, j < nums.length
i != j
a <= b
b - a == k
*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
           unordered_set<int> us1,us2;
           int n = nums.size();
           int pairs = 0;
           for(int i=0;i<n;i++){
                if(us1.find(nums[i]-k)!=us1.end()&&us2.find(nums[i]-k)==us2.end()){
                    pairs++;
                    us2.insert(nums[i]-k);
                }
                if(us1.find(nums[i]+k)!=us1.end()&&us2.find(nums[i])==us2.end()){
                    pairs++;
                    us2.insert(nums[i]);
                }
                us1.insert(nums[i]);
           }
        return pairs;
    }
};