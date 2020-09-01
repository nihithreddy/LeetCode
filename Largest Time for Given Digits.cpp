#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string to_str(int n){
        string s="";
        while(n){
            s+=(char)('0'+n%10);
            n/=10;
        }
        for(int i=2-s.size();i>0;i--) s+="0";
        reverse(s.begin(),s.end());
        return s;
    }
    int to_int(string str){
        int num = 0;
        for(char c:str){
            num = num*10 + (c-'0');
        }
        return num;
    }
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(),A.end());
        string time = "";
        int mx_min= -1;
        do{
            int hour = A[0]*10 + A[1];
            int minute = A[2]*10 + A[3];
            if((hour>=0&&hour<=23&&minute>=0&&minute<=59)){
                int min = hour*60 + minute;
                if(min > mx_min){
                    mx_min = min;
                    time = to_str(hour) +":" + to_str(minute);
                }
            }
            
        }while(next_permutation(A.begin(),A.end()));
        return time;
    }
};