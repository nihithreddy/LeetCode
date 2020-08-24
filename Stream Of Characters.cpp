#include<bits/stdc++.h>
using namespace std;
struct Trie{
    public:
    Trie *t[26];
    bool isEnd;
    Trie(){
        for(int i=0;i<26;i++){
            t[i] = NULL;
        }
        isEnd = false;
    }
};
class StreamChecker {
public:
    Trie* root;
    vector<char> lc;
    StreamChecker(vector<string>& words) {
        root = new Trie();
        for(string word:words){
            Trie* temp = root;
            reverse(word.begin(),word.end());
            for(char c:word){
                if(!temp->t[c-'a']){
                    temp->t[c-'a'] = new Trie();
                }
                temp = temp->t[c-'a'];
            }
            temp->isEnd=true;
        } 
        
    }
    
    bool query(char letter) {
        Trie* temp = root;
        lc.push_back(letter);
        int cnt = 0;
        for(int i=(int)lc.size()-1;i>=0;i--){
            char c= lc[i];
            if(!temp->t[c-'a']||temp->isEnd) break;
            else{
                cnt++;
                temp=temp->t[c-'a'];
            }
        }
        return cnt>=1&&temp->isEnd;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */