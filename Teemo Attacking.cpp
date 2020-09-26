#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int poisoned_time = 0;
        int prev_time = 0;
        int n = timeSeries.size();
        for(int i=0;i<n;i++){
            int cur_time = timeSeries.at(i);
            if(cur_time<prev_time){
                poisoned_time += duration-(prev_time-cur_time);
            }
            else{
                poisoned_time+=duration;
            }
            prev_time = cur_time+duration;
        }
        return poisoned_time;
    }
};