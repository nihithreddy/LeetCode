/*Given a list of intervals, remove all intervals that are covered by another interval in the list.
Interval [a,b) is covered by interval [c,d) if and only if c <= a and b <= d.
After doing so, return the number of remaining intervals.*/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](const vector<int> &a,const vector<int> &b) -> bool{
             if(a[0]==b[0]) return a[1]>b[1];
             return a[0]<b[0];
        });
        int n = (int)intervals.size();
        int count = 0;
        int end = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][1]<=end){
                count++;
            }
            else{
                end=intervals[i][1];
            }
        }
        return n-count;
    }
};