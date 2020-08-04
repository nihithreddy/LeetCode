#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num == 0){
            return false;
        }
        float log4 = log(num)/log(4);
        return floor(log4) == ceil(log4);
    }
    bool isPowerOfFour1(int num){
        if(num==0){
            return false;
        }
        while(num>1){
            if(num%4!=0){
                return false;
            }
            num = num/4;
        }
        return true;
    }
};