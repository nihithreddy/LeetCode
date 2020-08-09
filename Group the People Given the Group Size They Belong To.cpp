#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        map<int,int> mp;
        vector<vector<int>> groups;
        vector<int> group;
        for(int i=0;i<n;i++){
            mp[groupSizes[i]]++;
        }
        for(auto pi:mp){
            mp[pi.first]=pi.second/pi.first;
            for(int i=0,k=0;i<n&&k<mp[pi.first];i++){
                if(groupSizes[i]==pi.first){
                   group.push_back(i);
                    if(group.size()==pi.first){
                        groups.push_back(group);
                        group.clear();
                        k++;
                    }
                }
            }
            
        }
        return groups;
    }
};