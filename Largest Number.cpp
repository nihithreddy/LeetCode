#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),[](const int a,const int b)->bool{
            string s1 = to_string(a)+to_string(b);
            string s2 = to_string(b)+to_string(a);
            return s1>s2;
        });
        string result="";
        for(int i=0;i<n;i++){
            result+=to_string(nums[i]);
        }
        int idx = 0;
        int len = result.size();
        while(idx<len-1&&result[idx]=='0') idx++;
        return result.substr(idx);
    }
};