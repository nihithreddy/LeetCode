class Solution {
public:
    string reverseWords(string s) {
        vector<string> tokens;
        string t = "";
        for(char ch:s){
            if(ch==' '){
                if(t.length()>0){
                    tokens.push_back(t);
                    t="";
                }
            }
            else{
               t+=ch;
            }
        }
        if(t.length()>0){
            tokens.push_back(t);
        }
        reverse(tokens.begin(),tokens.end());
        int n = tokens.size();
        string ans = "";
        for(int i=0;i<n;i++){
            ans+=tokens[i];
            if(i!=n-1){
                ans+=" ";
            }
        }
        return ans;
    }
};