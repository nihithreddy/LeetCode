#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        int n = (int)A.size();
        vector<int> ans;
        for(int i=n;i>0;i--){
            if(A[i-1]==i) continue;
            int pos = find(A.begin(),A.end(),i)-A.begin()+1;
            reverse(A.begin(),A.begin()+pos);
            reverse(A.begin(),A.begin()+i);
            ans.push_back(pos);
            ans.push_back(i);
        }
        return ans;
    }
};