#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    map<string,vector<pair<string,double>>> pairs;
    map<string,bool> vis;
    double solve(string x,string y,double value){
        vis[x]=1;
        //cout<<x<<" ";
        if(x==y && pairs.find(x)!=pairs.end()){
            return value;
        }
        for(pair<string,double> pi:pairs[x]){
            if(!vis[pi.first]){
               double ans = solve(pi.first,y,value*pi.second*1.0);
                if(ans==-1) continue;
                else return ans;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = (int)equations.size();
        for(int i=0;i<n;i++){
            if(pairs.find(equations[i][0])==pairs.end()){
                vector<pair<string,double>> vp;
                vp.push_back({equations[i][1],values[i]});
                pairs[equations[i][0]]=vp;
            }
            else{
                vector<pair<string,double>>& vp = pairs[equations[i][0]];
                vp.push_back({equations[i][1],values[i]});
            }
            if(pairs.find(equations[i][1])==pairs.end()){
                vector<pair<string,double>> vp;
                vp.push_back({equations[i][0],1.0/values[i]});
                pairs[equations[i][1]]=vp;
            }
            else{
                vector<pair<string,double>>& vp = pairs[equations[i][1]];
                vp.push_back({equations[i][0],1.0/values[i]});
            }
        }
        int m = (int)queries.size();
        vector<double> result(m);
        for(int i=0;i<m;i++){
            string x = queries[i][0];
            string y = queries[i][1];
            result[i]=solve(x,y,1.0);
            vis.clear();
            //cout<<endl;
        }
        return result;
        
    }
};