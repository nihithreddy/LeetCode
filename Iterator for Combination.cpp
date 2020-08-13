#include<bits/stdc++.h>
using namespace std;
class CombinationIterator {
public:
    vector<string> combinations;
    int index,size,wordLength;
    CombinationIterator(string characters, int combinationLength) {
        index = 0;
        wordLength = (int)characters.size();
        findCombinations(characters,"",0,combinationLength,0,wordLength);
        size = combinations.size();
    }
    void findCombinations(string characters,string combination,int index,int length,int cur,int n){
        if(index==length){
             combinations.push_back(combination);
             return;
         }
         if(cur>=n){
             return;
         }
         findCombinations(characters,combination+characters[cur],index+1,length,cur+1,n);
         findCombinations(characters,combination,index,length,cur+1,n);
    }
    string next() {
        string nextWord = combinations.at(index);
        index = index+1;
        return nextWord;
    }
    
    bool hasNext() {
        return (index<size);
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */