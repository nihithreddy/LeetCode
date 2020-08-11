#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end());
        int hindex = 0;
        for(int i=0;i<n;i++){
            if(citations[i]>=n-i){
                hindex = n-i;
                break;
            }
        }
        return hindex;
    }
};