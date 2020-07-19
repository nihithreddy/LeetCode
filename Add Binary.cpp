#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        int n = (int)a.size();
        int m = (int)b.size();
        int sz = max(n,m);
        if(n<m){
            string c="";
            for(int i=0;i<m-n;i++) c+="0";
            a=c+a;
        }
        else if(m<n){
            string c = "";
            for(int i=0;i<n-m;i++) c+="0";
            b=c+b;
        }
        string ans = "";
        int carry = 0,sum=0;
        for(int i = sz-1;i>=0;i--){
            int c = a[i]-'0';
            int d = b[i]-'0';
            sum = (carry+c+d);
            carry = sum/2;
            ans+=to_string(sum%2);  
        }
        if(carry) ans+=to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};