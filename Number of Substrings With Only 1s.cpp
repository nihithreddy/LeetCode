class Solution {
    int mod = (int)1e9+7;
public:
    int numSub(string s) {
        int n = (int)s.size();
        int ans = 0;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt++;
                ans = (ans%mod)+(cnt%mod);
            }
            else{
                cnt=0;
            }
        }
        return ans;
    }
};