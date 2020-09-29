class Solution {
public:
    unordered_map<string,bool> dp;
    bool checkPossible(string s,unordered_map<string,int> &ump){
        int n = s.size();
        if(n==0) return true;
        if(dp.find(s)!=dp.end()) return dp[s];
        for(int i=0;i<n;i++){
            string t = s.substr(0,i+1);
            if(ump.find(t)!=ump.end()&&checkPossible(s.substr(i+1),ump)){
                dp[s]=true;
                return true;
            }
        }
        dp[s]=false;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int> ump;
        for(string str:wordDict){
            ump[str]=1;
        }
        return checkPossible(s,ump);
    }
};