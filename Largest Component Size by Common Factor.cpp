#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> dsu;
    int find(int p){
       if(dsu[p]==-1){
           return p;
       }
       else{
           dsu[p] = find(dsu[p]);
           return dsu[p];
       }
    }
    void merge(int u,int v){
        int pu = find(u);
        int pv = find(v);
        if(pu!=pv){
            dsu[pv]=pu;
        }
    }
    vector<int> factorize(int n){
        vector<int> factors;
        int m = 2;
        while(m*m<=n){
            if(n%m==0){
                factors.push_back(m);
                while(n%m==0){
                    n=n/m;
                }
            }
            m++;
        }
        if(n>1){
            factors.push_back(n);
        }
        return factors;
        
    }
    int largestComponentSize(vector<int>& A) {
        dsu.resize(100001);
        for(int i=0;i<(int)dsu.size();i++){
            dsu[i]=-1;
        }
        int n = (int)A.size();
        for(int i=0;i<n;i++){
            for(int x=2;x<=sqrt(A[i]);x++){
                if(A[i]%x==0){
                    merge(x,A[i]);
                    merge(A[i],A[i]/x);
                }
            }
        }
        int ans=0;
        unordered_map<int,int> um;
        for(int i=0;i<n;i++){
            int p = find(A[i]);
            um[p]++;
            ans=max(ans,um[p]);
        }
        return ans;
    }
};