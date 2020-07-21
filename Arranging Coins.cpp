#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int arrangeCoins(int n) {
       int stairs = (-1+sqrt(1+8*1.0*n))/2;
       return stairs;
    }
};