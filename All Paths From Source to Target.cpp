#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findPaths(vector<vector<int>> graph,vector<vector<int>>& paths,vector<int> &path,int cur){
        path.push_back(cur);
        if(cur == (int)graph.size()-1){
            paths.push_back(path);
        }
        else{
        for(auto v:graph[cur]){
            findPaths(graph,paths,path,v);
        }
        }
        path.pop_back();  
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
         vector<vector<int>> paths;
         vector<int> path;
        findPaths(graph,paths,path,0);
        return paths;
    }
};