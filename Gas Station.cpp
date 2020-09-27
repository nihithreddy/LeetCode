#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = (int)gas.size();
        for(int i=0;i<n;i++){
            if(gas[i]>=cost[i]){
                int cur = (i+1)%n;
                int amount = gas[i]-cost[i];
                while(cur!=i){
                    if(amount+gas[cur]<cost[cur]) break;
                    amount+=gas[cur]-cost[cur];
                    cur=(cur+1)%n;
                }
                if(cur==i) return i;
            }
        }
        return -1;
    }
};