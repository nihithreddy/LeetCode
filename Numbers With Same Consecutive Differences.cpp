#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int N, int K) {
        if(N==1){
            for(int i=0;i<=9;i++){
                ans.push_back(i);
            }
        }
        else{
            for(int i=1;i<=9;i++){
                solve(i,1,N,K);
            }
        }
        return ans;
    }
    void solve(int num,int count,int N,int K){
        if(count==N){
            ans.push_back(num);
            return;
        }
        int lastDigit = num%10;
        if(lastDigit+K<=9){
            solve(num*10+(lastDigit+K),count+1,N,K);
        }
        if(lastDigit-K>=0&&K!=0){
            solve(num*10+(lastDigit-K),count+1,N,K);
        }
    }
};