#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int n = A.size();
        int i = 0,j= n-1;
        while(i<j){
            while(i<j&&A[i]%2==0) i++;
            while(i<j&&A[j]%2==1) j--;
            if(i<j){
                swap(A[i],A[j]);
                i++;
                j--;
            }
        }
        return A;
    }
};