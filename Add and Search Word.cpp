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
class WordDictionary {
public:
    /** Initialize your data structure here. */
    Trie* root;
    WordDictionary() {
        root = new Trie();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Trie* temp = root;
        int n = word.size();
        for(int i=0;i<n;i++){
            char c = word[i];
            if(!temp->t[c-'a']){
                temp->t[c-'a'] = new Trie();
            }
            temp = temp->t[c-'a'];
        }
        temp->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        Trie* temp = root;
        bool res = searchHelper(temp,word,0,word.size());
        return res;
    }
    bool searchHelper(Trie* temp,string word,int i,int n){
        if(i==n){
            return temp->isEnd;
        }
        if(word[i]!='.'){
            if(!temp->t[word[i]-'a']) return false;
            return searchHelper(temp->t[word[i]-'a'],word,i+1,n);
        }
        else{
            for(int k=0;k<26;k++){
                if(temp->t[k]&&searchHelper(temp->t[k],word,i+1,n)) return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */