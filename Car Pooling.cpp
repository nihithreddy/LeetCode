#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int passengers[1005];
        memset(passengers,0,sizeof(passengers));
        int n = (int)trips.size();
        for(int i=0;i<n;i++){
            int cur_passengers = trips[i][0];
            int start_location = trips[i][1];
            int end_location = trips[i][2];
            passengers[start_location]+=cur_passengers;
            passengers[end_location]-=cur_passengers;
        }
        for(int i=1;i<=1000;i++){
            passengers[i]+=passengers[i-1];
            if(passengers[i]>capacity){
                return false;
            }
        }
        return true;
    }
};