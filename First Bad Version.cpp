// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstBadVersion(int n) {
        long long s=1,e=n,m,ans;
        while(s<=e){
            m=(s+e)/2;
            if(isBadVersion(m)){
                ans=m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return ans;
    }
};