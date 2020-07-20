#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = (int)digits.size();
        int carry = 1;
        for(int i=n-1;i>=0;i--){
            int sum = digits[i]+carry;
            carry = sum/10;
            digits[i] = sum%10;
        }
        if(carry){
            vector<int> new_arr(n+1);
            new_arr[0]=carry;
            copy(new_arr.begin()+1,new_arr.end(),digits.begin());
            return new_arr;
        }
        else{
            return digits;
        }
    }
};